

 /**
  * @include
  */
#pragma once
#include <xcStdHeaders.h>
#include <xcSceneNode.h>
#include "xcImGui.h"

using namespace xcEngineSDK;
using namespace ImGui;

class Hierarchy
{
public:
  //Default constructor.
  Hierarchy();

  //Default destructor.
  ~Hierarchy() = default;

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

  void
    renderNodeWithChilds(SPtr<SceneNode> inNode);

  void
    renderNode(SPtr<SceneNode> inNode);

  void
    evaluateNode(SPtr<SceneNode> inNode);

private:

  ImGuiWindowFlags m_windowFlags = 0;
  ImGuiTreeNodeFlags m_rootFlags = 0;
  ImGuiTreeNodeFlags m_treeSelectableFlags = 0;
  ImGuiTreeNodeFlags m_leafFlags = 0;




  friend class Details;
};
