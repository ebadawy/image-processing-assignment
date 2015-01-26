
#include "Image.h"
#include<iostream>


void main()
{
	// Path should be relative to the executable
	Image z("BrokenLines.bmp"); // input path image

	z.average(); // this function should make an average filter of 5*5 over an image
	// z should be changed through the thresh function
	// z should contain the average of z by 5*5 mask
	// take care that you need to make a copy of the data before you get the average as you are averaging the original image 
	// so each element in the output image is the average of the 5*5 window in the input image
	// so make sure you're not taking the average of the average 

	z.SaveImage("ConnectedLines.bmp");

}