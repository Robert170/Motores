#pragma once
#include <xcPrerequisitesCore.h>
#include <xcBaseApp.h>
#include <xcModel.h>


//struct CBNeverChanges
//{
//  Matrix4x4 mView;
//  Matrix4x4 mProjection;
//  Matrix4x4 mWorld;
//  Vector4 vMeshColor;
//};

struct CBBones
{
  Matrix4x4 Bones_CB[200];
};


class GameAppUnitTest : public BaseApp
{
 public:
  GameAppUnitTest() = default;
	~GameAppUnitTest() = default;

 public:

  /**
	 * @brief public functions
	 */
  void
	onCreate() override;

  void
  onEvents(sf::Event event) override;

	void
  onUpdate(float deltaTime) override;
  
	void
  onRender() override;

	void
  onDestroy() override;

 public:

	/**
	* @brief public variables
	*/

	//Texture
	Texture* m_renderTarget = nullptr;
	Texture* m_depthStencil = nullptr;
	Texture* m_shaderResource = nullptr;

	//Vector<Texture*> m_renderTargets;
	//Vector<Texture*> m_shaderResources;
	//Vector<SamplerState*> m_samplers;
	Vector<ConstantBuffer*> m_constantBuffers;
	Vector<String> m_semanticNames;
  Vector<String> m_vSemanticNames;
  Vector<uint32> m_vFormats;
  Vector<Matrix4x4> m_transform;

  ////Shader
  //SPtr<ShaderProgram> m_shaderProgram = nullptr;

  //SPtr<InputLayout> m_inputLayout = nullptr;

  //Buffers
  //VertexBuffer* m_pVertexBuffer = nullptr;
  //IndexBuffer* m_pIndexBuffer = nullptr;
  SPtr<ConstantBuffer> m_cbNeverChanges = nullptr;
  SPtr<ConstantBuffer> m_cbBonesAnimation = nullptr;

  //Sampler
  SamplerState* m_samplerState = nullptr;

  ////depth stencil state
  //SPtr<DepthStencilState> m_depthStencilState = nullptr;
  //SPtr<DepthStencilState> m_depthStencilStateSAQ = nullptr;

  ////Rasterizer
  //SPtr<RasterizerState> m_rasterizerGbuffer = nullptr;
  //SPtr<RasterizerState> m_rasterizerSAQ = nullptr;

  //World matrix
  Matrix4x4 m_world;
  Matrix4x4 m_view;
  Matrix4x4 m_projection;

  Vector4 m_meshColor;

  //ColorStruct m_color;

  InputLayout_Desc m_inpLayDesc;

  SPtr<Model> m_model;

  //CBNeverChanges m_constantBuffer;

  CBBones m_bonesBuffer;

};

