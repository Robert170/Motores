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

#include "xcPrerequisitesCore.h"

namespace xcEngineSDK {

	class Actor
	{
	 public:
		Actor() = default;
		~Actor() = default;

	 private:

	  Matrix4x4 m_location;
		Matrix4x4 m_rotation;
		Matrix4x4 m_scale;
	};


}