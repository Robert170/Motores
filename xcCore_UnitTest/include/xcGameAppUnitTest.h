#pragma once
#include <xcBaseApp.h>
#include <xcPrerequisitesCore.h>

namespace xcEngineSDK {

	class GameAppUnitTest : public BaseApp
	{
	 public:
		GameAppUnitTest() = default;
		~GameAppUnitTest() = default;

	 public:

		/**
		 * @brief public functions
		 */

	  void
		onCreate() override;

		void
    onUpdate(float deltaTime) override;
   
		void
    onRender() override;

		void
    onDestroy() override;

	 private:


	};

}