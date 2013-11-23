/**
 * Author      : Dorain Yeager
 * Course      : COMP 322, Advanced Programming 
 * Date        : Sometime before 1 November 2013
 * Description : This file declares the class which will later
 *               create an image from a set of data to resemble
 *               a Fractal.
*/

#ifndef Image_h
#define Image_h

#include <iosfwd>
using std::ostream;

#include <string>
using std::string;

#include "Color.h"

class Image
{
public:
  Image(int, int);
  ~Image();

  int get_xres() const;
  int get_yres() const;

  void set(int x, int y, const Color& c);

  void writeBMP(const string& fname) const;

private:
  static const int BITS_PER_BYTE           = 8;
	static const int MAX_BYTE_VALUE          = 256;
	static const int BMP_HEADER_SIZE         = 54;
	static const int BMP_BYTES_PER_COLOR     = 3;
	static const int BMP_PARTIAL_HEADER_SIZE = 40;
	static const int BMP_NUM_OF_PLANES       = 1;
	static const int BMP_COMPRESSION         = 0;

  void writeLittleEndian(unsigned long int num, ostream& out, int numBytes) const;

  int xres;
  int yres;
  
  Color** pixels;
};

inline int Image::get_xres() const
{
  return xres;
}

inline int Image::get_yres() const
{
  return yres;
}

inline void Image::set(int x, int y, const Color& c)
{
  pixels[y][x] = c;
}

#endif // Image_h
