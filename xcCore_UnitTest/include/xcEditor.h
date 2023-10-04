/**
 * @file    giEditor.h
 * @author  Jesus Alberto Del Moral Cupil
 * @e       idv18c.jmoral@uartesdigitales.edu.mx
 * @date    01/06/2022
 * @brief   A basic implementation of the editor of the engine.
 * @bug     No known Bugs.
 */

 /**
  * @include
  */
#pragma once
#include "xcImGui.h"
#include "xcContentBrowser.h"
#include "xcHierarchy.h"
#include "xcDetails.h"

using namespace xcEngineSDK;
using namespace ImGui;

/**
 * @brief     Basic implementation of the ui for the Editor for the engine.
 */
class Editor
{
public:

  //Default constructor.
  Editor() = default;

  //Default destructor.
  ~Editor() = default;

  /**
   * @brief      Initialize the editor UI.
   */
  void
    init(void* inHandler, Vector2 inWindowSize);

  /**
   * @brief      Update the information of the editor.
   */
  void
    update(float inDeltaTime);

  /**
   * @brief      Render the information of the editor.
   */
  void
    render();

  /**
   * @brief      Destroy the information of the editor.
   */
  void
    destroy();

  /**
   * @brief      Detect the inputs of the editor.
   */
  void
    callBack();

private:

  SPtr<UI> m_ui;

  SPtr<ContentBrowser> m_contentBrowser;

  SPtr<Hierarchy> m_hierarchy;

  SPtr<Details> m_details;

  void* m_windowHandle = nullptr;

  bool m_touchingImGui = false;

  void* m_windowsHandle = nullptr;

  bool m_startOmniverse = false;

  bool m_isRunningOmniverse = false;

};