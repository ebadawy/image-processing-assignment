
#include "Image.h"
#include<iostream>


void main()
{
	// Path should be relative to the executable
	Image z("cameraman.bmp"); // input path image

	z.increasebrightness(); // this function should increase the brightness of an image by a constant factor of your choice
	// also it will change z
	// after this function z should contain the new image of the higher brightness

	z.SaveImage("cameramanhigherbrightness.bmp");

}