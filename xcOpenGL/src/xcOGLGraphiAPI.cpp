#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

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

namespace xcEngineSDK {
	void 
	framebuffer_size_callback(GLFWwindow* window, int width, int height);


	void
	OGLGraphiAPI::createDeviceandSwap(sf::WindowHandle window) {

    PIXELFORMATDESCRIPTOR pfd = {
      sizeof(PIXELFORMATDESCRIPTOR),
      1,
      PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    // Flags
      PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
      32,                   // Colordepth of the framebuffer.
      0, 0, 0, 0, 0, 0,
      0,
      0,
      0,
      0, 0, 0, 0,
      24,                   // Number of bits for the depthbuffer
      8,                    // Number of bits for the stencilbuffer
      0,                    // Number of Aux buffers in the framebuffer.
      PFD_MAIN_PLANE,
      0,
      0, 0, 0
    };

		m_hdc = GetDC(window);

		int32 pixel = ChoosePixelFormat(m_hdc, &pfd);

		SetPixelFormat(m_hdc,pixel, &pfd);

		wglMakeCurrent(m_hdc, wglCreateContext(m_hdc));

		if (!gladLoadGL()){
			return;
		}

		RECT rect;

		GetClientRect(window, &rect);

		m_width = rect.right - rect.left;
		m_height = rect.bottom - rect.top;

		setViewport(1, m_width, m_height);

		glEnable(GL_DEPTH_TEST);

		glBindFramebuffer(GL_FRAMEBUFFER, 0);

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
	
		return MatrixWorld = Matrix4x4::IDENTITY_MATRIX;
	}

	Matrix4x4
	OGLGraphiAPI::initMatrixView(Matrix4x4& MatrixView,
			                         Vector3& Eye,
			                         Vector3& At,
			                         Vector3& Up) {
		//TODO
		////init view matrix
    MatrixView = MatrixView.lookAtLH(Eye,
                                     At,
                                     Up);

		return MatrixView;
	}

	Matrix4x4
	OGLGraphiAPI::initMatrixProjection(Matrix4x4& MatrixProjection,
			                               float& Fov,
			                               float& Height,
			                               float& Width,
			                               float& Near,
			                               float& Far) {

		MatrixProjection = MatrixProjection.perspectiveFovLH(Fov,
                                                         Height,
                                                         Width,
                                                         Near,
                                                         Far);
		return MatrixProjection;
	}


	SPtr<VertexBuffer>
	OGLGraphiAPI::createVertexBuffer(const Vector <BoneVertex>& Ver,
			                             uint32 NumBuffers) {

		SPtr<VertexBufferOGL> vertexBuffer = std::make_shared<VertexBufferOGL>();
	

		glGenBuffers(NumBuffers,
			           &vertexBuffer->m_vBO);

		glBindBuffer(GL_ARRAY_BUFFER,
			           vertexBuffer->m_vBO);

		glBufferData(GL_ARRAY_BUFFER,
			           Ver.size() * sizeof(BoneVertex),
			           Ver.data(),
			           GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);

		/*glBindBuffer(GL_ARRAY_BUFFER,
							 0);*/


		return vertexBuffer;
	}

	SPtr<IndexBuffer>
	OGLGraphiAPI::createIndexBuffer(const Vector<uint32>& Ind,
			                            uint32 NumBuffer) {

		SPtr<IndexBufferOGL> indexBuffer = std::make_shared<IndexBufferOGL>();


		glGenBuffers(NumBuffer,
			           &indexBuffer->m_IBO);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,
			           indexBuffer->m_IBO);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			           Ind.size() * sizeof(uint32),
			           Ind.data(),
			           GL_STATIC_DRAW);

		return indexBuffer;
	}

	SPtr<ConstantBuffer>
	OGLGraphiAPI::createConstantBuffer(uint32 BufferSize,//2
			                               uint32 NumBuffer, //1
			                               const void* Data) {//3

    SPtr<ConstantBufferOGL> constantBuffer = std::make_shared<ConstantBufferOGL>();
    

    glGenBuffers(NumBuffer,
      &constantBuffer->m_CBO);

    glBindBuffer(GL_UNIFORM_BUFFER,
      constantBuffer->m_CBO);

    glBufferData(GL_UNIFORM_BUFFER,
      BufferSize,
      Data,
      GL_DYNAMIC_DRAW);

    glBindBuffer(GL_UNIFORM_BUFFER,
      0);


    return constantBuffer;
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
			                          TYPE_USAGE Usage,
		                            const void* Data) {

		XC_UNREFERENCED_PARAMETER(format);
		XC_UNREFERENCED_PARAMETER(Usage);
		

    TextureOGL* texture = new TextureOGL();

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
	  unsigned int OglFormat;
	  if (TF_R16_UINT == format) {
	  	OglFormat = GL_RED;
	  }
	  else if (TF_R32G32B32_UINT == format) {
	  	OglFormat = GL_RGB;
	  }
	  else if (TF_R16G16B16A16_UINT == format) {
	  	OglFormat = GL_RGBA;
	  }
	  glGenTextures(numberTexture, 
	  	          &texture->m_texture);
	  
	  glBindTexture(GL_TEXTURE_2D, 
	  	            texture->m_texture);
	  
	  glTexImage2D(GL_TEXTURE_2D, 
	  	           0, 
	  	           OglFormat,
	  	           width, 
	  	           height, 
	  	           0, 
	  	           OglFormat,
	  	           GL_UNSIGNED_BYTE, 
	  	           Data);
	  
	  glTexParameteri(GL_TEXTURE_2D, 
	  	              GL_TEXTURE_WRAP_S, 
	  	              GL_REPEAT);	
	  glTexParameteri(GL_TEXTURE_2D, 
	  	              GL_TEXTURE_WRAP_T, 
	  	              GL_REPEAT);
	  
	  glTexParameteri(GL_TEXTURE_2D, 
	  	              GL_TEXTURE_MIN_FILTER, 
	  	              GL_LINEAR);
	  glTexParameteri(GL_TEXTURE_2D, 
	  	              GL_TEXTURE_MAG_FILTER, 
	  	              GL_LINEAR);
	  
	  glGenerateMipmap(GL_TEXTURE_2D);
	  
	  return texture;
	}


	void
		OGLGraphiAPI::createTexture3D() {
	}

	SPtr<ShaderProgram>
	OGLGraphiAPI::createShaderProgram(const String& FileNameVS,
			                              const String& FileNamePS,
			                              const String& EntryVS,
			                              const String& EntryPS,
			                              const String& ShaderModelVS,
			                              const String& ShaderModelPS,
			                              int32 NumVertexShader,
			                              int32 NumPixelShader) {

		XC_UNREFERENCED_PARAMETER(ShaderModelPS);
		XC_UNREFERENCED_PARAMETER(ShaderModelVS);
		XC_UNREFERENCED_PARAMETER(EntryPS);
		XC_UNREFERENCED_PARAMETER(EntryVS);

    SPtr<ShaderProgramOGL> shaderProgram = std::make_shared<ShaderProgramOGL>();

		

		shaderProgram->m_attachShaderID = glCreateProgram();


		// vertex Shader
		String RealName = FileNameVS + "_OGL.txt";

		shaderProgram->m_vertexShaderProgram = new VertexShaderOGL();

		String Temp = shaderProgram->m_vertexShaderProgram->readFile(RealName);

		const char* VertexCode = Temp.c_str();

		shaderProgram->m_vertexShaderProgram->
		               m_vertexShader = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(shaderProgram->m_vertexShaderProgram->m_vertexShader,
			             NumVertexShader,
			             &VertexCode,
			             nullptr);

		glCompileShader(shaderProgram->m_vertexShaderProgram->m_vertexShader);

		GLint isCompiled = 0;

		glGetShaderiv(shaderProgram->m_vertexShaderProgram->m_vertexShader,
			            GL_COMPILE_STATUS,
			            &isCompiled);

		if (isCompiled == GL_FALSE) {

			GLint maxLength = 0;
			glGetShaderiv(shaderProgram->m_vertexShaderProgram->m_vertexShader,
				            GL_INFO_LOG_LENGTH,
				            &maxLength);

			// The maxLength includes the NULL character
			Vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(shaderProgram->m_vertexShaderProgram->m_vertexShader,
				                 maxLength,
				                 &maxLength,
				                 &infoLog[0]);

			// We don't need the shader anymore.
			glDeleteShader(shaderProgram->m_vertexShaderProgram->m_vertexShader);
			//delete shaderProgram;

			return nullptr;
		}


		//pixel shader
		RealName = FileNamePS + "_OGL.txt";

		shaderProgram->m_pixelShaderProgram = new PixelShaderOGL();

		Temp = shaderProgram->m_pixelShaderProgram->readFile(RealName);

		const char* PixelCode = Temp.c_str();

		shaderProgram->m_pixelShaderProgram->m_pixelShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(shaderProgram->m_pixelShaderProgram->m_pixelShader,
			NumPixelShader,
			&PixelCode,
			nullptr);

		glCompileShader(shaderProgram->m_pixelShaderProgram->m_pixelShader);

		glGetShaderiv(shaderProgram->m_pixelShaderProgram->m_pixelShader, GL_COMPILE_STATUS, &isCompiled);

		if (isCompiled == GL_FALSE) {

			GLint maxLength = 0;
			glGetShaderiv(shaderProgram->m_pixelShaderProgram->m_pixelShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(shaderProgram->m_pixelShaderProgram->m_pixelShader, maxLength, &maxLength, &infoLog[0]);

			// We don't need the shader anymore.
			glDeleteShader(shaderProgram->m_pixelShaderProgram->m_pixelShader);
			//delete shaderProgram;

			return nullptr;
		}


		//set del shader
		glAttachShader(shaderProgram->m_attachShaderID,
			shaderProgram->m_vertexShaderProgram->m_vertexShader);
		glAttachShader(shaderProgram->m_attachShaderID,
			shaderProgram->m_pixelShaderProgram->m_pixelShader);
		glLinkProgram(shaderProgram->m_attachShaderID);


		return shaderProgram;
	}

	
    SPtr<ShaderProgram>
    createComputeShader(const String& FileNameCS,
                        const String& EntryCS,
                        const String& ShaderModelCS) {

      return nullptr;
		}

	SPtr<PixelShader> 
	OGLGraphiAPI::createPixelShaders(const String& FileName,
		                               const String& Entry,
		                               const String& ShaderModel,
		                               int32 NumPixelShader) {
		XC_UNREFERENCED_PARAMETER(Entry);
		XC_UNREFERENCED_PARAMETER(ShaderModel);

		// Pixel Shader
		String RealName = FileName + "_OGL.txt";

    SPtr<PixelShaderOGL> pixelShader = std::make_shared<PixelShaderOGL>();

		String Temp = pixelShader->readFile(RealName);

		const char* PixelCode = Temp.c_str();

		pixelShader->m_pixelShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(pixelShader->m_pixelShader,
			             NumPixelShader,
			             &PixelCode,
			             nullptr);

		glCompileShader(pixelShader->m_pixelShader);

		GLint isCompiled = 0;

		glGetShaderiv(pixelShader->m_pixelShader, GL_COMPILE_STATUS, &isCompiled);

		if (isCompiled == GL_FALSE) {

			GLint maxLength = 0;
			glGetShaderiv(pixelShader->m_pixelShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			Vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(pixelShader->m_pixelShader, 
				                 maxLength, 
				                 &maxLength, 
				                 &infoLog[0]);

			// We don't need the shader anymore.
			glDeleteShader(pixelShader->m_pixelShader);

			return nullptr;
		}



		//set del shader
		glAttachShader(m_attachShaderID,
			             pixelShader->m_pixelShader);

		glLinkProgram(m_attachShaderID);

		return pixelShader;

	}



	SPtr<VertexShader>
	OGLGraphiAPI::createVertexShaders(const String& FileName,
			                              const String& Entry,
			                              const String& ShaderModel,
			                              int32 NumVertexShader) {
		
		XC_UNREFERENCED_PARAMETER(Entry);
		XC_UNREFERENCED_PARAMETER(ShaderModel);
		// vertex Shader
		String RealName = FileName + "_OGL.txt";

    SPtr<VertexShaderOGL> vertexShader = std::make_shared<VertexShaderOGL>();

		String Temp = vertexShader->readFile(RealName);

		const char* VertexCode = Temp.c_str();

		vertexShader->m_vertexShader = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(vertexShader->m_vertexShader,
			             NumVertexShader,
			             &VertexCode,
			             nullptr);

		glCompileShader(vertexShader->m_vertexShader);

		GLint isCompiled = 0;

		glGetShaderiv(vertexShader->m_vertexShader, GL_COMPILE_STATUS, &isCompiled);

		if (isCompiled == GL_FALSE) {

			GLint maxLength = 0;
			glGetShaderiv(vertexShader->m_vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			Vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(vertexShader->m_vertexShader, maxLength, &maxLength, &infoLog[0]);

			// We don't need the shader anymore.
			glDeleteShader(vertexShader->m_vertexShader);

			return nullptr;
		}

		glAttachShader(m_attachShaderID,
			             vertexShader->m_vertexShader);


		return vertexShader;
	}

	InputLayout_Desc 
	OGLGraphiAPI::CreateInputLayoutDesc(Vector<String> SemanticsVector, 
		                                  Vector<uint32> FormatsVector) {
    InputLayout_Desc Temp;

    Temp.Semantics = SemanticsVector;
    Temp.Formats = FormatsVector;

    return Temp;
	}

	void checkGLError()
	{
		GLenum err;
		while ((err = glGetError()) != GL_NO_ERROR)
		{
			std::cout << err;
		}
	}

	SPtr<InputLayout>
	OGLGraphiAPI::createInputLayout(ShaderProgram& Vertex,
			                            InputLayout_Desc& LayoutDesc,
			                            uint32 NumInputLayout) {

		XC_UNREFERENCED_PARAMETER(Vertex);

    SPtr<InputLayoutOGL> inputLa = std::make_shared<InputLayoutOGL>();

		inputLa->m_numberOfInputLayout = NumInputLayout;
	  glGenVertexArrays(NumInputLayout,
		                  &inputLa->m_iPLA);
	checkGLError();


	glBindVertexArray(inputLa->m_iPLA);
	checkGLError();


	for (uint32 i = 0; i < LayoutDesc.Formats.size(); ++i) {
		glVertexAttribFormat(i,
			                   inputLa->getSize(LayoutDesc.Formats.at(i)), 
			                   GL_FLOAT,
			                   GL_TRUE, 
			                   inputLa->m_offset);
		checkGLError();
		glVertexAttribBinding(i, 0);
		checkGLError();
		glEnableVertexAttribArray(i);
		checkGLError();
		inputLa->m_offset += inputLa->getSize(LayoutDesc.Formats.at(i)) * 4;
	}
	

	return inputLa;
	}

	SPtr<InputLayout> 
	OGLGraphiAPI::createAutomaticInputLayout(ShaderProgram& VS) {
		return nullptr;
	}

	//mas parametros para diferentes samplers
	SPtr<SamplerState>
	OGLGraphiAPI::createSamplerState(uint32 NumSamplerState) {

    //new SamplerStateOGL();
    SPtr<SamplerStateOGL> samplerState = std::make_shared<SamplerStateOGL>();

		glGenSamplers(NumSamplerState,
			            &samplerState->m_samSt);

		glSamplerParameteri(samplerState->m_samSt,
			                  GL_TEXTURE_WRAP_S,
			                  GL_REPEAT);

		glSamplerParameteri(samplerState->m_samSt,
			                  GL_TEXTURE_WRAP_T,
			                  GL_REPEAT);

		glSamplerParameteri(samplerState->m_samSt,
			                  GL_TEXTURE_MAG_FILTER,
			                  GL_LINEAR);

		glSamplerParameteri(samplerState->m_samSt,
			                  GL_TEXTURE_MIN_FILTER,
			                  GL_LINEAR_MIPMAP_LINEAR);

		return samplerState;
	}

	SPtr<RasterizerState>
   OGLGraphiAPI::createRasterizerState(FILL_MODE::E fillMode,
                                       CULL_MODE::E cullMode,
                                       bool counterClockwise) {
		return nullptr;
	}

	void
	OGLGraphiAPI::setVertexBuffer(WeakSptr<VertexBuffer> VerBuff,
			                          uint32 StartSlot,
			                          uint32 NumBuffer,
			                          uint32 stride,
			                          uint32 offset) {


		XC_UNREFERENCED_PARAMETER(NumBuffer);
		VertexBufferOGL* VertBuff = 
	  reinterpret_cast<VertexBufferOGL*>(VerBuff.lock().get());

		glBindVertexBuffer(StartSlot,
			                 VertBuff->m_vBO,
			                 offset,
			                 stride);
		checkGLError();


	}

	void
	OGLGraphiAPI::setIndexBuffer(WeakSptr<IndexBuffer> IndBuff,
			                         uint32 offset) {

		XC_UNREFERENCED_PARAMETER(offset);

		IndexBufferOGL* IndexBuff = 
		reinterpret_cast<IndexBufferOGL*>(IndBuff.lock().get());

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,
			           IndexBuff->m_IBO);

		checkGLError();
	}

	void
	OGLGraphiAPI::setVSConstantBuffer(WeakSptr<ConstantBuffer> constBuff,
			                              uint32 StartSlot,
			                              uint32 NumBuffer) {

		XC_UNREFERENCED_PARAMETER(NumBuffer);

    ConstantBufferOGL* ConstantBuffer =
      reinterpret_cast<ConstantBufferOGL*>(constBuff.lock().get());

    glBindBufferBase(GL_UNIFORM_BUFFER,
      StartSlot,
      ConstantBuffer->m_CBO);
		checkGLError();
	}

	void
	OGLGraphiAPI::setPSConstantBuffer(WeakSptr<ConstantBuffer> constBuff,
			                              uint32 StartSlot,
			                              uint32 NumBuffer) {

		XC_UNREFERENCED_PARAMETER(NumBuffer);

		ConstantBufferOGL* ConstantBuffer = 
		reinterpret_cast<ConstantBufferOGL*>(constBuff.lock().get());
		
		glBindBufferBase(GL_UNIFORM_BUFFER,
			               StartSlot,
			               ConstantBuffer->m_CBO);
		checkGLError();
	}

	void
	OGLGraphiAPI::setShaderProgram(WeakSptr<ShaderProgram> shaderProgram) {

		ShaderProgramOGL* ShaderPro = 
		reinterpret_cast<ShaderProgramOGL*>(shaderProgram.lock().get());
		glUseProgram(ShaderPro->m_attachShaderID);
		checkGLError();
	}

	void
	OGLGraphiAPI::setPS(WeakSptr<PixelShader> pixel) {
		/*glAttachShader(m_attachShaderID,
			VertexShader->m_vertexShader)*/
		XC_UNREFERENCED_PARAMETER(pixel);
		glUseProgram(m_attachShaderID);
		checkGLError();
	}

	void
	OGLGraphiAPI::setVS(WeakSptr<VertexShader> vertex) {

		XC_UNREFERENCED_PARAMETER(vertex);
		glUseProgram(m_attachShaderID);
		checkGLError();
	}

	void
	OGLGraphiAPI::setInputLayout(WeakSptr<InputLayout> Inp) {

		InputLayoutOGL* InpL = 
		reinterpret_cast<InputLayoutOGL*>(Inp.lock().get());
		glBindVertexArray(InpL->m_iPLA);
		checkGLError();
	}

	void
	OGLGraphiAPI::setSamplerState(const Vector<SPtr<SamplerState>>& Sam,
			                          uint32 StartSlot) {

		for (uint32 i = 0; i < Sam.size(); ++i) {
			auto SamSt = reinterpret_cast<SamplerStateOGL*>(Sam[i].get());

			glBindSampler(StartSlot, SamSt->m_samSt);
			checkGLError();
		}
	}


	void
	OGLGraphiAPI::setDepthStencil(WeakSptr<Texture> pDSTex) {



		TextureOGL* DepSten = reinterpret_cast<TextureOGL*>(pDSTex.lock().get());

		glBindRenderbuffer(GL_RENDERBUFFER,
			                 DepSten->m_dSV);
		checkGLError();

		glFramebufferRenderbuffer(GL_FRAMEBUFFER,
			                        GL_DEPTH_ATTACHMENT,
			                        GL_RENDERBUFFER,
			                        DepSten->m_dSV);
		checkGLError();
	}

	void
	OGLGraphiAPI::setShaderResource(const Vector<Texture*>& pRTTex,
			                            uint32 StartSlot) {

		XC_UNREFERENCED_PARAMETER(StartSlot);
		XC_UNREFERENCED_PARAMETER(pRTTex);

		for (uint32 i = 0; i < pRTTex.size(); ++i) {
			//auto SamSt = reinterpret_cast<TextureOGL*>(pRTTex.at(i));

			//glTextureView()
			checkGLError();

		}

	}

	void
	OGLGraphiAPI::setViewport(uint32 NumViewport,
			                      float Width,
			                      float Height,
			                      float TopLeftX,
			                      float TopLeftY) {
		XC_UNREFERENCED_PARAMETER(NumViewport);
		glViewport(GLint(TopLeftX),
			         GLint(TopLeftY),
			         GLsizei(Width),
			         GLsizei(Height));
		checkGLError();

	}

	void
	OGLGraphiAPI::setPrimitiveTopology(PRIMITIVE_TOPOLOGY Topology) {
		XC_UNREFERENCED_PARAMETER(Topology);
	}

	void
	OGLGraphiAPI::setDefaultRenderTarget() {

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		checkGLError();

		//separar el depth y el render
		//glEnable(GL_DEPTH_TEST);

	}

	Matrix4x4 
	OGLGraphiAPI::matri4x4Context(const Matrix4x4& matrix) {

		return matrix;
	}

	void
	OGLGraphiAPI::clearRenderTarget(Texture* RT,
			                            ColorStruct Color) {

		XC_UNREFERENCED_PARAMETER(RT);
		glClearColor(Color.R, Color.G, Color.B, Color.A);
		checkGLError();

		glClear(GL_COLOR_BUFFER_BIT);
		checkGLError();
	}

	void
	OGLGraphiAPI::clearDepthStencil(Texture* RT,
			                            uint32 ClerFlag,
			                            float Depth,
			                            uint32 Stencil) {

		XC_UNREFERENCED_PARAMETER(RT);
		XC_UNREFERENCED_PARAMETER(ClerFlag);
		XC_UNREFERENCED_PARAMETER(Depth);
		XC_UNREFERENCED_PARAMETER(Stencil);
		//glClear()
	}

	void
	OGLGraphiAPI::clearDefaultRenderTargetAndDepthStencil(ColorStruct Color) {
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		checkGLError();

		glClearColor(Color.R, Color.G, Color.B, Color.A);
		checkGLError();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		checkGLError();
	}

	//tamaño de los datos
	void
  OGLGraphiAPI::updateSubresource(const void* Data,
		                              ConstantBuffer& ConstantBufffer) {
		
		XC_UNREFERENCED_PARAMETER(Data);
		XC_UNREFERENCED_PARAMETER(ConstantBufffer);
		checkGLError();


	}

	Texture*
	OGLGraphiAPI::textureFromFile(String path) {

    Texture* texture = new Texture();

    int width, height, nrComponents;
    unsigned char* data = stbi_load(path.c_str(),
			                              &width, 
			                              &height, 
			                              &nrComponents, 
			                              0);
    if (data) {
      TEXTURE_FORMAT format;
      if (nrComponents == 1) {

        format = TF_R16_UINT;
      }
      else if (nrComponents == 3) {

        format = TF_R32G32B32_UINT;
      }
      else if (nrComponents == 4) {

        format = TF_R16G16B16A16_UINT;
      }
      //create texture
      texture = createTexture2D(width,
                                height,
                                1,
                                format,
                                TEXTURE_BIND_SHADER_RESOURCE,
                                TYPE_USAGE_DEFAULT,
                                data);
      //m_texturesloaded.push_back(m_texture);



      stbi_image_free(data);
    }
    else {
      std::cout << "Texture failed to load at path: " << path << std::endl;
      stbi_image_free(data);
    }

    return texture;
	}

	void 
	OGLGraphiAPI::setRasterizerState(WeakSptr<RasterizerState> RasState) {

		XC_UNREFERENCED_PARAMETER(RasState);
	}

	void 
	OGLGraphiAPI::setRenderTarget(const Vector<Texture*>& pRTTex,
		                            Texture* pDSTex) {
		XC_UNREFERENCED_PARAMETER(pDSTex);

		for (uint32 i = 0; i < pRTTex.size(); ++i) {
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

	//void OGLGraphiAPI::DrawModel(ShaderProgram& ShaderPro)
	//{
	//	auto& ShaderProOGL = reinterpret_cast<ShaderProgramOGL&>(ShaderPro);
	//}

	void 
	OGLGraphiAPI::drawIndexed(uint32 NumIndex,
		                        uint32 StartindexLocation,
		                        uint32 BaseVertexLocation,
		                        const void* Index) {

		XC_UNREFERENCED_PARAMETER(StartindexLocation);
		XC_UNREFERENCED_PARAMETER(BaseVertexLocation);
		XC_UNREFERENCED_PARAMETER(Index);
		glDrawElements(GL_TRIANGLES, NumIndex, GL_UNSIGNED_INT, 0);
		checkGLError();
	}
	void 
	OGLGraphiAPI::drawInstanced(uint32 VertexCountPerInstance,
		                          uint32 InstanceCount,
		                          uint32 StartVertexLocation,
		                          uint32 StartInstanceLocation) {

		XC_UNREFERENCED_PARAMETER(StartVertexLocation);
		glDrawArraysInstanced(GL_TRIANGLES, 
			                    StartInstanceLocation,
			                    VertexCountPerInstance, 
			                    InstanceCount);
		checkGLError();
	}

	void 
	OGLGraphiAPI::draw(uint32 VertexCount,
		                 uint32 StartVertexLocation) {
		glDrawArrays(GL_TRIANGLES, StartVertexLocation, VertexCount);
		checkGLError();
	}

	void
	OGLGraphiAPI::present() {

		SwapBuffers(m_hdc);

		/*glfwSwapBuffers(m_window);
		checkGLError();

		glfwPollEvents();
		checkGLError();*/

	}

	//no es del API
	void 
	OGLGraphiAPI::destroy() {

		//auto InputLay = reinterpret_cast<InputLayoutOGL*>(InputLayout);
		//glDeleteVertexArrays(1, &InputLay->m_iPLA);

		//auto VertexBuff = reinterpret_cast<VertexBufferOGL*>(VertexBuffer);
		//glDeleteBuffers(1, &VertexBuff->m_vBO);

		//auto IndexBuff = reinterpret_cast<IndexBufferOGL*>(IndexBuffer);
		//glDeleteBuffers(1, &IndexBuff->m_IBO);

		//auto VerShader = reinterpret_cast<CVertexShaderOGL*>(VertexShader);
		//glDeleteShader(VerShader->m_vertexShader);

		//auto PixShader = reinterpret_cast<CPixelShaderOGL*>(PixelShader);
		//glDeleteShader(PixShader->m_pixelShader);


		//for (uint32 i = 0; i < SamplerStates.size(); ++i)
		//{
		//	auto Sampler = reinterpret_cast<SamplerStateOGL*>(SamplerStates.at(i));
		//	//glDeleteSamplers(SamplerStates.size(),Sampler->m_samSt);

		//}
		glfwTerminate();
	}


	void 
	framebuffer_size_callback(GLFWwindow* window, 
		                        int width, 
		                        int height) {

		XC_UNREFERENCED_PARAMETER(window);
		glViewport(0, 0, width, height);
	}

  

}