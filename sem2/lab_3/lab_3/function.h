#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma pack(1)
typedef struct Pixel {
	unsigned char r;
	unsigned char g;
	unsigned char b;
}Pixel;
typedef struct {
	unsigned char ID[2];
	unsigned int fileSize;
	unsigned char unused[4];
	unsigned int pixelOffset;
} BMPHeader;
typedef struct {
	unsigned int headerSize;
	unsigned int width;
	unsigned int height;
	unsigned short colorPlanes;
	unsigned short bitsPerPixel;
	unsigned int BIRGB;
	unsigned int dataSize;
	unsigned int pwidth;
	unsigned int pheight;
	unsigned int colorsCount;
	unsigned int impColorsCount;
}DIBHeader;

typedef struct {
	BMPHeader bhdr;
	DIBHeader dhdr;
	Pixel* pixels;
}BMPFile;
#pragma pop

void createFile(BMPFile bmpFile);
FILE* getFile(char** strAll);
void mergeSort(unsigned char** array, int maxEll);
void merge(unsigned char** nextArray, unsigned char* array1, unsigned char* array2, int lenght1, int lenght2);
void medianFiltration(Pixel* pixels, BMPFile bmpFile, int windowSize);
void fillWindow(int x, int y, BMPFile bmpFile, int windowSize, Pixel* pixels, unsigned char* window, int color);
void monohrome(Pixel* pixels, BMPFile bmpFile);
void negotive(Pixel* pixels, BMPFile bmpFile);
void gammaCorrection(Pixel* pixels, BMPFile bmpFile, float gamma);