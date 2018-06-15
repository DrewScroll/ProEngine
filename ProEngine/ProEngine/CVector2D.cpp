#include "CVector2D.h"

proEngine::CVector2D::CVector2D() {}

proEngine::CVector2D::~CVector2D() {}

proEngine::CVector2D::CVector2D(float fx, float fy) {
  m_x = fx;
  m_y = fy;
}

proEngine::CVector2D::CVector2D(const CVector2D & v) {
  m_x = v.m_x;
  m_y = v.m_y;
}

float proEngine::CVector2D::magnitud() {
  return sqrt((m_x*m_x)+(m_y*m_y));
}

proEngine::CVector2D proEngine::CVector2D::normalize() {
  CVector2D Res;
  float mag = magnitud();
  if (mag == 0) {
    return Res;
  }
  Res.m_x = m_x / mag;
  Res.m_y = m_y / mag;
  return Res;
}

float proEngine::CVector2D::dotProduct(const CVector2D & v) {
  return (m_x*v.m_x) + (m_y*v.m_y);
}

proEngine::CVector2D & proEngine::CVector2D::operator=(const CVector2D & v) {
  m_x = v.m_x;
  m_y = v.m_y;
  return *this;
}

proEngine::CVector2D proEngine::CVector2D::operator+(const CVector2D & v) const {
  CVector2D Res;
  Res.m_x = m_x + v.m_x;
  Res.m_y = m_y + v.m_y;
  return Res;
}

proEngine::CVector2D & proEngine::CVector2D::operator+=(const CVector2D & v) {
  m_x = m_x + v.m_x;
  m_y = m_y + v.m_y;
  return *this;
}

proEngine::CVector2D proEngine::CVector2D::operator-(const CVector2D & v) const {
  CVector2D Res;
  Res.m_x = m_x - v.m_x;
  Res.m_y = m_y - v.m_y;
  return Res;
}

proEngine::CVector2D & proEngine::CVector2D::operator-=(const CVector2D & v) {
  m_x = m_x - v.m_x;
  m_y = m_y - v.m_y;
  return *this;
}

proEngine::CVector2D proEngine::CVector2D::operator*(float f) const {
  CVector2D Res;
  Res.m_x = m_x * f;
  Res.m_y = m_y * f;
  return Res;
}

proEngine::CVector2D & proEngine::CVector2D::operator*=(float f) {
  m_x = m_x * f;
  m_y = m_y * f;
  return *this;
}

proEngine::CVector2D proEngine::CVector2D::operator/(float f) const {
  CVector2D Res;
  Res.m_x = m_x / f;
  Res.m_y = m_y / f;
  return Res;
}

proEngine::CVector2D & proEngine::CVector2D::operator/=(float f) {
  m_x = m_x / f;
  m_y = m_y / f;
  return *this;
}
