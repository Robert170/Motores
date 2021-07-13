/*****************************************************************************/
/**
 * @file    xcSceneGraph.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/06/04
 * @brief   Represents the SceneGraph of the core
 *
 * Represents the SceneGraph of the engine, this class allows 
 * you to have control over all the objects that are in the scene 
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once

/*****************************************************************************/
/**
 * Includes
 */
 /*****************************************************************************/
#include <xcModule.h>
#include "xcPrerequisitesCore.h"
#include "xcSceneNode.h"

namespace xcEngineSDK {
	class XC_CORE_EXPORT SceneGraph : public Module<SceneGraph>
	{
	 public:
		SceneGraph();
		virtual ~SceneGraph() = default;

		

		void
		addActor(SPtr<SceneNode> parent, SPtr<Actor> child);

		void
		removeActor(const SPtr<Actor> actor);

		void
		selectActor(const SPtr<Actor> actor);

    void
    renameActor(const SPtr<Actor> actor, const String& newName);

	

	 public:
		SPtr<SceneNode> m_pRoot;

	 private:
		 

	};

	/**
   * @brief export the instance 
   */
  XC_CORE_EXPORT SceneGraph& 
	g_sceneGraph();
}
