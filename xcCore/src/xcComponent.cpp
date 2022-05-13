#include "xcComponent.h"

namespace xcEngineSDK {
    void 
    Component::setID(COMPONENT_ID::E id) {
      m_ID = id;
    }

    COMPONENT_ID::E 
    Component::getID() {
      return m_ID;
    }
}