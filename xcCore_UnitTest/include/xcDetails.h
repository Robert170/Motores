
 /**
  * @include
  */
#pragma once

#include <xcStdHeaders.h>
#include "xcImGui.h"

using namespace xcEngineSDK;
using namespace ImGui;

class Details
{
public:
  //Default constructor.
  Details();

  //Default destructor.
  ~Details() = default;

  /**
   * @brief      Initialize the information.
   */
  void
  init();

  /**
   * @brief      Update the information.
   */
  void
  update(float inDeltaTime);

  /**
   * @brief      Render the information.
   */
  void
  render();

  /**
   * @brief      Destroy the information.
   */
  void
  destroy();

private:

  ImGuiWindowFlags m_windowFlags = 0;

};
