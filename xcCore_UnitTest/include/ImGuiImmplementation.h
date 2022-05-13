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



using namespace xcEngineSDK;

struct CONSTANT_BUFFER
{
  Matrix4x4 mvp;
};

namespace ImGuiImplementation
{


  void
  init();

  void
  update();

  void
  render();
 


  

};

