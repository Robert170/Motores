#include "xcBaseOmvniverse.h"

namespace xcEngineSDK {
	XC_CORE_EXPORT BaseOmvniverse& g_omvniverse()
	{
		return BaseOmvniverse::instance();
	}
}
