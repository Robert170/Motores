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
  Camera::event(sf::Event INPUT) {

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

      m_rigthMove = true;
    }
    else if (INPUT.key.code == sf::Keyboard::Q &&
             INPUT.type == sf::Event::KeyPressed) {

      m_upMove = true;
    }
    else if (INPUT.key.code == sf::Keyboard::E &&
             INPUT.type == sf::Event::KeyPressed) {

      m_downtMove = true;
    }
    else if (INPUT.key.code == sf::Keyboard::W &&
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

      m_rigthMove = false;
    }
    else if (INPUT.key.code == sf::Keyboard::Q &&
             INPUT.type == sf::Event::KeyReleased) {

      m_upMove = false;
    }
    else if (INPUT.key.code == sf::Keyboard::E &&
             INPUT.type == sf::Event::KeyReleased) {

      m_downtMove = false;
    }
    if (INPUT.type == sf::Event::MouseButtonPressed) {

      if (INPUT.mouseButton.button == sf::Mouse::Left) {
        setInitialPosition({INPUT.mouseButton.x,
                            INPUT.mouseButton.y,
                            0 });
        setClicked(true);
      }
    }
    if (INPUT.type == sf::Event::MouseButtonReleased) {

      if (INPUT.mouseButton.button == sf::Mouse::Left) {
        setClicked(false);
      }
    }
    if (INPUT.type == sf::Event::MouseMoved) {
      
    }
    

  }


  void 
  Camera::createViewMatrix() {

    m_matrixAxis = {
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
   
    m_matrixView = m_matrixPosition * m_matrixAxis;
    
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

    m_matrixAxis = {
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

    //m_matrixPosition *= m_matrixAxis;
   
    m_matrixView = m_matrixPosition * m_matrixAxis;
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