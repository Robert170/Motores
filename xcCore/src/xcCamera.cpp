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
    m_fowar = false;
    m_back = false;
    m_rigth = false;
    m_left = false;

    setFront(Data.at, Data.position);
    setRight(m_data.up, m_data.front);
    setUpTrue(m_data.front, m_data.rigth);

    createViewMatrix();
    updateViewMatrix();
    updateProyeccion();
  }

  void 
  Camera::init(CameraDatas Data) {

    m_data.position = Data.position;
    m_data.at = Data.at;
    m_data.up = Data.up;
    m_data.fov = Data.fov;
    m_data.width = Data.width;
    m_data.height = Data.height;
    m_data.Near = Data.Near;
    m_data.Far = Data.Far;
    m_fowar = false;
    m_back = false;
    m_rigth = false;
    m_left = false;

    setFront(Data.at, Data.position);
    setRight(m_data.up, m_data.front);
    setUpTrue(m_data.front, m_data.rigth);

    createViewMatrix();
    updateViewMatrix();
    updateProyeccion();

  }

  void
  Camera::setFront(Vector3 At, Vector3 Posicion) {

    m_front = Vector3(At - Posicion).normalize();
    m_data.front = m_front;
  }

  void 
  Camera::setRight(Vector3 Up, Vector3 Front) {

    Vector3 right(Up);
    right = right.cross(Front).normalize();
    //right.normalize();
    m_data.rigth = right;
  }

  void 
  Camera::setUpTrue(Vector3 Front, Vector3 Right) {

    Vector3 trueUp(Front);
    trueUp = trueUp.cross(Right).normalize();
    //trueUp.normalize();
    m_up = trueUp;
  }

  void 
  Camera::input(sf::Event INPUT) {




    if (INPUT.key.code == sf::Keyboard::W &&
        INPUT.type == sf::Event::KeyPressed) {
      
      m_fowar = true;
      
    }
    else if (INPUT.key.code == sf::Keyboard::A &&
             INPUT.type == sf::Event::KeyPressed) {

      m_left = true;
    }
    else if (INPUT.key.code == sf::Keyboard::S &&
             INPUT.type == sf::Event::KeyPressed) {
      
      m_back = true;
      
    }
    else if (INPUT.key.code == sf::Keyboard::D &&
             INPUT.type == sf::Event::KeyPressed) {

      m_rigth = true;
    }
    if (INPUT.key.code == sf::Keyboard::W &&
        INPUT.type == sf::Event::KeyReleased) {
      
      m_fowar = false;
      
    }
    else if (INPUT.key.code == sf::Keyboard::A &&
             INPUT.type == sf::Event::KeyReleased) {

      m_left = false;
    }
    else if (INPUT.key.code == sf::Keyboard::S &&
             INPUT.type == sf::Event::KeyReleased) {
      
      m_back = false;
      
    }
    else if (INPUT.key.code == sf::Keyboard::D &&
             INPUT.type == sf::Event::KeyReleased) {

      m_rigth = false;
    }

  }


  void 
  Camera::createViewMatrix() {

 
    m_view = m_view.lookAtLH(m_data.front, m_data.at, m_data.up);
    //m_axis = {
    //  m_data.rigth.m_x, m_up.m_x, m_data.front.m_x, 0,
    //  m_data.rigth.m_y, m_up.m_y, m_data.front.m_y, 0,
    //  m_data.rigth.m_z, m_up.m_z, m_data.front.m_z, 0,
    //  0, 0, 0, 1
    //};



    ///*m_position = {
    //  1, 0, 0, 0,
    //  0, 1, 0, 0,
    //  0, 0, 1, 0,
    //  -m_data.position.m_x, -m_data.position.m_y , -m_data.position.m_z, 1
    //};*/

    ////m_position *= m_axis;

    //m_view = m_axis * m_position;
  }

  void 
  Camera::updateProyeccion() {

    m_proyeccion = m_proyeccion.perspectiveFovLH(m_data.fov, 
                                                 m_data.height, 
                                                 m_data.width, 
                                                 m_data.Near, 
                                                 m_data.Far);
      
    //m_proyeccion = m_proyeccion.transpose();

  }

  void 
  Camera::updateViewMatrix() {
    
    m_data.rigth = { m_view.m_matrix[0].m_x,  
                     m_view.m_matrix[1].m_x,
                     m_view.m_matrix[2].m_x };

    m_data.up = { m_view.m_matrix[0].m_y,
                  m_view.m_matrix[1].m_y,
                  m_view.m_matrix[2].m_y };

    m_up = m_data.up;
    //Front = { View[2][0],View[2][1],View[2][2] };

    m_data.front = { m_view.m_matrix[0].m_z,
                     m_view.m_matrix[1].m_z,
                     m_view.m_matrix[2].m_z };
 
    m_data.at = getFront() + getPosition();
 
  }

  void 
  Camera::move() {

    if (m_fowar) {
      
      m_data.position += m_data.front * 0.025f;
      
    }
    else if (m_rigth) {

      m_data.position -= m_data.rigth * 0.025f;
    }
    else if (m_back) {
      
      m_data.position -= m_data.front * 0.025f;
      
    }
    else if (m_left) {

      m_data.position += m_data.rigth * 0.025f;
    }

    m_axis = {
      m_data.rigth.m_x, m_up.m_x, m_data.front.m_x, 0,
      m_data.rigth.m_y, m_up.m_y, m_data.front.m_y,0, 
      m_data.rigth.m_z, m_up.m_z, m_data.front.m_z, 0, 
      0, 0, 0, 1
    };
    
    m_position = {
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      -m_data.position.m_x, -m_data.position.m_y, -m_data.position.m_z, 1
    };

    m_position *= m_axis;
    //m_view = m_view.lookAtLH(m_data.position, m_data.at, m_data.up);
    m_view = m_position;
    //updateViewMatrix();

    return;
  }

  float 
  Camera::getWidth() {

    return m_data.width;
  }

  float 
  Camera::getHeight() {

    return m_data.height;
  }

  float 
  Camera::getFar() {

    return m_data.Far;
  }

  float 
  Camera::getFov() {

    return m_data.fov;
  }

  float 
  Camera::getNear() {

    return m_data.Near;
  }

  Vector3 
  Camera::getPosition() {

    return m_data.position;
  }

  Vector3 
  Camera::getAt() {

    return m_data.at;
  }

  Vector3 
  Camera::getUp() {

    return m_data.up;
  }

  Vector3 
  Camera::getFront() {

    return m_data.front;
  }

  Vector3 
  Camera::getRight() {

    return m_data.rigth;
  }

  Matrix4x4 
  Camera::getView() {

    return m_view;
  }

  Matrix4x4 
  Camera::getProyeccion() {

    return m_proyeccion;
  }

}