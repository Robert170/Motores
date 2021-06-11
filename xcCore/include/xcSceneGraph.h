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
	class SceneGraph : public Module<SceneGraph>
	{
	 public:
		SceneGraph() = default;
		virtual ~SceneGraph() = default;


		void
		addActor(const SPtr<Actor>& actor);

		void
		removeActor(const SPtr<Actor>& actor);

	 public:
		UPtr<SceneNode> m_pRoot;

	 private:
		 

	};
}
