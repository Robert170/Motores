#include "xcActor.h"

namespace xcEngineSDK {
    Actor::Actor(String name) {
      m_actorName = name;
    }

    void 
    Actor::addComponent(Component& component) {
      m_vComponents.push_back(component);
    }

    void
    Actor::setName(String name) {
      m_actorName = name;
    }

    void
    Actor::setSelect(bool selected) {
      m_isSelected = selected;
    }
}