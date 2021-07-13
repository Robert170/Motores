/**
 * @class BaaseApp
 *
 * @brief class for the base for the app
 *
 * This class contains the base aplication for the app
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 4/19/2021
 *
 *
 * @bug	No know Bugs
 */

#pragma once


#include <xcPlugin.h>

#include "xcPrerequisitesCore.h"
#include "xcGraphiAPI.h"
#include "xcSceneGraph.h"


using namespace xcEngineSDK;

namespace xcEngineSDK {

	
	class XC_CORE_EXPORT BaseApp
	{
	 public:
		BaseApp() = default;
		~BaseApp() = default;

		/**
		 * @brief private functions
		 */

		 /**
			* @brief      run function, to run the program
			* @bug		     No know Bugs
			* @return     Returns a int32
			*/
		int32
		run();

		void
		handleWindowEvent(sf::Event event);

	 private:

		/**
		 * @brief private functions
		 */

		 /**
			* @brief      createWindow function, to create window
			* @bug		     No know Bugs
			* @return     Returns nothing
			*/
		void
	  createWindow();


		/**
		 * @brief      update function, to update the program
		 * @param      deltaTime parameter one, delta time for the program
		 * @bug		     No know Bugs
		 * @return     Returns nothing
		 */
		void
		update(float deltaTime);

		/**
		 * @brief      render function, to render the program
		 * @bug		     No know Bugs
		 * @return     Returns nothing
		 */
		void
		render();

		/**
		 * @brief      intSystems function, to inti systems
		 * @bug		     No know Bugs
		 * @return     Returns nothing
		 */
		void
		initSystems();

		/**
		 * @brief      destroySystems function, to destroy systems
		 * @bug		     No know Bugs
		 * @return     Returns nothing
		 */
		void
		destroySystems();



	 protected:

		/**
		 * @brief protected functions
		 */

		virtual void
		onCreate() {};


    virtual void
    onEvents(sf::Event event) {};

		virtual void
		onUpdate(float) {};

		virtual void
		onRender() {};

		virtual void
		onDestroy() {};


	 protected:

		 //TODO Cambiar al la clase base
     Plugin m_plugin;

		 

	};

}

