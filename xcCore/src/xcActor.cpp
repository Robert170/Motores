#include "xcActor.h"
#include "xcStaticMesh.h"
#include "xcBaseRenderer.h"
namespace xcEngineSDK {
    Actor::Actor(String name) {
      m_actorName = name;
      m_actorPosition = Vector3(-5.0f,10.0f,0.0f);
      m_actorRotation = Vector3::ZERO;
      m_actorScale = Vector3(0.5f, 0.5f, 0.5f);
      m_actorTrasform = Matrix4x4::IDENTITY_MATRIX;

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

      g_renderer().setActorTransformCB(m_actorTrasform);
      for (auto component : m_vComponents) {
        component->render();
      }

    }

    void 
    Actor::update(const float& deltaTime) {
      
      m_actorTrasform = Matrix4x4::IDENTITY_MATRIX;

      //Scale
      m_actorTrasform.m_matrix[0].x = m_actorScale.x;
      m_actorTrasform.m_matrix[1].y = m_actorScale.y;
      m_actorTrasform.m_matrix[2].z = m_actorScale.z;

      //Position
      m_actorTrasform.m_matrix[3].x = m_actorPosition.x;
      m_actorTrasform.m_matrix[3].y = m_actorPosition.y;
      m_actorTrasform.m_matrix[3].z = m_actorPosition.z;

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

    /*Vector3& 
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
    }*/
}