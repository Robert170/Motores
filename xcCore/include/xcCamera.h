/*****************************************************************************/
/**
 * @file    xcCamera.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/03/18
 * @brief   Camera of the graphi api
 *
 * This class has the functions to have a camera, that can move in the scene
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/

#pragma once
#include <xcVector3.h>
#include <xcMatrix4x4.h>
#include "xcPrerequisitesCore.h"
#include "xcConstantBuffer.h"

namespace xcEngineSDK {

  struct CameraDatas
  {
    
    Vector3 front;

    Vector3 position;

    Vector3 at;

    Vector3 up;

    Vector3 rigth;

    float width;

    float height;

    float Near;

    float Far;

    float fov;

  };

  class Camera
  {
   public:
    Camera() = default;

    Camera(CameraDatas Data);

    ~Camera() = default;

    void
    setFront(Vector3 At, Vector3 Posicion);

    void
    setRight(Vector3 Up, Vector3 Front);

    void
    setUpTrue(Vector3 Front, Vector3 Right);

    void
    rotation(WPARAM RotX);

    void
    input(WPARAM INPUT);

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

    uint32
    init(CameraDatas D);

    int32
    updateViewMatrix();

    int32
    move(WPARAM Traslation);

    float
    getWeight();

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

    int32 m_limitPitchU = 0;

    int32 m_limitPitchD = 0;

    int32 m_limitRollU = 0;

    int32 m_limitRollD = 0;

    float m_movementSpeed = 2.5F;

    CameraDatas m_data;

    Vector3 m_up;

    Vector3 m_front;

    Vector3 m_posIn;

    Vector3 m_posFn;

    Vector3 m_dir;

    Matrix4x4 m_proyeccion;

    Matrix4x4 m_axis;

    Matrix4x4 m_position;

    Matrix4x4 m_view;

    ConstantBuffer m_pCBNeverChanges;

    ConstantBuffer m_pCBChangeOnResize;

    ConstantBuffer m_pCBChangesEveryFrame;

  };
}

