#include "xcCamera.h"

namespace xcEngineSDK {

  void 
  Camera::init() {
    
    m_fowarMove = false;
    m_backMove = false;
    m_rigthMove = false;
    m_leftMove = false;
    m_isClicked = false;

    setFront(m_at, m_position);
    setRight(m_up, m_front);
    setUpTrue(m_front, m_rigth);

    createViewMatrix();
    updateViewMatrix();
    updateProyeccion();

  }

  void
  Camera::setPosition(const Vector3& position) {
    m_position = position;
  }

  void
  Camera::setInitialPosition(const VectorI3& initposition) {
    m_initialPosition = initposition;
  }

  void
  Camera::setClicked(bool isClicked) {
    
    m_isClicked = isClicked;
  }


  void 
  Camera::setLookAt(const Vector3& at) {
    m_at = at;
  }

  void 
  Camera::setUp(const Vector3& up) {
    m_up = up;

  }

  void 
  Camera::setFielOfView(float fov) {
    m_fov = fov;
  }

  void 
  Camera::setWidth(float width) {
    m_width = width;
  }

  void 
  Camera::setHeight(float height) {
    m_height = height;
  }

  void 
  Camera::setNear(float _near) {
    m_near = _near;
  }

  void 
  Camera::setfar(float Far) {
    m_far = Far;
  }

  void
  Camera::setFront(Vector3 At, Vector3 Posicion) {

    m_front = Vector3(At - Posicion).normalize();
  }

  void 
  Camera::setRight(Vector3 Up, Vector3 Front) {

    m_rigth = Up.cross(Front).normalize();
  }

  void 
  Camera::setUpTrue(Vector3 Front, Vector3 Right) {

    m_trueUp = Front.cross(Right);
    
  }

  void 
  Camera::setFowarMove(bool pressed) {
    m_fowarMove = pressed;
  }

  void 
  Camera::setBackMove(bool pressed) {
    m_backMove = pressed;
  }

  void 
  Camera::setRigthMove(bool pressed) {
    m_rigthMove = pressed;
  }

  void 
  Camera::setLeftMove(bool pressed) {
    m_leftMove = pressed;
  }


  void 
  Camera::createViewMatrix() {

    /*m_matrixAxis = {
      m_rigth.x, m_trueUp.x, m_front.x, 0,
      m_rigth.y, m_trueUp.y, m_front.y, 0,
      m_rigth.z, m_trueUp.z, m_front.z, 0,
      0, 0, 0, 1
    };

    m_matrixPosition = {
      1, 0, 0, -m_position.x,
      0, 1, 0, -m_position.y,
      0, 0, 1, -m_position.z,
      0, 0, 0, 1
    };

    m_matrixView = m_matrixPosition * m_matrixAxis;*/

    Vector3 Axis[3];
    Vector3 negativePosition = -m_position;

    Axis[2] = m_front;//(m_at - m_position).normalize();  //zaxis
    Axis[0] = m_rigth;//m_up.cross(Axis[2]).normalize();  //xaxis
    Axis[1] = m_trueUp;// Axis[2].cross(Axis[0]).normalize(); //yaxis

    for (size_t i = 0; i < 3; ++i) {
      m_matrixView.m_matrix[0][i] = Axis[i].x;
      m_matrixView.m_matrix[1][i] = Axis[i].y;
      m_matrixView.m_matrix[2][i] = Axis[i].z;
      m_matrixView.m_matrix[3][i] = Axis[i].dot(negativePosition);
    }

    m_matrixView.m_matrix[0][3] = 0.0f;
    m_matrixView.m_matrix[1][3] = 0.0f;
    m_matrixView.m_matrix[2][3] = 0.0f;
    m_matrixView.m_matrix[3][3] = 1.0f;
    
   }

  void 
  Camera::updateProyeccion() {

    m_matrixProyeccion = m_matrixProyeccion.perspectiveFovLH(m_fov,
                                                             m_height, 
                                                             m_width, 
                                                             m_near, 
                                                             m_far);

  }

  void 
  Camera::updateViewMatrix() {
    
    m_rigth = { m_matrixView.m_matrix[0].x,
                m_matrixView.m_matrix[0].y,
                m_matrixView.m_matrix[0].z };

    m_trueUp = { m_matrixView.m_matrix[1].x,
                 m_matrixView.m_matrix[1].y,
                 m_matrixView.m_matrix[1].z };

    m_front = { m_matrixView.m_matrix[2].x,
                m_matrixView.m_matrix[2].y,
                m_matrixView.m_matrix[2].z };
 
    m_at = m_position + m_front;
 
  }

  void 
  Camera::update() {

    if (m_fowarMove) {
      
      m_position += m_front * 0.025f;
      
    }
    else if (m_backMove) {

      m_position -= m_front * 0.025f;

    }
    else if (m_rigthMove) {

      m_position += m_rigth * 0.025f;
    }
    else if (m_leftMove) {

      m_position -= m_rigth * 0.025f;
    }
    else if (m_upMove) {

      m_position += m_trueUp * 0.025f;
    }
    else if (m_downtMove) {

      m_position -= m_trueUp * 0.025f;
    }

    /*m_matrixAxis = {
      m_rigth.x, m_trueUp.x, m_front.x, 0,
      m_rigth.y, m_trueUp.y, m_front.y, 0,
      m_rigth.z, m_trueUp.z, m_front.z, 0,
      0, 0, 0, 1
    };
    
    m_matrixPosition = {
      1, 0, 0, -m_position.x,
      0, 1, 0, -m_position.y,
      0, 0, 1, -m_position.z,
      0, 0, 0, 1
    };
   
    m_matrixView = m_matrixPosition * m_matrixAxis;*/
    createViewMatrix();
    updateViewMatrix();

    return;
  }


  bool 
  Camera::getClicked() {

    return m_isClicked;
  }

  float 
  Camera::getWidth() {

    return m_width;
  }

  float 
  Camera::getHeight() {

    return m_height;
  }

  float 
  Camera::getFar() {

    return m_far;
  }

  float 
  Camera::getFov() {

    return m_fov;
  }

  float 
  Camera::getNear() {

    return m_near;
  }

  Vector3 
  Camera::getPosition() {

    return m_position;
  }

  Vector3 
  Camera::getAt() {

    return m_at;
  }

  Vector3 
  Camera::getUp() {

    return m_up;
  }

  Vector3 
  Camera::getFront() {

    

    return m_front;
  }

  Vector3 
  Camera::getRight() {

    return m_rigth;
  }

  Matrix4x4 
  Camera::getView() {

    return m_matrixView;
  }

  Matrix4x4 
  Camera::getProyeccion() {

    return m_matrixProyeccion;
  }

}