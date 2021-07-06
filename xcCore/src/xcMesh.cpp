#include "xcMesh.h"

namespace xcEngineSDK {
  Mesh::Mesh(Vector<BoneVertex> Vertices,
             Vector<uint32> indices,
             Vector<Texture*> Textures,
             Vector<SamplerState*> Samplers,
             BONES_INFO* Skull,
             BoneVertex* BonVer,
             uint32 NumBones,
             const aiScene* scene) {

    this->m_Vertices = Vertices;
    this->m_Indices = indices;
    this->m_vTextures = Textures;
    this->m_vSamplers = Samplers;
    m_pBonesInfo.reset(Skull);
    m_pBoneVertex.reset(BonVer);
    m_bonesTransforms.clear();
    m_bonesTransforms.resize(NumBones);
    m_scene = scene; 

    setupMesh();
  }

  void 
  Mesh::draw(ShaderProgram& shader,
             Vector<SamplerState*> Samplers) {

    XC_UNREFERENCED_PARAMETER(shader);

    //set shader resource
    for (int i = 0; i < m_vTextures.size(); i++)
    {
      g_graphicsAPI().setShaderResource(m_vTextures,
                                        1);
    }

    //set sampler state
    for (int i = 0; i < Samplers.size(); i++)
    {
      g_graphicsAPI().setSamplerState(Samplers,
                                    1);
    }

    g_graphicsAPI().setVertexBuffer(m_vertexBuffer,
                                  0,
                                  1,
                                  sizeof(BoneVertex),
                                  0);

    g_graphicsAPI().setIndexBuffer(m_indexBuffer,
                                   0);

    // draw mesh
    g_graphicsAPI().drawIndexed(m_Indices.size(),
                               0,
                               0,
                               nullptr);

  }

  void 
  Mesh::setupMesh() {
    m_vertexBuffer = g_graphicsAPI().createVertexBuffer(m_Vertices,
                                                       1);
    
    m_indexBuffer = g_graphicsAPI().createIndexBuffer(m_Indices,
                                                      1);
  }

  Matrix4x4 
  Mesh::boneTrasnform(float time, 
                      Vector<Matrix4x4>& transform) {

    Matrix4x4 identity = Matrix4x4::IDENTITY_MATRIX;
    if (nullptr == m_scene->mAnimations) {
      return identity;
    }
    float TicksPerSecond = m_scene->mAnimations[0]->mTicksPerSecond != 0 ?
                           m_scene->mAnimations[0]->mTicksPerSecond : 25.0f;

    float TimeInTicks = time * TicksPerSecond;
    float AnimationTime = fmod(TimeInTicks, m_scene->mAnimations[0]->mDuration);

    nodeHeirarchy(AnimationTime, m_scene->mRootNode, identity);

    transform.resize(m_pBonesInfo->NumBones);

    for (int i = 0; i < m_pBonesInfo->NumBones; ++i) {

      transform[i] = m_pBonesInfo->VecSkeletal[i].Transformation;

    }

    return Matrix4x4();
  }

  void 
  Mesh::nodeHeirarchy(float time,
                      const aiNode* node, 
                      const Matrix4x4& transform) {

    String nodeName(node->mName.data);

    const aiAnimation* animation = m_scene->mAnimations[0];

    Matrix4x4 NodeTransformation(node->mTransformation.a1, node->mTransformation.b1, 
                                 node->mTransformation.c1, node->mTransformation.d1, 
                                 node->mTransformation.a2, node->mTransformation.b2, 
                                 node->mTransformation.c2, node->mTransformation.d2, 
                                 node->mTransformation.a3, node->mTransformation.b3, 
                                 node->mTransformation.c3, node->mTransformation.d3, 
                                 node->mTransformation.a4, node->mTransformation.b4, 
                                 node->mTransformation.c4, node->mTransformation.d4);

    Matrix4x4 globalInverseTransform(m_scene->mRootNode->mTransformation.a1, 
                                     m_scene->mRootNode->mTransformation.b1, 
                                     m_scene->mRootNode->mTransformation.c1, 
                                     m_scene->mRootNode->mTransformation.d1, 
                                     m_scene->mRootNode->mTransformation.a2, 
                                     m_scene->mRootNode->mTransformation.b2, 
                                     m_scene->mRootNode->mTransformation.c2, 
                                     m_scene->mRootNode->mTransformation.d2, 
                                     m_scene->mRootNode->mTransformation.a3, 
                                     m_scene->mRootNode->mTransformation.b3, 
                                     m_scene->mRootNode->mTransformation.c3, 
                                     m_scene->mRootNode->mTransformation.d3, 
                                     m_scene->mRootNode->mTransformation.a4, 
                                     m_scene->mRootNode->mTransformation.b4, 
                                     m_scene->mRootNode->mTransformation.c4, 
                                     m_scene->mRootNode->mTransformation.d4);

    globalInverseTransform.inverse();

   // glm::mat4 glmTransform = glm::transpose(glm::make_mat4(&Node->mTransformation.a1));

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
      Quaternion quaternionRotation(RotationQ.x, RotationQ.y, 
                                    RotationQ.z, RotationQ.w);
    
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

    Matrix4x4 temp = transform;

    Matrix4x4 globalTransform = temp * NodeTransformation;

    if (m_pBonesInfo->BonesMap.find(nodeName) != m_pBonesInfo->BonesMap.end()) {

      unsigned int BoneIndex = m_pBonesInfo->BonesMap[nodeName];

      m_pBonesInfo->VecSkeletal[BoneIndex].
                               Transformation = 
                               globalInverseTransform * 
                               globalTransform *
                               m_pBonesInfo->VecSkeletal[BoneIndex].Offset;
    }

    for (int i = 0; i < node->mNumChildren; i++) {
      nodeHeirarchy(time, node->mChildren[i], globalTransform);
    }

  }

  const aiNodeAnim* 
  Mesh::FindNodeAnimation(const String NameNod,
                          const aiAnimation* Anim) {

    for (int i = 0; i < Anim->mNumChannels; i++) {

      const aiNodeAnim* Temp = Anim->mChannels[i];
      if (String(Temp->mNodeName.data) == NameNod) {

        return Temp;
      }
    }

    return nullptr;
  }

  int32 
  Mesh::findPosition(float AnimationTime, const aiNodeAnim* pNodeAnim) {

    for (int i = 0; i < pNodeAnim->mNumPositionKeys - 1; i++) {
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

    for (int i = 0; i < pNodeAnim->mNumRotationKeys - 1; i++) {
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

    for (int i = 0; i < pNodeAnim->mNumScalingKeys - 1; i++) {
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