
#ifndef __IMAGE__
#define __IMAGE__

#include "cips.h"
#include <iostream>

// Don't modify this class
// This class is responsible for holding header information
class ImageHeader
{
public :
	bmpfileheader BitMapFileHeader;
	ctstruct      BitMapColorMap[GRAY_LEVELS + 1];
	bitmapheader  BitMapHeader;

	int width;
	int height;

public:
	int getwidth(){return width;}
	int getheight(){return height;}
	ImageHeader(char *filename);
	void CreateFileAndSaveHeader(char *filename);
};


// This is the class you should complete
 class Image
 {
 private:
	 // a pointer to pointer to short containing image data usually each pixel range between 0 to 255
	 short ** image;
	 // containing the width of the image (how many pixel per row)
	 int width;
	 // containing the height of the image (how many pixel per column)
	 int height;
	 // an object containing header data
	 ImageHeader imageHeader;
 public :
	 // Constructor that takes  an image path and read its width , height and pixels data into member variables
	 Image(char *filename);
	 // a function that takes the header file info , width , height, pixels data and save it in the path specified by the filename string
	 void SaveImage(char *filename);
	 ~Image();

	 // To be Declared and defined functions 
	 //(to understand the following image functions refer to the videos in your google drive in the following path )
	 // Google Drive\Software Engineering  (CSE321)\Assignments\Assignment 2 Image Class\Helping Videos
	 // TODO: 1- Threshold function that takes an integer and threshold the image above and below that integer
	 
	 // TODO: 2- Average function that computes the average of an image with a box 5*5 and modify the image itselfs

	 // TODO: 3- Median Filter that create and return an image that's the median of the original image convoluted by a 3*3 mask

	 // TODO: 4- Copy Constructor to be able to create an image from another existing image 
	 // that will be needed if any of the functions has a return type of "Image"

	 // TODO: 5- increase brightness that increase the brightness of the image itself

	 // TODO: 6- increase contrast that generates a new image which has a better contrast

 };





#endif
