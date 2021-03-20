#include "xcOGLGraphiAPI.h"
#include "xcPixelShaderOGL.h"
#include "xcVertexShaderOGL.h"
#include "xcTextureOGL.h"
#include "xcIndexBufferOGL.h"
#include "xcVertexBufferOGL.h"
#include "xcConstantBufferOGL.h"
#include "xcInputLayoutOGL.h"
#include "xcSamplerStateOGL.h"
#include "xcShaderProgramOGL.h"
#include "xcModel.h"

namespace xcEngineSDK {
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	void 
	OGLGraphiAPI::initWindow(uint32 width,
		                       uint32 height) {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_window = glfwCreateWindow(width, height, "LearnOpenGL", nullptr, nullptr);
		if (nullptr == m_window) {
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(m_window);
		//glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize GLAD" << std::endl;
			return;
		}

		// configure global opengl state
		// -----------------------------
		glEnable(GL_DEPTH_TEST);
		////default render target
		//glGenFramebuffers(1, &m_BackBuffer);
		//glBindFramebuffer(GL_FRAMEBUFFER, m_BackBuffer);

		////default depth
		//glGenRenderbuffers(1, &m_Depth);
		//glBindRenderbuffer(GL_RENDERBUFFER, m_Depth);
		//glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
		//glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_Depth);

	}


	void 
	OGLGraphiAPI::createDeviceandSwap() {
	}

	void 
	OGLGraphiAPI::createDeferredContext() {
	}

	OGLGraphiAPI::OGLGraphiAPI() {
	}

	OGLGraphiAPI::~OGLGraphiAPI() {
	}

	Matrix4x4 
	OGLGraphiAPI::initMatrixWorld(Matrix4x4& MatrixWorld) {
		//TODO: IDENTYDI MATRIX
		//return MatrixWorld = Matrix4x4(1.0);
		return MatrixWorld;
	}

	Matrix4x4 
	OGLGraphiAPI::initMatrixView(Matrix4x4& MatrixView,
		                           Vector3& Eye,
		                           Vector3& At,
		                           Vector3& Up) {
		//TODO
		////init view matrix
    /*MatrixView = glm::lookAtLH(Eye,
      At,
      Up);*/

		return MatrixView;
	}

	Matrix4x4 
	OGLGraphiAPI::initMatrixProjection(Matrix4x4& MatrixProjection,
		                                 float& Fov,
		                                 float& Height,
		                                 float& Width,
		                                 float& Near,
		                                 float& Far) {
    /*MatrixProjection = glm::perspectiveFovLH(Fov,
      Height,
      Width,
      Near,
      Far);*/
		return MatrixProjection;
	}

	//CModel* OGLGraphiAPI::LoadModel(CGraphiAPI* API, 
	//	                             InputLayout_Desc InpLayDesc, 
	//	                             std::string Path)
	//{
	//	
	//	ModelOgl->Init(Path, 
	//		           API,
	//		           InpLayDesc);
	//	return ModelOgl;
	//}


	VertexBuffer* 
	OGLGraphiAPI::createVertexBuffer(const std::vector <SimpleVertex>& Ver,
		                               uint32 BufferSize,
		                               uint32 NumBuffers) {

		auto VertexBuffer = new VertexBufferOGL();

		glGenBuffers(NumBuffers,
			           &VertexBuffer->m_vBO);

		glBindBuffer(GL_ARRAY_BUFFER,
			           VertexBuffer->m_vBO);

		glBufferData(GL_ARRAY_BUFFER,
			           Ver.size() * sizeof(SimpleVertex),
			           Ver.data(),
			           GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);

		/*glBindBuffer(GL_ARRAY_BUFFER,
							 0);*/


		return VertexBuffer;
	}

	IndexBuffer* 
	OGLGraphiAPI::createIndexBuffer(const std::vector<uint32>& Ind,
		                              uint32 BufferSize, //no va
		                              uint32 NumBuffer) {

		auto IndexBuffer = new IndexBufferOGL();


		glGenBuffers(NumBuffer,
			          &IndexBuffer->m_IBO);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,
			           IndexBuffer->m_IBO);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			           Ind.size() * sizeof(uint32),
			           Ind.data(),
			           GL_STATIC_DRAW);

		return IndexBuffer;
	}

	ConstantBuffer* 
	OGLGraphiAPI::createConstantBuffer(uint32 BufferSize,//2
		                                 uint32 NumBuffer, //1
		                                 const void* Data) {//3
		                                 auto ConstantBuffer = new ConstantBufferOGL();

		glGenBuffers(NumBuffer,
			           &ConstantBuffer->m_CBO);

		glBindBuffer(GL_UNIFORM_BUFFER,
			           ConstantBuffer->m_CBO);

		glBufferData(GL_UNIFORM_BUFFER,
			           BufferSize,
			           &Data,
			           GL_DYNAMIC_DRAW);

		glBindBuffer(GL_UNIFORM_BUFFER,
			           0);


		return ConstantBuffer;
	}


	void 
	OGLGraphiAPI::createTexture1D() {
	}

	Texture* 
	OGLGraphiAPI::createTexture2D(uint32 width,
		                            uint32 height,
		                            uint32 numberTexture,
		                            TEXTURE_FORMAT format,
		                            uint32 bindFlags,
		                            TYPE_USAGE Usage) {

		auto texture = new TextureOGL();


		//Checar que interfaces se van a crear
		//se puede omitir
		if (bindFlags & TEXTURE_BIND_SHADER_RESOURCE) {//Crear SRV
			//flata arreglar
			glTextureView(0, 0, 0, 0, 0, 0, 0, 0);
		}
		if (bindFlags & TEXTURE_BIND_DEPTH_STENCIL) {//Crear DSV

			glGenRenderbuffers(numberTexture,
				                 &texture->m_dSV);

			glRenderbufferStorage(GL_RENDERBUFFER,
				                    GL_DEPTH_COMPONENT,
				                    width,
				                    height);
		}
		if (bindFlags & TEXTURE_BIND_RENDER_TARGET) {//Crear RTV

			glGenFramebuffers(numberTexture,
				                &texture->m_rTV);
		}
		if (bindFlags & TEXTURE_BIND_UNORDERED_ACCESS) {//Crear UAV


		}

		glGenTextures(numberTexture,
			            &texture->m_texture);

		glBindTexture(GL_TEXTURE_2D,
			            texture->m_texture);

		glTexImage2D(GL_TEXTURE_2D,
			           0,
			           GL_RGB,
			           width,
			           height,
			           0,
			           GL_RGB,
			           GL_UNSIGNED_BYTE,
			           0);

		glTexParameteri(GL_TEXTURE_2D,
			              GL_TEXTURE_MAG_FILTER,
			              GL_NEAREST);

		glTexParameteri(GL_TEXTURE_2D,
			              GL_TEXTURE_MIN_FILTER,
			              GL_NEAREST);

		return texture;
	}


	void OGLGraphiAPI::CreateTexture3D()
	{
	}

	CShaderProgram* OGLGraphiAPI::CreateShaderProgram(const std::string& FileNameVS,
		const std::string& FileNamePS,
		const std::string& EntryVS,
		const std::string& EntryPS,
		const std::string& ShaderModelVS,
		const std::string& ShaderModelPS,
		int NumVertexShader,
		int NumPixelShader)
	{

		auto ShaderProgram = new CShaderProgramOGL();

		ShaderProgram->m_AttachShaderID = glCreateProgram();


		// vertex Shader
		std::string RealName = FileNameVS + "_OGL.txt";

		ShaderProgram->m_VertexShaderProgram = new CVertexShaderOGL();

		std::string Temp = ShaderProgram->m_VertexShaderProgram->ReadFile(RealName);

		const char* VertexCode = Temp.c_str();

		ShaderProgram->m_VertexShaderProgram->m_VertexShader = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(ShaderProgram->m_VertexShaderProgram->m_VertexShader,
			NumVertexShader,
			&VertexCode,
			nullptr);

		glCompileShader(ShaderProgram->m_VertexShaderProgram->m_VertexShader);

		GLint isCompiled = 0;

		glGetShaderiv(ShaderProgram->m_VertexShaderProgram->m_VertexShader,
			GL_COMPILE_STATUS,
			&isCompiled);

		if (isCompiled == GL_FALSE) {

			GLint maxLength = 0;
			glGetShaderiv(ShaderProgram->m_VertexShaderProgram->m_VertexShader,
				GL_INFO_LOG_LENGTH,
				&maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(ShaderProgram->m_VertexShaderProgram->m_VertexShader,
				maxLength,
				&maxLength,
				&infoLog[0]);

			// We don't need the shader anymore.
			glDeleteShader(ShaderProgram->m_VertexShaderProgram->m_VertexShader);
			delete ShaderProgram;

			return nullptr;
		}


		//pixel shader
		RealName = FileNamePS + "_OGL.txt";

		ShaderProgram->m_PixelShaderProgram = new CPixelShaderOGL();

		Temp = ShaderProgram->m_PixelShaderProgram->ReadFile(RealName);

		const char* PixelCode = Temp.c_str();

		ShaderProgram->m_PixelShaderProgram->m_PixelShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(ShaderProgram->m_PixelShaderProgram->m_PixelShader,
			NumPixelShader,
			&PixelCode,
			nullptr);

		glCompileShader(ShaderProgram->m_PixelShaderProgram->m_PixelShader);

		glGetShaderiv(ShaderProgram->m_PixelShaderProgram->m_PixelShader, GL_COMPILE_STATUS, &isCompiled);

		if (isCompiled == GL_FALSE) {

			GLint maxLength = 0;
			glGetShaderiv(ShaderProgram->m_PixelShaderProgram->m_PixelShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(ShaderProgram->m_PixelShaderProgram->m_PixelShader, maxLength, &maxLength, &infoLog[0]);

			// We don't need the shader anymore.
			glDeleteShader(ShaderProgram->m_PixelShaderProgram->m_PixelShader);
			delete ShaderProgram;

			return nullptr;
		}


		//set del shader
		glAttachShader(ShaderProgram->m_AttachShaderID,
			ShaderProgram->m_VertexShaderProgram->m_VertexShader);
		glAttachShader(ShaderProgram->m_AttachShaderID,
			ShaderProgram->m_PixelShaderProgram->m_PixelShader);
		glLinkProgram(ShaderProgram->m_AttachShaderID);


		return ShaderProgram;
	}

	CPixelShader* OGLGraphiAPI::CreatePixelShaders(const std::string& FileName,
		const std::string& Entry,
		const std::string& ShaderModel,
		int NumPixelShader)
	{
		// Pixel Shader
		std::string RealName = FileName + "_OGL.txt";

		auto PixelShader = new CPixelShaderOGL();

		std::string Temp = PixelShader->ReadFile(RealName);

		const char* PixelCode = Temp.c_str();

		PixelShader->m_PixelShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(PixelShader->m_PixelShader,
			NumPixelShader,
			&PixelCode,
			nullptr);

		glCompileShader(PixelShader->m_PixelShader);

		GLint isCompiled = 0;

		glGetShaderiv(PixelShader->m_PixelShader, GL_COMPILE_STATUS, &isCompiled);

		if (isCompiled == GL_FALSE) {

			GLint maxLength = 0;
			glGetShaderiv(PixelShader->m_PixelShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(PixelShader->m_PixelShader, maxLength, &maxLength, &infoLog[0]);

			// We don't need the shader anymore.
			glDeleteShader(PixelShader->m_PixelShader);
			delete PixelShader;

			return nullptr;
		}



		//set del shader
		glAttachShader(m_AttachShaderID,
			PixelShader->m_PixelShader);

		glLinkProgram(m_AttachShaderID);

		return PixelShader;

	}

	CVertexShader* OGLGraphiAPI::createVertexShaders(const std::string& FileName,
		const std::string& Entry,
		const std::string& ShaderModel,
		int NumVertexShader)
	{
		// vertex Shader
		std::string RealName = FileName + "_OGL.txt";

		auto VertexShader = new CVertexShaderOGL();

		std::string Temp = VertexShader->ReadFile(RealName);

		const char* VertexCode = Temp.c_str();

		VertexShader->m_VertexShader = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(VertexShader->m_VertexShader,
			NumVertexShader,
			&VertexCode,
			nullptr);

		glCompileShader(VertexShader->m_VertexShader);

		GLint isCompiled = 0;

		glGetShaderiv(VertexShader->m_VertexShader, GL_COMPILE_STATUS, &isCompiled);

		if (isCompiled == GL_FALSE) {

			GLint maxLength = 0;
			glGetShaderiv(VertexShader->m_VertexShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(VertexShader->m_VertexShader, maxLength, &maxLength, &infoLog[0]);

			// We don't need the shader anymore.
			glDeleteShader(VertexShader->m_VertexShader);
			delete VertexShader;

			return nullptr;
		}

		glAttachShader(m_AttachShaderID,
			VertexShader->m_VertexShader);


		return VertexShader;
	}

	void checkGLError()
	{
		GLenum err;
		while ((err = glGetError()) != GL_NO_ERROR)
		{
			std::cout << err;
		}
	}

	CInputLayout* OGLGraphiAPI::CreateInputLayout(CShaderProgram& Vertex,
		InputLayout_Desc& LayoutDesc,
		uint32 NumInputLayout)
	{
		auto InputLa = new CInputLayoutOGL();

		glGenVertexArrays(NumInputLayout,
			&InputLa->m_IPLA);
		//checkGLError();


		glBindVertexArray(InputLa->m_IPLA);
		checkGLError();


		for (int i = 0; i < LayoutDesc.Formats.size(); i++)
		{
			glVertexAttribFormat(i,
				InputLa->GetSize(LayoutDesc.Formats.at(i)),
				GL_FLOAT,
				GL_TRUE,
				InputLa->m_Offset);
			checkGLError();
			glVertexAttribBinding(i, 0);
			checkGLError();
			glEnableVertexAttribArray(i);
			checkGLError();
			InputLa->m_Offset += InputLa->GetSize(LayoutDesc.Formats.at(i)) * 4;
		}


		return InputLa;
	}

	//mas parametros para diferentes samplers
	CSamplerState* OGLGraphiAPI::CreateSamplerState(uint32 NumSamplerState)
	{
		auto SamplerState = new CSamplerStateOGL();

		glGenSamplers(NumSamplerState,
			&SamplerState->m_SamSt);

		glSamplerParameteri(SamplerState->m_SamSt,
			GL_TEXTURE_WRAP_S,
			GL_REPEAT);

		glSamplerParameteri(SamplerState->m_SamSt,
			GL_TEXTURE_WRAP_T,
			GL_REPEAT);

		glSamplerParameteri(SamplerState->m_SamSt,
			GL_TEXTURE_MAG_FILTER,
			GL_LINEAR);

		glSamplerParameteri(SamplerState->m_SamSt,
			GL_TEXTURE_MIN_FILTER,
			GL_LINEAR_MIPMAP_LINEAR);

		return SamplerState;
	}

	CRasterizerState* OGLGraphiAPI::CreateRasterizerState()
	{
		return nullptr;
	}

	void OGLGraphiAPI::SetVertexBuffer(VertexBuffer* VerBuff,
		uint32 StartSlot,
		uint32 NumBuffer,
		uint32 stride,
		uint32 offset)
	{
		auto* VertBuff = reinterpret_cast<VertexBufferOGL*>(VerBuff);
		glBindVertexBuffer(StartSlot,
			VertBuff->m_vBO,
			offset,
			stride);
		checkGLError();


	}

	void OGLGraphiAPI::SetIndexBuffer(IndexBuffer* IndBuff,
		uint32 offset)
	{
		auto* IndexBuff = reinterpret_cast<IndexBufferOGL*>(IndBuff);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,
			IndexBuff->m_IBO);
		checkGLError();
	}

	void OGLGraphiAPI::SetVertexShaderConstantBuffer(ConstantBuffer* ConstBuff,
		uint32 StartSlot,
		uint32 NumBuffer)
	{
		auto* ConstantBuffer = reinterpret_cast<ConstantBufferOGL*>(ConstBuff);
		glBindBufferBase(GL_UNIFORM_BUFFER, StartSlot, ConstantBuffer->m_CBO);
		checkGLError();
	}

	void OGLGraphiAPI::SetPixelShaderConstantBuffer(ConstantBuffer* ConstBuff,
		uint32 StartSlot,
		uint32 NumBuffer)
	{
		auto* ConstantBuffer = reinterpret_cast<ConstantBufferOGL*>(ConstBuff);
		glBindBufferBase(GL_UNIFORM_BUFFER, StartSlot, ConstantBuffer->m_CBO);
		checkGLError();
	}

	void OGLGraphiAPI::SetShaderProgram(CShaderProgram* ShaderProgram)
	{
		auto* ShaderPro = reinterpret_cast<CShaderProgramOGL*>(ShaderProgram);
		glUseProgram(ShaderPro->m_AttachShaderID);
		checkGLError();
	}

	void OGLGraphiAPI::SetPixelShaders(CPixelShader* Pixel)
	{
		/*glAttachShader(m_AttachShaderID,
			VertexShader->m_VertexShader)*/
		glUseProgram(m_AttachShaderID);
		checkGLError();
	}

	void OGLGraphiAPI::SetVertexShaders(CVertexShader* Vertex)
	{
		glUseProgram(m_AttachShaderID);
		checkGLError();
	}

	void OGLGraphiAPI::SetInputLayout(CInputLayout* Inp)
	{
		auto* InpL = reinterpret_cast<CInputLayoutOGL*>(Inp);
		glBindVertexArray(InpL->m_IPLA);
		checkGLError();
	}

	void OGLGraphiAPI::SetSamplerState(const std::vector<CSamplerState*>& Sam,
		uint32 StartSlot)
	{
		for (int i = 0; i < Sam.size(); i++)
		{
			auto SamSt = reinterpret_cast<CSamplerStateOGL*>(Sam.at(i));

			glBindSampler(StartSlot, SamSt->m_SamSt);
			checkGLError();
		}
	}


	void OGLGraphiAPI::SetDepthStencil(Texture* pDSTex)
	{
		auto* DepSten = reinterpret_cast<TextureOGL*>(pDSTex);

		glBindRenderbuffer(GL_RENDERBUFFER,
			DepSten->m_dSV);
		checkGLError();

		glFramebufferRenderbuffer(GL_FRAMEBUFFER,
			GL_DEPTH_ATTACHMENT,
			GL_RENDERBUFFER,
			DepSten->m_dSV);
		checkGLError();
	}

	void OGLGraphiAPI::SetShaderResource(const std::vector<Texture*>& pRTTex,
		uint32 StartSlot)
	{
		for (int i = 0; i < pRTTex.size(); i++)
		{
			auto SamSt = reinterpret_cast<TextureOGL*>(pRTTex.at(i));

			//glTextureView()
			checkGLError();

		}

	}

	void OGLGraphiAPI::SetViewport(uint32 NumViewport,
		float Width,
		float Height,
		float TopLeftX,
		float TopLeftY)
	{
		glViewport(TopLeftX,
			TopLeftY,
			Width,
			Height);
		checkGLError();

	}

	void OGLGraphiAPI::SetPrimitiveTopology(PRIMITIVE_TOPOLOGY Topology)
	{
	}

	void OGLGraphiAPI::SetDefaultRenderTarget()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		checkGLError();

		//separar el depth y el render
		//glEnable(GL_DEPTH_TEST);

	}

	void OGLGraphiAPI::ClearRenderTarget(Texture* RT,
		ColorStruct Color)
	{
		glClearColor(Color.R, Color.G, Color.B, Color.A);
		checkGLError();

		glClear(GL_COLOR_BUFFER_BIT);
		checkGLError();
	}

	void OGLGraphiAPI::ClearDepthStencil(Texture* RT,
		uint32 ClerFlag,
		float Depth,
		uint32 Stencil)
	{
		//glClear()
	}

	void OGLGraphiAPI::ClearDefaultRenderTargetAndDepthStencil(ColorStruct Color)
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		checkGLError();

		glClearColor(Color.R, Color.G, Color.B, Color.A);
		checkGLError();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		checkGLError();
	}

	//tama�o de los datos
	void OGLGraphiAPI::UpdateSubresource(const void* Data,
		ConstantBuffer& ConstantBufffer)
	{
		checkGLError();


	}

	void OGLGraphiAPI::SetRasterizerState(CRasterizerState* RasState)
	{
	}

	void OGLGraphiAPI::SetRenderTarget(const std::vector<Texture*>& pRTTex,
		Texture* pDSTex)
	{
		for (int i = 0; i < pRTTex.size(); i++)
		{
			auto pRTODL = reinterpret_cast<TextureOGL*>(pRTTex.at(i));

			/*ID3D11DepthStencilView* pDSV = nullptr;

			if (nullptr != pDSTex)
			{
				auto pDSDX = reinterpret_cast<TextureOGL*>(pDSTex);
				pDSV = pDSDX->m_dSV;
			}*/

			glBindFramebuffer(GL_FRAMEBUFFER,
				pRTODL->m_rTV);
			checkGLError();

			glFramebufferTexture(GL_FRAMEBUFFER,
				GL_COLOR_ATTACHMENT0,
				pRTODL->m_texture,
				i);
			checkGLError();
		}
	}

	//void OGLGraphiAPI::DrawModel(CShaderProgram& ShaderPro)
	//{
	//	auto& ShaderProOGL = reinterpret_cast<CShaderProgramOGL&>(ShaderPro);
	//}

	void OGLGraphiAPI::DrawIndexed(uint32 NumIndex,
		uint32 StartindexLocation,
		uint32 BaseVertexLocation,
		const void* Index)
	{
		glDrawElements(GL_TRIANGLES, NumIndex, GL_UNSIGNED_INT, 0);
		checkGLError();
	}
	void OGLGraphiAPI::DrawInstanced(uint32 VertexCountPerInstance,
		uint32 InstanceCount,
		uint32 StartVertexLocation,
		uint32 StartInstanceLocation)
	{
		glDrawArraysInstanced(GL_TRIANGLES, StartInstanceLocation, VertexCountPerInstance, InstanceCount);
		checkGLError();
	}

	void OGLGraphiAPI::Draw(uint32 VertexCount,
		uint32 StartVertexLocation)
	{
		glDrawArrays(GL_TRIANGLES, StartVertexLocation, VertexCount);
		checkGLError();
	}

	void OGLGraphiAPI::Present()
	{
		glfwSwapBuffers(m_window);
		//checkGLError();

		glfwPollEvents();
		checkGLError();

	}

	//no es del API
	void OGLGraphiAPI::Destroy()
	{

		//auto InputLay = reinterpret_cast<CInputLayoutOGL*>(InputLayout);
		//glDeleteVertexArrays(1, &InputLay->m_IPLA);

		//auto VertexBuff = reinterpret_cast<VertexBufferOGL*>(VertexBuffer);
		//glDeleteBuffers(1, &VertexBuff->m_vBO);

		//auto IndexBuff = reinterpret_cast<IndexBufferOGL*>(IndexBuffer);
		//glDeleteBuffers(1, &IndexBuff->m_IBO);

		//auto VerShader = reinterpret_cast<CVertexShaderOGL*>(VertexShader);
		//glDeleteShader(VerShader->m_VertexShader);

		//auto PixShader = reinterpret_cast<CPixelShaderOGL*>(PixelShader);
		//glDeleteShader(PixShader->m_PixelShader);


		//for (int i = 0; i < SamplerStates.size(); i++)
		//{
		//	auto Sampler = reinterpret_cast<CSamplerStateOGL*>(SamplerStates.at(i));
		//	//glDeleteSamplers(SamplerStates.size(),Sampler->m_SamSt);

		//}
		glfwTerminate();
	}


	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}