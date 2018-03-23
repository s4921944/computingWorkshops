#include "Types.h"
#include <GL/gl.h>

Vec3::Vec3( float _x, float _y, float _z ) :
  m_x( _x ), m_y( _y ), m_z( _z ) {}

void Vec3::scale() const
{

  glScalef( m_x, m_y, m_z );

}

void Vec3::translate() const
{

  glTranslatef( m_x, m_y, m_z );

}

void Vec3::colour() const
{

  glColor3f( m_x, m_y, m_z );

}


Vec3 Vec3::operator+(const Vec3 &_v) const
{

  return Vec3(m_x + _v.m_x,
              m_y + _v.m_y,
              m_z + _v.m_z);

}

void Vec3::operator+=(const Vec3 &_v)
{

  m_x += _v.m_x;
  m_y += _v.m_y;
  m_z += _v.m_z;

}

Vec3 Vec3::operator*(float _i) const
{

  return Vec3(m_x * _i,
              m_y * _i,
              m_z * _i);

}

