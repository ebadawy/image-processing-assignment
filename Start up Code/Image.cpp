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
void Image::thresh(int thersh_line)
{
	for (int i=0;i<height;i++)
	{
		for (int j=0;j<width;j++)
		{
			if (image[i][j] > thersh_line) 
				image[i][j] = 255;
			else
				image[i][j] = 0;
		}
	}
}
void Image:: increasebrightness()
{
	for (int i=0;i<height;i++)
		{
			for (int j=0;j<width;j++)
			{
				if (image[i][j]+30 > 255) 
					image[i][j] = 255;
				else
					image[i][j] = image[i][j]+30;
			}
		}
}
void Image:: average()
{
	short ** tempimage;
	tempimage = new short* [height];
	for(int i=0;i<height;i++)
	{
		tempimage[i] = new short[width];
	}

	for (int i=0;i<height;i++)
		{
			for (int j=0;j<width;j++)
				{
					int sum =0;
					int count=0;
					for (int dx=-2;dx<=2;dx++)
					{
						for (int dy=-2;dy<=2;dy++)
						{
							
							if (i+dx>0 && i+dx<height && j+dy>0 && j+dy<width)
							{
								sum += image[i+dx][j+dy];
								count++;
							}
							else 
							{
								sum += 255;
								count++;
								
							}
						}
					}
					tempimage[i][j] = sum/count;
				}
		}
	for (int i=0;i<height;i++)
		{
			for (int j=0;j<width;j++)
			{
				image[i][j] = tempimage[i][j];
			}
		}
	for(int i = 0;i<height;i++)
	{
		delete tempimage[i];
	}
	delete[] tempimage;
}
Image::Image(ImageHeader newimageheader , short** newimage)
{
	imageHeader = newimageheader;
	for (int i=0;i<height;i++)
		{
			for (int j=0;j<width;j++)
				{
					image[i][j] = newimage[i][j];
				}
		}

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
ImageHeader::ImageHeader()
{

}
