#pragma once

#include <xcModule.h>
#include <xcPrerequisitesCore.h>
namespace xcEngineSDK {

	class BaseSound : public Module<BaseSound>
	{
	 public:
		BaseSound() = default;
		~BaseSound() = default;

	 private:
    FORCEINLINE void
      setObject(BaseSound* input) {
			BaseSound::_instance() = input;
    }

	};

	/**
	 * @brief export the instance
	 */
	XC_CORE_EXPORT BaseSound&
  g_sound();

	/**
	 * @Variable funProtoGraphiAPI, instance of the class
	 */
	using funProtoSound = BaseSound * (*)();

}