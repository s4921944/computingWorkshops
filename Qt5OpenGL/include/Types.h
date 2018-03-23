#ifndef TYPES_H_
#define TYPES_H_

struct Vec3
{

  Vec3() = default;
  Vec3( float _x, float _y, float _z );
  Vec3( const Vec3 & ) = default;

  Vec3 operator +(const Vec3 &_v) const;
  void operator +=(const Vec3 &_v);
  Vec3 operator *(float _i) const;

  void scale() const;
  void translate() const;
  void colour() const;

  float m_x = 0.0f;
  float m_y = 0.0f;
  float m_z = 0.0f;

};

struct Cube
{

  Vec3 m_pos    = {0, 0, 0};
  Vec3 m_scale  = {0.05f, 0.05f, 0.05f};
  Vec3 m_colour = {1, 1, 1};
  Vec3 m_dir;

};

#endif
