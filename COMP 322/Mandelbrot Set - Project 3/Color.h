/**
 * Author      : Dorian Yeager
 * Course      : COMP 322, Advanced Programming 
 * Date        : Sometime before 1 November 2013
 * Description : This file declares and defines the Color
 *               class which is used to generate each of 
 *               pixels for the Fractal generator.
*/


#ifndef Color_h
#define Color_h

class Color
{
public:
  Color(float r, float g, float b);
  Color();

  float operator[](int idx);

private:
  float e[3];
};

inline Color::Color(float r, float g, float b)
{
  e[0] = r;
  e[1] = g;
  e[2] = b;
}

inline Color::Color()
{
  e[0] = 0.f;
  e[1] = 0.f;
  e[2] = 0.f;
}

inline float Color::operator[](int idx)
{
  return e[idx];
}

#endif // Color_h
