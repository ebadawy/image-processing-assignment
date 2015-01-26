
#include "Image.h"
#include<iostream>


void main()
{
	// Path should be relative to the executable
	Image z("rice.bmp"); // input path image

	z.thresh(120); // this function should threshold the image z with 120
	// z should be changed through the thresh function

	z.SaveImage("ricethresh120.bmp");

}