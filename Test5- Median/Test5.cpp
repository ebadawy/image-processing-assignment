
#include "Image.h"
#include<iostream>


void main()
{
	// Path should be relative to the executable
	Image z("noisyimage.bmp"); // input path image

	Image g;
	g = z.median(); // this function should make an median filter of 3*3 over an image
	// also it should not change z at all , z image should be the same before and after this function
	// g should contain the new image that's the median of the image with a 3*3 mask

	g.SaveImage("medianfilteredimage.bmp");

}