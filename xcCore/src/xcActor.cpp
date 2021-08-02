#include "xcActor.h"

namespace xcEngineSDK {
    Actor::Actor(String name) {
      m_actorName = name;
    }

    void 
    Actor::addComponent(WeakSptr<Component> component) {
      m_vComponents.push_back(component.lock());
    }

    void 
    Actor::removeComponent(WeakSptr<Component>& component) {
    }

    void
    Actor::setName(String name) {
      m_actorName = name;
    }

    void
    Actor::setSelect(bool selected) {
      m_isSelected = selected;
    }

    void
    Actor::renderComponent() {

      for (auto component : m_vComponents) {
        component->render();
      }

    }

    void 
    Actor::update(const float& deltaTime) {

      for (auto component : m_vComponents) {
        component->update(deltaTime);
      }
    }
}