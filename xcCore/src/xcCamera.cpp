#include "xcCamera.h"

namespace xcEngineSDK {

  void 
  Camera::init() {
    


    m_fowarMove = false;
    m_backMove = false;
    m_rigthMove = false;
    m_leftMove = false;

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
    m_front = m_front;
  }

  void 
  Camera::setRight(Vector3 Up, Vector3 Front) {

    Vector3 right(Up);
    right = right.cross(Front).normalize();
    //right.normalize();
    m_rigth = right;
  }

  void 
  Camera::setUpTrue(Vector3 Front, Vector3 Right) {

    Vector3 trueUp(Front);
    trueUp = trueUp.cross(Right).normalize();
    //trueUp.normalize();
    m_trueUp = trueUp;
  }

  void 
  Camera::input(sf::Event INPUT) {




    if (INPUT.key.code == sf::Keyboard::W &&
        INPUT.type == sf::Event::KeyPressed) {
      
      m_fowarMove = true;
      
    }
    else if (INPUT.key.code == sf::Keyboard::A &&
             INPUT.type == sf::Event::KeyPressed) {

      m_leftMove = true;
    }
    else if (INPUT.key.code == sf::Keyboard::S &&
             INPUT.type == sf::Event::KeyPressed) {
      
      m_backMove = true;
      
    }
    else if (INPUT.key.code == sf::Keyboard::D &&
             INPUT.type == sf::Event::KeyPressed) {

      m_rigth = true;
    }
    if (INPUT.key.code == sf::Keyboard::W &&
        INPUT.type == sf::Event::KeyReleased) {
      
      m_fowarMove = false;
      
    }
    else if (INPUT.key.code == sf::Keyboard::A &&
             INPUT.type == sf::Event::KeyReleased) {

      m_leftMove = false;
    }
    else if (INPUT.key.code == sf::Keyboard::S &&
             INPUT.type == sf::Event::KeyReleased) {
      
      m_backMove = false;
      
    }
    else if (INPUT.key.code == sf::Keyboard::D &&
             INPUT.type == sf::Event::KeyReleased) {

      m_rigth = false;
    }

  }


  void 
  Camera::createViewMatrix() {

 
    m_matrixView = m_matrixView.lookAtLH(m_front, m_at, m_up);
    //m_axis = {
    //  m_rigth.x, m_up.x, m_front.x, 0,
    //  m_rigth.y, m_up.y, m_front.y, 0,
    //  m_rigth.z, m_up.z, m_front.z, 0,
    //  0, 0, 0, 1
    //};



    ///*m_position = {
    //  1, 0, 0, 0,
    //  0, 1, 0, 0,
    //  0, 0, 1, 0,
    //  -m_position.x, -m_position.y , -m_position.z, 1
    //};*/

    ////m_position *= m_axis;

    //m_view = m_axis * m_position;
  }

  void 
  Camera::updateProyeccion() {

    m_matrixProyeccion = m_matrixProyeccion.perspectiveFovLH(m_fov,
                                                             m_height, 
                                                             m_width, 
                                                             m_near, 
                                                             m_far);
      
    //m_proyeccion = m_proyeccion.transpose();

  }

  void 
  Camera::updateViewMatrix() {
    
    m_rigth = { m_matrixView.m_matrix[0].x,
                m_matrixView.m_matrix[1].x,
                m_matrixView.m_matrix[2].x };

    m_up = { m_matrixView.m_matrix[0].y,
             m_matrixView.m_matrix[1].y,
             m_matrixView.m_matrix[2].y };

    m_trueUp = m_up;
    //Front = { View[2][0],View[2][1],View[2][2] };

    m_front = { m_matrixView.m_matrix[0].z,
                m_matrixView.m_matrix[1].z,
                m_matrixView.m_matrix[2].z };
 
    m_at = getFront() + getPosition();
 
  }

  void 
  Camera::move() {

    if (m_fowarMove) {
      
      m_position += m_front * 0.025f;
      
    }
    else if (m_rigthMove) {

      m_position -= m_rigth * 0.025f;
    }
    else if (m_backMove) {
      
      m_position -= m_front * 0.025f;
      
    }
    else if (m_leftMove) {

      m_position += m_rigth * 0.025f;
    }

    m_matrixAxis = {
      m_rigth.x, m_trueUp.x, m_front.x, 0,
      m_rigth.y, m_trueUp.y, m_front.y, 0,
      m_rigth.z, m_trueUp.z, m_front.z, 0,
      0, 0, 0, 1
    };
    
    m_matrixProyeccion = {
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      -m_position.x, -m_position.y, -m_position.z, 1
    };

    m_matrixProyeccion *= m_matrixAxis;
    //m_view = m_view.lookAtLH(m_position, m_at, m_up);
    m_matrixView = m_matrixProyeccion;
    //updateViewMatrix();

    return;
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