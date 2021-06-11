/*****************************************************************************/
/**
 * @file    xcSceneNode.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/06/04
 * @brief   Represents the nodes of the scene
 *
 * Represents all nodes of the scene
 * 
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
#include "xcPrerequisitesCore.h"
#include "xcActor.h"

namespace xcEngineSDK {

	class SceneNode
	{
	 public:
		 SceneNode() = default;
		~SceneNode() = default;

		SceneNode(WeakSptr<Actor> parent, SPtr<Actor> actor);

		void
		addChild(WeakSptr<Actor> child);

    void
    removeChild(WeakSptr<Actor> child);

	 public:
     WeakSptr<SceneNode> m_pParent;
     List<WeakSptr<SceneNode>>  m_pChild;

     SPtr<Actor> m_pActor;

	 private:

	};
}
