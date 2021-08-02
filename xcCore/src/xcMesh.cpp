#include "xcMesh.h"

namespace xcEngineSDK {


  Mesh::Mesh(Vector<BoneVertex> Vertices,
             Vector<uint32> indices,
             Vector<Texture*> Textures,
             Vector<SamplerState*> Samplers,
             BONES_INFO2* skeletal,
             const aiScene* scene) {

    this->m_Vertices = Vertices;
    this->m_Indices = indices;
    this->m_vTextures = Textures;
    this->m_vSamplers = Samplers;
    m_pBonesInfo.reset(skeletal);
    m_bonesTransforms.clear();
    m_bonesTransforms.resize(skeletal->NumBones);
    m_scene = scene; 

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

    Matrix4x4 identity = Matrix4x4::IDENTITY_MATRIX;
    if (nullptr == m_scene->mAnimations) {
      return identity;
    }
    float TicksPerSecond = m_scene->mAnimations[0]->mTicksPerSecond != 0 ?
                           m_scene->mAnimations[0]->mTicksPerSecond : 25.0f;

    float TimeInTicks = time * TicksPerSecond;
    float AnimationTime = fmod(TimeInTicks, m_scene->mAnimations[0]->mDuration);

    nodeHeirarchy(AnimationTime, m_scene->mRootNode);

    m_bonesTransforms.resize(m_pBonesInfo->NumBones);

    for (uint32 i = 0; i < m_pBonesInfo->NumBones; ++i) {

      m_bonesTransforms[i] = m_pBonesInfo->VecSkeletal[i].Transformation;

    }

    return Matrix4x4();
  }

  void 
  Mesh::nodeHeirarchy(float time,
                      const aiNode* node) {

    String nodeName(node->mName.data);

    const aiAnimation* animation = m_scene->mAnimations[0];

    Matrix4x4 NodeTransformation;

    std::memcpy(&NodeTransformation, &node->mTransformation, sizeof(Matrix4x4));


    const aiNodeAnim* animNode = FindNodeAnimation(nodeName, animation);

    if (animNode) {
      //scale
      aiVector3D Scaling;
      calcInterpolatedScaling(Scaling, time, animNode);
      Matrix4x4 ScalingM = Matrix4x4::IDENTITY_MATRIX;
      ScalingM.m_matrix[0].x = Scaling.x;
      ScalingM.m_matrix[1].y = Scaling.y;
      ScalingM.m_matrix[2].z = Scaling.z;


      //rotation
      aiQuaternion RotationQ;
      calcInterpolatedRotation(RotationQ, time, animNode);
      Quaternion quaternionRotation(RotationQ.x, 
                                    RotationQ.y,
                                    RotationQ.z, 
                                    RotationQ.w);

      Matrix4x4 RotationM = RotationM.quatToMatRot(quaternionRotation);


      //translation
      aiVector3D Traslation;
      calcInterpolatedPosition(Traslation, time, animNode);
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

    for (uint32 i = 0; i < node->mNumChildren; ++i) {
      nodeHeirarchy(time, node->mChildren[i]);
    }

  }

  const aiNodeAnim* 
  Mesh::FindNodeAnimation(const String NameNod,
                          const aiAnimation* Anim) {

    for (uint32 i = 0; i < Anim->mNumChannels; ++i) {

      const aiNodeAnim* Temp = Anim->mChannels[i];
      if (String(Temp->mNodeName.data) == NameNod) {

        return Temp;
      }
    }

    return nullptr;
  }

  int32 
  Mesh::findPosition(float AnimationTime, const aiNodeAnim* pNodeAnim) {

    for (uint32 i = 0; i < pNodeAnim->mNumPositionKeys - 1; ++i) {
      if (AnimationTime < (float)pNodeAnim->mPositionKeys[i + 1].mTime)  {
        return i;
      }

    }
    assert(0);
    return 0;
  }

  int32 
  Mesh::findRotation(float AnimationTime, const aiNodeAnim* pNodeAnim) {
    assert(pNodeAnim->mNumRotationKeys > 0);

    for (uint32 i = 0; i < pNodeAnim->mNumRotationKeys - 1; ++i) {
      if (AnimationTime < (float)pNodeAnim->mRotationKeys[i + 1].mTime) {
        return i;
      }
    }
    assert(0);
    return 0;
  }

  int32 
  Mesh::findScaling(float AnimationTime, const aiNodeAnim* pNodeAnim) {
    assert(pNodeAnim->mNumScalingKeys > 0);

    for (uint32 i = 0; i < pNodeAnim->mNumScalingKeys - 1; ++i) {
      if (AnimationTime < (float)pNodeAnim->mScalingKeys[i + 1].mTime) {
        return i;
      }
    }
    assert(0);
    return 0;
  }

  void 
  Mesh::calcInterpolatedPosition(aiVector3D& Out, 
                                 float AnimationTime, 
                                 const aiNodeAnim* pNodeAnim) {

    if (pNodeAnim->mNumPositionKeys == 1) {
      Out = pNodeAnim->mPositionKeys[0].mValue;
      return;
    }

    unsigned int PositionIndex = findPosition(AnimationTime, pNodeAnim);

    unsigned int NextPositionIndex = (PositionIndex + 1);

    assert(NextPositionIndex < pNodeAnim->mNumPositionKeys);

    float DeltaTime = (float)(pNodeAnim->mPositionKeys[NextPositionIndex].mTime 
                              - pNodeAnim->mPositionKeys[PositionIndex].mTime);
    float Factor = (AnimationTime - 
                   (float)pNodeAnim->mPositionKeys[PositionIndex].mTime) 
                   / DeltaTime;

    assert(Factor >= 0.0f && Factor <= 1.0f);

    const aiVector3D& Start = pNodeAnim->mPositionKeys[PositionIndex].mValue;
    const aiVector3D& End = pNodeAnim->mPositionKeys[NextPositionIndex].mValue;
    aiVector3D Delta = End - Start;
    Out = Start + Factor * Delta;

  }

  void
  Mesh::calcInterpolatedRotation(aiQuaternion& Out, 
                                 float AnimationTime, 
                                 const aiNodeAnim* pNodeAnim) {

    if (pNodeAnim->mNumRotationKeys == 1) {
      Out = pNodeAnim->mRotationKeys[0].mValue;
      return;
    }

    unsigned int RotationIndex = findRotation(AnimationTime, pNodeAnim);
    unsigned int NextRotationIndex = (RotationIndex + 1);
    assert(NextRotationIndex < pNodeAnim->mNumRotationKeys);
    float DeltaTime = (float)(pNodeAnim->mRotationKeys[NextRotationIndex].mTime 
                              - pNodeAnim->mRotationKeys[RotationIndex].mTime);
    float Factor = (AnimationTime - 
                   (float)pNodeAnim->mRotationKeys[RotationIndex].mTime) 
                   / DeltaTime;

    assert(Factor >= 0.0f && Factor <= 1.0f);

    const aiQuaternion& StartRotationQ = 
                        pNodeAnim->mRotationKeys[RotationIndex].mValue;

    const aiQuaternion& EndRotationQ = 
                        pNodeAnim->mRotationKeys[NextRotationIndex].mValue;

    aiQuaternion::Interpolate(Out, StartRotationQ, EndRotationQ, Factor);

    Out = Out.Normalize();
  }

  void 
  Mesh::calcInterpolatedScaling(aiVector3D& Out, 
                                float AnimationTime, 
                                const aiNodeAnim* pNodeAnim) {

    if (pNodeAnim->mNumScalingKeys == 1) {
      Out = pNodeAnim->mScalingKeys[0].mValue;
      return;
    }

    unsigned int ScalingIndex = findScaling(AnimationTime, pNodeAnim);

    unsigned int NextScalingIndex = (ScalingIndex + 1);

    assert(NextScalingIndex < pNodeAnim->mNumScalingKeys);

    float DeltaTime = (float)(pNodeAnim->mScalingKeys[NextScalingIndex].mTime 
                             - pNodeAnim->mScalingKeys[ScalingIndex].mTime);

    float Factor = (AnimationTime - 
                   (float)pNodeAnim->mScalingKeys[ScalingIndex].mTime) 
                   / DeltaTime;

    assert(Factor >= 0.0f && Factor <= 1.0f);

    const aiVector3D& Start = pNodeAnim->mScalingKeys[ScalingIndex].mValue;

    const aiVector3D& End = pNodeAnim->mScalingKeys[NextScalingIndex].mValue;

    aiVector3D Delta = End - Start;

    Out = Start + Factor * Delta;

  }


}