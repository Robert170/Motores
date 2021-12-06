/*****************************************************************************/
/**
 * @file    ImGuiImmplementation.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    15/11/2021
 * @brief   Represents the implementation of to imgui
 *
 * Represent the actor of the scene
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
/*****************************************************************************/
/**
 * Includes
 */
 /*****************************************************************************/
#include <xcPrerequisitesCore.h>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Window.hpp>
#include "xcIndexBuffer.h"
#include "xcVertexBuffer.h"
#include "xcDepthStencilState.h"
#include "xcRasterizerState.h"
#include "xcShaderProgram.h"
#include "xcInputLayout.h"
#include "xcConstantBuffer.h"
#include "xcSamplerState.h"
#include "xcTexture.h"
#include "xcBlendState.h"

struct VERTEX_CONSTANT_BUFFER
{
  float   mvp[4][4];
};

using namespace xcEngineSDK;

class ImGuiImplementatio
{
  
 public:
  ImGuiImplementatio() = default;
  ~ImGuiImplementatio() = default;

  void
  init();

  void
  update();

  void
  render();
  

 private:

  SPtr<IndexBuffer> m_IB;
  SPtr<VertexBuffer> m_VB;
  SPtr<ShaderProgram> m_shaderProgramImGui;
  SPtr<InputLayout> m_inputLayout;
  SPtr<ConstantBuffer> m_vertexConstantBuffer;
  VERTEX_CONSTANT_BUFFER m_cbVertex;
  Vector<SPtr<SamplerState>> m_vfontSampler;
  SPtr<RasterizerState> m_rasterizerState;
  SPtr<DepthStencilState> m_depthStencilState;
  SPtr<BlendState> m_blendState;
  Texture* m_fontTextureView;


  uint32 VertexBufferSize = 5000;
  uint32 IndexBufferSize = 10000;

  unsigned char* m_pixels;
  int32 m_width;
  int32 m_height;

};

