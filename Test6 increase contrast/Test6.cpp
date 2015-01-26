
#include "Image.h"
#include<iostream>


void main()
{
	// Path should be relative to the executable
	Image z("lowcontrast.bmp"); // input path image

	Image g = z.increasecontrast(); // this function should make an increase the contrast by a constant factor of your choice in the range of 0.1 -> 0.3
	// also it should not change z at all , z image should be the same before and after this function
	// g should contain the new image that's the median of the image with a 3*3 mask

	g.SaveImage("highcontrast.bmp");

}