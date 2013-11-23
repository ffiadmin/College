/**
 * Author      : Dorain Yeager
 * Course      : COMP 322, Advanced Programming 
 * Date        : Sometime before 1 November 2013
 * Description : This file defines the class which will later
 *               create an image from a set of data to resemble
 *               a Fractal.
*/

#include <fstream>
using std::ofstream;

#include <iostream>
using std::ios;
using std::cerr;
using std::endl;

#include "Image.h"

Image::Image(int xres_, int yres_) :
  xres(xres_), yres(yres_)
{
  pixels = new Color*[yres];
  Color* p = new Color[xres*yres];
  for (int i = 0; i < yres; ++i)
    pixels[i] = p + i*xres;
}

Image::~Image()
{
  delete [] pixels[0];
  delete [] pixels;
}

void Image::writeBMP(const string& fname) const
{
	ofstream out(fname.c_str(), ios::binary);
	if (out.fail())
	{
		cerr << "Failed to open \"" << fname << "\" for writing" << endl;
		return;
	}

	// Write BMP header
	char* data = new char[3];

  data[0] = 'B';
	data[1] = 'M';
	out.write(data, 2);

  unsigned long int picDataSize = xres*yres*static_cast<unsigned long int>(BMP_BYTES_PER_COLOR);
	int widthSpacer = (4 - ((xres * BMP_BYTES_PER_COLOR) % 4)) % 4;
	picDataSize += widthSpacer * yres;

  unsigned long int fileSize = BMP_HEADER_SIZE + picDataSize;

	writeLittleEndian(fileSize, out, 4);
	writeLittleEndian(0, out, 4);
	writeLittleEndian(BMP_HEADER_SIZE, out, 4);
	writeLittleEndian(BMP_PARTIAL_HEADER_SIZE, out, 4);
	writeLittleEndian(xres, out, 4);
	writeLittleEndian(yres, out, 4);
	writeLittleEndian(BMP_NUM_OF_PLANES, out, 2);
	writeLittleEndian(BMP_BYTES_PER_COLOR * BITS_PER_BYTE, out, 2);
	writeLittleEndian(BMP_COMPRESSION, out, 4);
	writeLittleEndian(picDataSize, out, 4);
	writeLittleEndian(0, out, 16);

	// Write pixel data
	float temp;
	Color color;
	for (int i = 0; i < yres; ++i)
	{
		for (int j = 0; j < xres; ++j)
		{
			color = pixels[i][j];
			
      temp = color[2] * MAX_BYTE_VALUE;
			data[0] = static_cast<char>((temp > 255.f) ? 255 : ((temp < 0.f) ? 0 : temp));

			temp = color[1] * MAX_BYTE_VALUE;
			data[1] = static_cast<char>((temp > 255.f) ? 255 : ((temp < 0.f) ? 0 : temp));
			
      temp = color[0] * MAX_BYTE_VALUE;
			data[2] = static_cast<char>((temp > 255.f) ? 255 : ((temp < 0.f) ? 0 : temp));
			
      out.write(data, 3);
		}

		// Pad so that that rows are always in increments of four bytes
		for (int i = 0; i < widthSpacer; ++i)
		{
			data[0] = static_cast<char>(0);
			out.write(data, 1);
		}
	}

	delete [] data;
	
  out.close();
}

void Image::writeLittleEndian(unsigned long int num, ostream& out, int numBytes) const
{
	char *data = new char[numBytes];

	for (int i = 0; i < numBytes; ++i)
	{
		data[i] = static_cast<char>(num % MAX_BYTE_VALUE);
		num /= MAX_BYTE_VALUE;
	}

	out.write(data, numBytes);

	delete [] data;
}
