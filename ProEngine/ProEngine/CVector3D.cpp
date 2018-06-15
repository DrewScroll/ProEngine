#include "CVector3D.h"

proEngine::CVector3D::CVector3D() {}

proEngine::CVector3D::~CVector3D() {}

proEngine::CVector3D::CVector3D(float fx, float fy, float fz) {
  m_x = fx;
  m_y = fy;
  m_z = fz;
}

proEngine::CVector3D::CVector3D(const CVector3D & v) {
  m_x = v.m_x;
  m_y = v.m_y;
  m_z = v.m_z;
}

float proEngine::CVector3D::magnitud() {
  return sqrt((m_x*m_x) + (m_y*m_y) + (m_z*m_z));
}

proEngine::CVector3D proEngine::CVector3D::normalize() {
  CVector3D Res;
  float mag = magnitud();
  if (mag == 0) {
    return Res;
  }
  Res.m_x = m_x / mag;
  Res.m_y = m_y / mag;
  Res.m_z = m_z / mag;
  return Res;
}

float proEngine::CVector3D::dotProduct(const CVector3D & v) {
  return (m_x*v.m_x) + (m_y*v.m_y) + (m_z*m_z);
}

proEngine::CVector3D & proEngine::CVector3D::operator=(const CVector3D & v) {
  m_x = v.m_x;
  m_y = v.m_y;
  m_z = v.m_z;
  return *this;
}

proEngine::CVector3D proEngine::CVector3D::operator+(const CVector3D & v) const {
  CVector3D Res;
  Res.m_x = m_x + v.m_x;
  Res.m_y = m_y + v.m_y;
  Res.m_z = m_z + v.m_z;
  return Res;
}

proEngine::CVector3D & proEngine::CVector3D::operator+=(const CVector3D & v) {
  m_x = m_x + v.m_x;
  m_y = m_y + v.m_y;
  m_z = m_z + v.m_z;
  return *this;
}

proEngine::CVector3D proEngine::CVector3D::operator-(const CVector3D & v) const {
  CVector3D Res;
  Res.m_x = m_x - v.m_x;
  Res.m_y = m_y - v.m_y;
  Res.m_z = m_z - v.m_z;
  return Res;
}

proEngine::CVector3D & proEngine::CVector3D::operator-=(const CVector3D & v) {
  m_x = m_x - v.m_x;
  m_y = m_y - v.m_y;
  m_z = m_z - v.m_z;
  return *this;
}

proEngine::CVector3D proEngine::CVector3D::operator*(float f) const {
  CVector3D Res;
  Res.m_x = m_x * f;
  Res.m_y = m_y * f;
  Res.m_z = m_z * f;
  return Res;
}

proEngine::CVector3D & proEngine::CVector3D::operator*=(float f) {
  m_x = m_x * f;
  m_y = m_y * f;
  m_z = m_z * f;
  return *this;
}

proEngine::CVector3D proEngine::CVector3D::operator/(float f) const {
  CVector3D Res;
  Res.m_x = m_x / f;
  Res.m_y = m_y / f;
  Res.m_z = m_z / f;
  return Res;
}

proEngine::CVector3D & proEngine::CVector3D::operator/=(float f) {
  m_x = m_x / f;
  m_y = m_y / f;
  m_z = m_z / f;
  return *this;
}


