/**
 * An example program that creates a 24-bit bitmap file that is 800 x 600 and makes a blue/red checkerboard pattern.
 * Uses EasyBMP
 *
 * Cory Boatright
 * University of Pennsylvania, Fall 2011
 **/

#include "EasyBMP.h"
#include "glm\glm.hpp"
using namespace glm;

using namespace std;
#include "Ray.h"

int main(int argc, char** argv) {
	unsigned int width = 800;
	unsigned int height = 600;
	float aspect = ((float)width)/height;
	float fovy = 90.0f * 3.1415926535/180;
	float phi = fovy/2;
	vec4 up = vec4(0,1,0,0);
	vec4 u = vec4(-1,0,0,0);

	vec4 v = up * tan(phi);
	vec4 h = -u * tan(phi) * aspect;

	vec4 m = vec4(0,0,-1,1);
	vec4 e = vec4(0,0,0,1);

	BMP output;
	output.SetSize(width, height);
	output.SetBitDepth(24);


	
	for(unsigned int x = 0; x < width; x++) {
		for(unsigned int y = 0; y < height; y++) {
			Ray ray;
			vec4 p = m + (2 * (float)x/(width-1)-1)*h + (2 * (float)y/(height-1)-1) * v;
			ray.origin = e;
			ray.direction = (p-e)/length(p-e);

			output(x, y)->Red = abs(ray.direction.x)*255;
			output(x, y)->Green = abs(ray.direction.y)*255;
			output(x, y)->Blue = abs(ray.direction.z)*255;


			/*if(x % 40 == 0) {
				if(y % 40 == 0) {
					output(x, y)->Red = 255;
					output(x, y)->Blue = 0;
					output(x, y)->Green = 0;
				}
				else {
					output(x, y)->Red = 0;
					output(x, y)->Blue = 255;
					output(x, y)->Green = 0;
				}
			}
			else {
				if(y % 40 == 0) {
					output(x, y)->Red = 0;
					output(x, y)->Blue = 255;
					output(x, y)->Green = 0;
				}
				else {
					output(x, y)->Red = 255;
					output(x, y)->Blue = 0;
					output(x, y)->Green = 0;
				}
			}*/
		}
	}

	output.WriteToFile("output.bmp");
	return 0;
}