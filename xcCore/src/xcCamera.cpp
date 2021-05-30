#include "xcCamera.h"

namespace xcEngineSDK {
  
  Camera::Camera(CameraDatas Data) {

    m_data.position = Data.position;
    m_data.at = Data.at;
    m_data.up = Data.up;
    m_data.fov = Data.fov;
    m_data.width = Data.width;
    m_data.height = Data.height;
    m_data.Near = Data.Near;
    m_data.Far = Data.Far;

    setFront(Data.at, Data.position);
    setRight(m_data.up, m_data.front);
    setUpTrue(m_data.front, m_data.rigth);
  }

  void 
  Camera::setFront(Vector3 At, Vector3 Posicion) {
    m_front = Vector3(At - Posicion).normalize();
    m_data.front = m_front;
  }

  void 
  Camera::setRight(Vector3 Up, Vector3 Front) {

    Vector3 right(Up);
    right = right.cross(Front);
    right.normalize();
    m_data.rigth = right;
  }

  void 
  Camera::setUpTrue(Vector3 Front, Vector3 Right) {

    Vector3 trueUp(Front);
    trueUp = trueUp.cross(Right);
    trueUp.normalize();
    m_up = trueUp;
  }
}