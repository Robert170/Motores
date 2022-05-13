#include "xcActor.h"
#include "xcStaticMesh.h"
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

    void 
    Actor::getModels(Vector<SPtr<Model>>& model) {

      for (auto component : m_vComponents) {

        if (component->getID() == COMPONENT_ID::kModel) {

          StaticMesh* temp =
          reinterpret_cast<StaticMesh*>(component.get());


          model.push_back(temp->getModel());

        }
      }
    }

    Vector3& 
    Actor::getTraslation() {

      return m_actorTrasform.getTraslation();
    }
    Quaternion& 
    Actor::getRotation() {

      return m_actorTrasform.getRotation();
    }
    Vector3& 
    Actor::getScale() {

      return m_actorTrasform.getScale();
    }
}