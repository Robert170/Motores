
#include "xcMesh.h"

namespace xcEngineSDK {


  Mesh::Mesh(Vector<BoneVertex> Vertices,
             Vector<uint32> indices,
             Vector<Texture*> Textures,
             Vector<SamplerState*> Samplers,
             BONES_INFO* skeletal) {

    this->m_Vertices = Vertices;
    this->m_Indices = indices;
    this->m_vTextures = Textures;
    this->m_vSamplers = Samplers;
    m_pBonesInfo.reset(skeletal);
    m_bonesTransforms.clear();
    m_bonesTransforms.resize(skeletal->NumBones);
    

    setupMesh();
  }

  Mesh::Mesh(ModelData data) {
    this->m_Vertices = data.meshData;
    this->m_Indices = data.index;
    this->m_vTextures = data.modelTextures;
    this->m_vSamplers = data.samplers;
    m_pBonesInfo.reset(data.skeletal);
    m_bonesTransforms.clear();
    m_bonesTransforms.resize(data.skeletal->NumBones);
    m_scene = data.scene;
    setupMesh();
  }

  void 
  Mesh::render() {

    auto graphicsApi = g_graphicsAPI().instancePtr();

   graphicsApi->updateSubresource(&m_bonesTransforms,
                                   *graphicsApi->getConstBufferBones());

    uint32 textureSize = m_vTextures.size();

    //set shader resource
    for (uint32 i = 0; i < textureSize; ++i) {
      graphicsApi->setShaderResource(m_vTextures,
                                       1);
    }

    uint32 samplerSize = m_vSamplers.size();

    //set sampler state
    for (uint32 i = 0; i < samplerSize; ++i) {
      graphicsApi->setSamplerState(m_vSamplers,
                                   1);
    }

    graphicsApi->setVertexBuffer(m_vertexBuffer,
                                 0,
                                 1,
                                 sizeof(BoneVertex),
                                 0);

    graphicsApi->setIndexBuffer(m_indexBuffer,
                                0);


    // draw mesh
    graphicsApi->drawIndexed(m_Indices.size(),
                             0,
                             0,
                             nullptr);

  }

  void 
  Mesh::update(const float& deltaTime) {

    //boneTrasnform(deltaTime);

  }

  void 
  Mesh::setupMesh() {

    auto graphicsApi = g_graphicsAPI().instancePtr();

    m_vertexBuffer = graphicsApi->createVertexBuffer(m_Vertices,
                                                     1);
     
    m_indexBuffer = graphicsApi->createIndexBuffer(m_Indices,
                                                   1);
  }

  Matrix4x4 
  Mesh::boneTrasnform(float time) {

    auto& tempScene = reinterpret_cast<aiScene&>(m_scene);

    Matrix4x4 identity = Matrix4x4::IDENTITY_MATRIX;
    if (nullptr == tempScene.mAnimations) {
      return identity;
    }
    float TicksPerSecond = tempScene.mAnimations[0]->mTicksPerSecond != 0 ?
                           tempScene.mAnimations[0]->mTicksPerSecond : 25.0f;

    float TimeInTicks = time * TicksPerSecond;
    float AnimationTime = fmod(TimeInTicks, tempScene.mAnimations[0]->mDuration);

    nodeHeirarchy(AnimationTime, tempScene.mRootNode);

    m_bonesTransforms.resize(m_pBonesInfo->NumBones);

    for (uint32 i = 0; i < m_pBonesInfo->NumBones; ++i) {

      m_bonesTransforms[i] = m_pBonesInfo->VecSkeletal[i].Transformation;

    }

    return Matrix4x4();
  }

  void 
  Mesh::nodeHeirarchy(float time,
                      const void* node) {

    auto& tempScene = reinterpret_cast<aiScene&>(m_scene);

    auto& tempNode = reinterpret_cast<aiNode&>(node);

    String nodeName(tempNode.mName.data);

    const aiAnimation* animation = tempScene.mAnimations[0];

    Matrix4x4 NodeTransformation;

    std::memcpy(&NodeTransformation, &tempNode.mTransformation, sizeof(Matrix4x4));


    const aiNodeAnim* animNode = FindNodeAnimation(nodeName, animation);

    if (animNode) {
      //scale
      aiVector3D Scaling;
      calcInterpolatedScaling(&Scaling, time, animNode);
      Matrix4x4 ScalingM = Matrix4x4::IDENTITY_MATRIX;
      ScalingM.m_matrix[0].x = Scaling.x;
      ScalingM.m_matrix[1].y = Scaling.y;
      ScalingM.m_matrix[2].z = Scaling.z;


      //rotation
      aiQuaternion RotationQ;
      calcInterpolatedRotation(&RotationQ, time, animNode);
      Quaternion quaternionRotation(RotationQ.x, 
                                    RotationQ.y,
                                    RotationQ.z, 
                                    RotationQ.w);

      Matrix4x4 RotationM = RotationM.quatToMatRot(quaternionRotation);


      //translation
      aiVector3D Traslation;
      calcInterpolatedPosition(&Traslation, time, animNode);
      Matrix4x4 TraslationM = Matrix4x4::IDENTITY_MATRIX;
      TraslationM.m_matrix[3].x = Traslation.x;
      TraslationM.m_matrix[3].y = Traslation.y;
      TraslationM.m_matrix[3].z = Traslation.z;

      //make final transform
      NodeTransformation = TraslationM * RotationM * ScalingM;

      NodeTransformation.transpose();
    }

    Matrix4x4 globalInverseTransform = Matrix4x4::IDENTITY_MATRIX;

    Matrix4x4 globalTransform = NodeTransformation * Matrix4x4::IDENTITY_MATRIX;

    if (m_pBonesInfo->BonesMap.find(nodeName) != m_pBonesInfo->BonesMap.end()) {

      unsigned int BoneIndex = m_pBonesInfo->BonesMap[nodeName];

      m_pBonesInfo->VecSkeletal[BoneIndex].
                               Transformation = 
                               globalInverseTransform * 
                               globalTransform *
                               m_pBonesInfo->VecSkeletal[BoneIndex].Offset;
    }

    for (uint32 i = 0; i < tempNode.mNumChildren; ++i) {
      nodeHeirarchy(time, tempNode.mChildren[i]);
    }

  }

  const aiNodeAnim*
  Mesh::FindNodeAnimation(const String NameNod,
                          const void* Anim) {

    auto& tempAnim = reinterpret_cast<aiAnimation&>(Anim);
    
    for (uint32 i = 0; i < tempAnim.mNumChannels; ++i) {

      const aiNodeAnim* Temp = tempAnim.mChannels[i];
      if (String(Temp->mNodeName.data) == NameNod) {

        return Temp;
      }
    }

    return nullptr;
  }

  int32 
  Mesh::findPosition(float AnimationTime, const void* pNodeAnim) {

    auto& tempNodeAnim = reinterpret_cast<aiNodeAnim&>(pNodeAnim);

    for (uint32 i = 0; i < tempNodeAnim.mNumPositionKeys - 1; ++i) {
      if (AnimationTime < (float)tempNodeAnim.mPositionKeys[i + 1].mTime)  {
        return i;
      }

    }
    assert(0);
    return 0;
  }

  int32 
  Mesh::findRotation(float AnimationTime, const void* pNodeAnim) {

    auto& tempNodeAnim = reinterpret_cast<aiNodeAnim&>(pNodeAnim);

    assert(tempNodeAnim.mNumRotationKeys > 0);

    for (uint32 i = 0; i < tempNodeAnim.mNumRotationKeys - 1; ++i) {
      if (AnimationTime < (float)tempNodeAnim.mRotationKeys[i + 1].mTime) {
        return i;
      }
    }
    assert(0);
    return 0;
  }

  int32 
  Mesh::findScaling(float AnimationTime, const void* pNodeAnim) {

    auto& tempNodeAnim = reinterpret_cast<aiNodeAnim&>(pNodeAnim);

    assert(tempNodeAnim.mNumScalingKeys > 0);

    for (uint32 i = 0; i < tempNodeAnim.mNumScalingKeys - 1; ++i) {
      if (AnimationTime < (float)tempNodeAnim.mScalingKeys[i + 1].mTime) {
        return i;
      }
    }
    assert(0);
    return 0;
  }

  void 
  Mesh::calcInterpolatedPosition(const void* Out, 
                                 float AnimationTime, 
                                 const void* pNodeAnim) {

    auto& tempNodeAnim = reinterpret_cast<aiNodeAnim&>(pNodeAnim);
    auto& tempout = reinterpret_cast<aiVector3D&>(Out);
    

    if (tempNodeAnim.mNumPositionKeys == 1) {
      tempout = tempNodeAnim.mPositionKeys[0].mValue;
      return;
    }

    unsigned int PositionIndex = findPosition(AnimationTime, pNodeAnim);

    unsigned int NextPositionIndex = (PositionIndex + 1);

    assert(NextPositionIndex < tempNodeAnim.mNumPositionKeys);

    float DeltaTime = (float)(tempNodeAnim.mPositionKeys[NextPositionIndex].mTime 
                              - tempNodeAnim.mPositionKeys[PositionIndex].mTime);
    float Factor = (AnimationTime - 
                   (float)tempNodeAnim.mPositionKeys[PositionIndex].mTime) 
                   / DeltaTime;

    assert(Factor >= 0.0f && Factor <= 1.0f);

    const aiVector3D& Start = tempNodeAnim.mPositionKeys[PositionIndex].mValue;
    const aiVector3D& End = tempNodeAnim.mPositionKeys[NextPositionIndex].mValue;
    aiVector3D Delta = End - Start;
    tempout = Start + Factor * Delta;

  }

  void
  Mesh::calcInterpolatedRotation(const void* Out, 
                                 float AnimationTime, 
                                 const void* pNodeAnim) {

    auto& tempNodeAnim = reinterpret_cast<aiNodeAnim&>(pNodeAnim);
    auto& tempout = reinterpret_cast<aiQuaternion&>(Out);

    if (tempNodeAnim.mNumRotationKeys == 1) {
      tempout = tempNodeAnim.mRotationKeys[0].mValue;
      return;
    }

    unsigned int RotationIndex = findRotation(AnimationTime, pNodeAnim);
    unsigned int NextRotationIndex = (RotationIndex + 1);
    assert(NextRotationIndex < tempNodeAnim.mNumRotationKeys);
    float DeltaTime = (float)(tempNodeAnim.mRotationKeys[NextRotationIndex].mTime 
                              - tempNodeAnim.mRotationKeys[RotationIndex].mTime);
    float Factor = (AnimationTime - 
                   (float)tempNodeAnim.mRotationKeys[RotationIndex].mTime) 
                   / DeltaTime;

    assert(Factor >= 0.0f && Factor <= 1.0f);

    const aiQuaternion& StartRotationQ = 
                        tempNodeAnim.mRotationKeys[RotationIndex].mValue;

    const aiQuaternion& EndRotationQ = 
                        tempNodeAnim.mRotationKeys[NextRotationIndex].mValue;

    aiQuaternion::Interpolate(tempout, StartRotationQ, EndRotationQ, Factor);

    tempout = tempout.Normalize();
  }

  void 
  Mesh::calcInterpolatedScaling(const void* Out, 
                                float AnimationTime, 
                                const void* pNodeAnim) {

    auto& tempNodeAnim = reinterpret_cast<aiNodeAnim&>(pNodeAnim);
    auto& tempout = reinterpret_cast<aiVector3D&>(Out);

    if (tempNodeAnim.mNumScalingKeys == 1) {
      tempout = tempNodeAnim.mScalingKeys[0].mValue;
      return;
    }

    unsigned int ScalingIndex = findScaling(AnimationTime, pNodeAnim);

    unsigned int NextScalingIndex = (ScalingIndex + 1);

    assert(NextScalingIndex < tempNodeAnim.mNumScalingKeys);

    float DeltaTime = (float)(tempNodeAnim.mScalingKeys[NextScalingIndex].mTime 
                             - tempNodeAnim.mScalingKeys[ScalingIndex].mTime);

    float Factor = (AnimationTime - 
                   (float)tempNodeAnim.mScalingKeys[ScalingIndex].mTime) 
                   / DeltaTime;

    assert(Factor >= 0.0f && Factor <= 1.0f);

    const aiVector3D& Start = tempNodeAnim.mScalingKeys[ScalingIndex].mValue;

    const aiVector3D& End = tempNodeAnim.mScalingKeys[NextScalingIndex].mValue;

    aiVector3D Delta = End - Start;

    tempout = Start + Factor * Delta;

  }


}