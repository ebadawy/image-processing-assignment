/************************************************************
*
* file cips.h
*
* Functions: This file contains no functions. It
* contains declarations of the data structures used
* by the C Image Processing Systems CIPS.
*
* Purpose:
* To declare data structures.
*
* Modifications:
* June 1990 = created
*
**********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <dos.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <sys\types.h>
#include <sys\stat.h>
#define MAX_NAME_LENGTH 80
#define ROWS 100
#define COLS 100
#define GRAY_LEVELS 255
#define PREWITT 1
#define PEAK_SPACE 50
#define PEAKS 30
#define KIRSCH 2
#define SOBEL 3
#define STACK_SIZE 40000
#define STACK_FILE_LENGTH 500
#define FORGET_IT -50
#define STACK_FILE "c:stack"
#define OTHERC 1
#undef MSC
/**************************************************
*
* The following struct defines the information
* you need to read from the bmp file
* header.
*
***************************************************/
struct bmpfileheader{
unsigned short filetype;
unsigned long filesize;
short reserved1;
short reserved2;
unsigned long bitmapoffset;
};
struct bitmapheader{
unsigned long size;
long width;
long height;
unsigned short planes;
unsigned short bitsperpixel;
unsigned long compression;
unsigned long sizeofbitmap;
unsigned long horzres;
unsigned long vertres;
unsigned long colorsused;
unsigned long colorsimp;
};
struct ctstruct{
unsigned char blue;
unsigned char green;
unsigned char red;
};
/*********************************************
*
* The following unions are used
* to put the bytes from the header
* into either an integer or a floating
* point number.
*
**********************************************/
union short_char_union{
short s_num;
char s_alpha[2];
};
union int_char_union{
int i_num;
char i_alpha[2];
};
union long_char_union{
long l_num;
char l_alpha[4];
};
union float_char_union{
float f_num;
char f_alpha[4];
};
union ushort_char_union{
short s_num;
char s_alpha[2];
};
union uint_char_union{
int i_num;
char i_alpha[2];
};
union ulong_char_union{
long l_num;
char l_alpha[4];
};
/**************************************************
*
* The following struct defines the information
* you need to read from the tiff file
* header.
*
***************************************************/
struct tiff_header_struct{
short lsb;
long bits_per_pixel;
long image_length;
long image_width;
long strip_offset;
};
/**************************************************
*
* Declarlation of the functions
*
***************************************************/
void read_image_array(char *file_name,short **array);
void write_image_array(char *file_name, short **array);
void create_image_file(char *in_name, char *out_name);
int get_image_size(char *file_name, long *rows, long *cols);
short **allocate_image_array(long length,long width);
int free_image_array(short **the_array, long length);
void create_file_if_needed(char *in_name, char *out_name, short **array);
void create_resized_image_file(char *in_name, char *out_name,long length,long width);
int does_not_exist(char file_name[]);
int are_not_same_size(char *file1, char *file2);
void equate_bitmapheaders(struct bitmapheader *src, struct bitmapheader *dest);
int get_bitsperpixel(char *file_name, long *bitsperpixel);
int get_lsb(char *name);
void read_tiff_header(char file_name[], struct tiff_header_struct *image_header);
void read_tiff_image(char image_file_name[], short **the_image);
int read_line (FILE *image_file , short **the_image,int line_number, struct tiff_header_struct *image_header,int ie,int le);
void create_tiff_file_if_needed(char in_name[], char  out_name[], short **out_image);
void create_allocate_tiff_file(char file_name[],struct tiff_header_struct *image_header);
void write_tiff_image(char image_file_name[], short **array);
int write_line(FILE *image_file, short **array ,int line_number,struct tiff_header_struct *image_header,int ie,int le);
int is_a_tiff(char *file_name);
void equate_tiff_headers(struct tiff_header_struct *src, struct tiff_header_struct *dest);
void extract_long_from_buffer(char buffer[],int lsb,int start, long *number);
void extract_ulong_from_buffer(char buffer[],int lsb,int start,unsigned long *number);
void extract_short_from_buffer(char buffer[],int lsb,int start,short *number);
void extract_ushort_from_buffer(char buffer[],int lsb,int start, unsigned short *number);
void insert_short_into_buffer(char buffer[], int start,short number);
void insert_ushort_into_buffer(char buffer[], int start,unsigned short number);
void insert_long_into_buffer(char buffer[],int start,long number);
void insert_ulong_into_buffer(char buffer[],int start,unsigned long number);
void read_bmp_file_header(char *file_name,struct bmpfileheader *file_header);
void read_bm_header(char *file_name,struct bitmapheader *bmheader);
void read_color_table(char *file_name,struct ctstruct *rgb,int size);
void read_bmp_image(char *file_name,short **array);
void create_bmp_file_if_needed(char in_name[],char out_name[],short **out_image);
void create_allocate_bmp_file(char *file_name,struct bmpfileheader *file_header,struct bitmapheader *bmheader);
void write_bmp_image(char *file_name,short **array);
int is_a_bmp(char *file_name);
int calculate_pad(long width);
void equate_bmpfileheaders(struct bmpfileheader *src, struct bmpfileheader *dest);
void flip_image_array(short **the_image,long rows,long cols);



