/*****************************************************************************/
/**
 * @file    xcRay.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/02/15
 * @brief   class of ray
 *
 * This class is using for know if the ray intersect with other thing
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
#include "xcPrerequisitesUtilities.h"
#include "xcVector3.h"


using xcEngineSDK::Vector3;

namespace xcEngineSDK {

  class Sphere;
  class AABB;

  class XC_UTILITY_EXPORT Ray 
  {
   public:
    /**
     * @brief default constructor
     */
     Ray() = default;

    /**
     * @brief default destructor
     */
     ~Ray() = default;

   public:

    /**
     * @brief public function
     */

    /**
		 * @brief      intersec function, to known if intersec with a sphere
		 * @param      sphere parameter one, sphere for the intersection
		 * @bug	       No know Bugs
		 * @return     Returns a bool, depends if intersec or not
		 */
    bool
    intersec(Sphere& sphere);

    /**
		 * @brief      intersec function, to known if intersec with a AABB
		 * @param      box parameter one, sphere for the intersection
		 * @bug	       No know Bugs
		 * @return     Returns a bool, depends if intersec or not
		 */
    bool
    intersec(AABB& box);

   public:

    /**
     * @brief public members
     */

    /**
     * @brief m_position, position of the ray
     */
    Vector3 m_position;

    /**
     * @brief m_direction, direction of the ray
     */
    Vector3 m_direction;

  };
}
