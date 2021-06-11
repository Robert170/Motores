#pragma once
#include <xcPrerequisitesCore.h>
#include <xcBaseApp.h>
#include <xcModel.h>

namespace xcEngineSDK {

  struct CBNeverChanges
  {
    Matrix4x4 mView;
    Matrix4x4 mProjection;
    Matrix4x4 mWorld;
    Vector4 vMeshColor;
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

		//TextureBs
		TextureB* m_renderTarget = nullptr;
		TextureB* m_depthStencil = nullptr;
		TextureB* m_shaderResource = nullptr;

		//std::vector<TextureB*> m_renderTargets;
		//std::vector<TextureB*> m_shaderResources;
		//std::vector<SamplerState*> m_samplers;
		Vector<ConstantBuffer*> m_constantBuffers;
		Vector<String> m_semanticNames;
    Vector<String> m_vSemanticNames;
    Vector<uint32> m_vFormats;

    //Shader
    VertexShader* m_vertexShader = nullptr;
    PixelShader* m_pixelShader = nullptr;
    ShaderProgram* m_shaderProgram = nullptr;

    InputLayout* m_inputLayout = nullptr;

    //Buffers
    //VertexBuffer* m_pVertexBuffer = nullptr;
    //IndexBuffer* m_pIndexBuffer = nullptr;
    ConstantBuffer* m_cbNeverChanges = nullptr;

    //Sampler
    SamplerState* m_samplerState = nullptr;

    //World matrix
    Matrix4x4 m_world;
    Matrix4x4 m_view;
    Matrix4x4 m_projection;

    Vector4 m_meshColor;

    ColorStruct m_color;

    InputLayout_Desc m_inpLayDesc;

    Model* m_model;

    CBNeverChanges m_constantBuffer;

    Camera m_camera;

	};

}