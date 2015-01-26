#include "Image.h"

// Constructor that reads an image file from your disk
Image::Image(char *filename)
	// Calling the Constructor for the imageHeader
	:imageHeader(filename)
{
	
	width = imageHeader.getwidth();
	height = imageHeader.getheight();
	image = new short*[height];
	// this must be allocated in the constructor 
	for(int i=0;i<height;i++)
	{
		image[i] = new short[width];
	}
	read_bmp_image(filename,image);
	
}

Image::~Image()
{
	for(int i = 0;i<height;i++)
	{
		delete image[i];
	}
	delete[] image;
}



void Image::SaveImage(char *filename)
{
	imageHeader.CreateFileAndSaveHeader(filename);
	write_bmp_image(filename,image);
}

ImageHeader::ImageHeader(char *filename)
{
	// Don't Modify this function
	read_bmp_file_header(filename,&BitMapFileHeader);
	read_bm_header(filename,&BitMapHeader);
	read_color_table(filename,BitMapColorMap,BitMapHeader.colorsused);
	height = BitMapHeader.height;
	width = BitMapHeader.width;
}

void ImageHeader::CreateFileAndSaveHeader(char *filename)
{
	create_allocate_bmp_file(filename,&BitMapFileHeader,&BitMapHeader);
}
