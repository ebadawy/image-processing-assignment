
#include "Image.h"
#include<iostream>


void main()
{
	// Path should be relative to the executable
	Image z("BrokenLines.bmp"); // input path image

	z.average();
	z.thresh(190);
	z.SaveImage("FixedBroken.bmp");

}