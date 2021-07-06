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

		SceneNode(WeakSptr<Actor> parent, WeakSptr<Actor> actor);

		void
		addChild(WeakSptr<Actor> parent, WeakSptr<Actor> child);

    void
    removeChild(WeakSptr<Actor> child);

    void
    selectChild(const uint32& index);

		void
		renameChild(const uint32& index);

	 public:

     WeakSptr<SceneNode> m_pParent;
     Vector<WeakSptr<SceneNode>> m_pChild;

     SPtr<Actor> m_pActor;

	 private:

	};
}
