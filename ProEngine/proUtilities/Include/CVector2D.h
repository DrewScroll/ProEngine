/**
* @file   CVector2d.h
* @author Daniel Velasco and Andres Gonzalez
* @date   2018/05/30
* @brief  Functions for Vector use in 2D
*
* Functions to compute Vectors in a 2D environment applied with Mathematics.
*/

#pragma once

/**
* Includes
*/
#include "proMath.h"

namespace proEngine {
  class CVector2D {
  public:
    CVector2D();
    ~CVector2D();
    CVector2D(float fx, float fy);
    CVector2D(const CVector2D& v);
    float magnitud();
    CVector2D normalize();
    float dotProduct(const CVector2D& v);

    CVector2D& operator = (const CVector2D& v);    
    CVector2D operator + (const CVector2D& v) const;
    CVector2D& operator +=(const CVector2D& v);
    CVector2D operator - (const CVector2D& v) const;
    CVector2D& operator -=(const CVector2D& v);
    CVector2D operator *(float f) const;
    CVector2D& operator *= (float f);
    CVector2D operator / (float f) const;
    CVector2D& operator /= (float f);

    float m_x;
    float m_y;
  };
}
