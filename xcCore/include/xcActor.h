/*****************************************************************************/
/**
 * @file    xcActor.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/05/25
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
#include <xcMatrix4x4.h>
#include <xcQuaternions.h>
#include "xcPrerequisitesCore.h"
#include "xcGameObject.h"

namespace xcEngineSDK {

	class Actor : public GameObject
	{
	 public:
		Actor() = default;
		virtual ~Actor() = default;

	 public:

		bool m_isSelected;
	  String m_actorName;

	 private:

	  Matrix4x4 m_location;
		Quaternion m_rotation;
		Matrix4x4 m_scale;
	};


}