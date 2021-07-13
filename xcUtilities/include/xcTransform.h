/*****************************************************************************/
/**
 * @file    xcTransform.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/07/07
 * @brief   Represents the transform to actors
 *
 * Represents athe transform to actors of the scene, contains, traslation, 
 * rotation, scale
 
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
#include "xcVector3.h"
#include "xcQuaternions.h"
#include "xcPrerequisitesUtilities.h"

namespace xcEngineSDK {

  class XC_UTILITY_EXPORT Transfom 
	{
	 public:
		Transfom() = default;
		~Transfom() = default;
		Transfom(const Vector3& traslation, 
			       const Quaternion& rotation,
			       const Vector3& scale);


	 public:

	 private:

    /**
     * @brief Translation of this transformation, as a vector.
     */
    Vector3	m_translation = Vector3::ZERO;

	  /**
     * @brief Rotation of this transformation, as a quaternion.
     */
    Quaternion m_rotation = Quaternion::IDENTITY;

    /**
     * @brief3D scale as a vector.
     */
    Vector3	m_scale = Vector3::UNIT;

	};

}
