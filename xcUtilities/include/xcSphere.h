/*****************************************************************************/
/**
 * @file    xcSphere.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/02/12
 * @brief   class of Sphere
 *
 * This class is using for know if the sphere intersect with other thing
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once

#include "xcPrerequisitesUtilities.h"
#include "xcVector3.h"

using xcEngineSDK::Vector3;

namespace xcEngineSDK {
  class AABB;

  class Sphere 
  {
   public:

    /**
     * @brief default constructor
     */
    Sphere() = default;

    /**
     * @brief default destructor
     */
    ~Sphere() = default;

    

   public:

    /**
     * @brief public function
     */

    /**
		 * @brief      intersec function, to known if intersec with a vector
		 * @param      vector parameter one, vector for the intersection
		 * @bug	       No know Bugs
		 * @return     Returns a bool, depends if intersec or not
		 */
    bool
    intersec(Vector3& vector);

    /**
		 * @brief      intersec function, to known if intersec with a AABB
		 * @param      vector parameter one, vector for the intersection
		 * @bug	       No know Bugs
		 * @return     Returns a bool, depends if intersec or not
		 */
    bool
    intersec(AABB& vector);

   public:

    /**
     * @brief public members
     */

    /**
     * @brief m_position, position of the sphere
     */
    Vector3 m_position;

    /**
     * @brief m_radio, radio of the sphere
     */
    float m_radio;

  };
}