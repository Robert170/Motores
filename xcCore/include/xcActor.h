/*****************************************************************************/
/**
 * @file    xcActor.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    19/08/2021
 * @brief   Represents the actor of the scene 
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
 
#include <xcTransform.h>
#include "xcPrerequisitesCore.h"
#include "xcGameObject.h"
#include "xcComponent.h"
#include "xcModel.h"



namespace xcEngineSDK {


	class XC_CORE_EXPORT Actor : public GameObject
	{
	 public:
		Actor() = default;

		Actor(String name);

		virtual ~Actor() = default;
		

		void
		addComponent(WeakSptr<Component> component);

    void
    removeComponent(WeakSptr<Component>& component);

		void
		setName(String name);

    void
    setSelect(bool selected);

		void
		renderComponent();

    void
    update(const float& deltaTime);


    void
    getModels(Vector<SPtr<Model>>& model);

    Vector3&
    getTraslation();

    Quaternion&
    getRotation();

    Vector3&
    getScale();



	 public:

		bool m_isSelected = false;
	  String m_actorName;

	 private:

		
		Transfom m_actorTrasform;
		//TODO cambiar a map
		Vector<SPtr<Component>> m_vComponents;

	};


}