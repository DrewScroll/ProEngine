#pragma once
#include "proMath.h"
namespace proEngine {
  class CVector3D
  {
  public:
    CVector3D();
    ~CVector3D();
    CVector3D(float fx, float fy, float fz);
    CVector3D(const CVector3D& v);
    float magnitud();
    CVector3D normalize();
    float dotProduct(const CVector3D& v);

    CVector3D& operator = (const CVector3D& v);
    CVector3D operator + (const CVector3D& v) const;
    CVector3D& operator +=(const CVector3D& v);
    CVector3D operator - (const CVector3D& v) const;
    CVector3D& operator -=(const CVector3D& v);
    CVector3D operator *(float f) const;
    CVector3D& operator *= (float f);
    CVector3D operator / (float f) const;
    CVector3D& operator /= (float f);

    float m_x;
    float m_y;
    float m_z;
  };
}
