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

		SceneNode(SPtr<Actor> actor, WeakSptr<SceneNode> parent);

		void
		addChild(SPtr<Actor> child, WeakSptr<SceneNode> parent);

    void
    removeChild(WeakSptr<Actor> child);

    void
    selectChild(WeakSptr<Actor> child);

		void
		renameChild(WeakSptr<Actor> child, const String& newName);

		void
		update(float deltaTime);

		void
		render();

		void
	  getModels(Vector<SPtr<Model>>& model);

	 public:

		 WeakSptr<SceneNode> m_pParent;
     Vector<SPtr<SceneNode>> m_pChild;

     SPtr<Actor> m_pActor;

	 private:

	};
}
