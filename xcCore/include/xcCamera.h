/*****************************************************************************/
/**
 * @file    xcCamera.h
 * @author  Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/03/18
 * @brief   Camera of the graphi api
 *
 * This class has the functions to have a camera, that can move in the scene
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/

#pragma once
#include <windows.h>
#include <xcVector3.h>
#include <xcMatrix4x4.h>
#include "xcPrerequisitesCore.h"
#include "xcConstantBuffer.h"

namespace xcEngineSDK {


  class XC_CORE_EXPORT Camera
  {
   public:
    Camera() = default;


    ~Camera() = default;

    void
    init();

    void
    setPosition(const Vector3& position);

    void
    setLookAt(const Vector3& at);

    void
    setUp(const Vector3& up);

    void
    setFielOfView(float fov);

    void
    setWidth(float width);

    void
    setHeight(float height);

    void
    setNear(float _near);

    void
    setfar(float Far);

    void
    setFront(Vector3 At, Vector3 Posicion);

    void
    setRight(Vector3 Up, Vector3 Front);

    void
    setUpTrue(Vector3 Front, Vector3 Right);

    void
    rotation(WPARAM RotX);

    void
    input(sf::Event INPUT);

    void
    moveMouse(Vector3 Dir);

    void
    rotMouse(Vector3 Dir);

    void
    rotMouseX(Vector3 Dir);

    void
    rotMouseY(Vector3 Dir);

    void
    createViewMatrix();

    void
    updateProyeccion();
    
    void
    updateViewMatrix();

    void
    move();

    float
    getWidth();

    float
    getHeight();

    float
    getFar();

    float
    getFov();

    float
    getNear();

    Vector3
    getPosition();

    Vector3
    getAt();

    Vector3
    getUp();

    Vector3
    getFront();

    Vector3
    getRight();

    Matrix4x4
    getView();

    Matrix4x4
    getProyeccion();

   public:

    bool Fpres = false;

    bool RotF = false;

    bool m_fowarMove;

    bool m_backMove;

    bool m_rigthMove;

    bool m_leftMove;

    int32 m_limitPitchU = 0;

    int32 m_limitPitchD = 0;

    int32 m_limitRollU = 0;

    int32 m_limitRollD = 0;

    float m_movementSpeed = 2.5F;

    Vector3 m_trueUp;


    Vector3 m_posIn;

    Vector3 m_posFn;

    Vector3 m_dir;

    Matrix4x4 m_matrixProyeccion;

    Matrix4x4 m_matrixAxis;

    Matrix4x4 m_matrixPosition;

    Matrix4x4 m_matrixView;

    ConstantBuffer m_pCBNeverChanges;

    ConstantBuffer m_pCBChangeOnResize;

    ConstantBuffer m_pCBChangesEveryFrame;

    //Camera datas

    Vector3 m_front; //

    Vector3 m_position; //

    Vector3 m_at;//

    Vector3 m_up;//

    Vector3 m_rigth;//

    float m_width;//

    float m_height;//

    float m_near;

    float m_far;

    float m_fov;//

  };
}

