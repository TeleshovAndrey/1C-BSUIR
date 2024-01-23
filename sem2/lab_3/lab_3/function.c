#include "function.h"
void createFile(BMPFile bmpFile) {
	getchar();
	FILE* finishFile = NULL;
	char* name = (char*)malloc(sizeof(char));
	printf("Enter name finish file - ");
	int i = 0;
	char c;
	while ((c = getchar()) != EOF && c != '\n') {
		name[i++] = c;
		if (i >= 1) {
			name = (char*)realloc(name, (i * 2) * sizeof(char));
		}
	}
	name = realloc(name, i + 1);
	name[i] = '\0';
	
	int point = strlen(name);
	for (int j = 0; j < 7; j++) {
		point = strlen(name);
		name = (char*)realloc(name, sizeof(char) * (strlen(name) + 2));
		for (int i = point; i >= 0; i--)
			name[i + 1] = name[i];
	}
	name[0] = 'i';
	name[1] = 'm';
	name[2] = 'a';
	name[3] = 'g';
	name[4] = 'e';
	name[5] = 's';
	name[6] = '/';
	
	if (point == 0) exit(1);
	point = strlen(name);
	name = (char*)realloc((name), sizeof(char) * (point + 6));
	name[point] = '.';
	name[point + 1] = 'b';
	name[point + 2] = 'm';
	name[point + 3] = 'p';
	name[point + 4] = '\0';
	fopen_s(&finishFile, name, "wb");

	fwrite(&bmpFile.bhdr, sizeof(BMPHeader), 1, finishFile);
	fwrite(&bmpFile.dhdr, sizeof(DIBHeader), 1, finishFile);
	fwrite(bmpFile.pixels, sizeof(*bmpFile.pixels), bmpFile.dhdr.dataSize / 3, finishFile);
	fclose(finishFile);
	free(name);
}

FILE* getFile(char** strAll) {
	int i = 0;
	char c;
	while ((c = getchar()) != EOF && c != '\n') {
		(*strAll)[i++] = c;
		if (i >= 1) {
			(*strAll) = (char*)realloc((*strAll), (i * 2) * sizeof(char));
		}
	}
	(*strAll) = realloc((*strAll), i + 1);
	(*strAll)[i] = '\0';
	FILE* startFile = NULL;
	int point = strlen(*strAll);
	(*strAll) = (char*)realloc((*strAll), sizeof(char) * (point + 6));
	(*strAll)[point] = '.';
	(*strAll)[point + 1] = 'b';
	(*strAll)[point + 2] = 'm';
	(*strAll)[point + 3] = 'p';
	(*strAll)[point + 4] = '\0';
	fopen_s(&startFile, (*strAll), "rb");
	if (startFile == NULL) {
		printf("File not fouded!");
		exit(1);
	}
	return startFile;
}
void merge(unsigned char** nextArray, unsigned char* array1, unsigned char* array2, int lenght1, int lenght2)
{
	int array1MinIndex = 0, array2MinIndex = 0, nextArrayMinIndex = 0;
	while (array1MinIndex < lenght1 && array2MinIndex < lenght2) {
		if (array1[array1MinIndex] <= array2[array2MinIndex])
		{
			(*nextArray)[nextArrayMinIndex] = array1[array1MinIndex];
			array1MinIndex++;
		}
		else
		{
			(*nextArray)[nextArrayMinIndex] = array2[array2MinIndex];;
			array2MinIndex++;
		}
		nextArrayMinIndex++;
	}
	if (array1MinIndex < lenght1)
		while (array1MinIndex < lenght1) 
		{
			(*nextArray)[nextArrayMinIndex] = array1[array1MinIndex];
			array1MinIndex++;
			nextArrayMinIndex++;
		}
	if (array2MinIndex < lenght2)
		while (array2MinIndex < lenght2)
		{
			(*nextArray)[nextArrayMinIndex] = array2[array2MinIndex];
			array2MinIndex++;
			nextArrayMinIndex++;
		}
}
void mergeSort(unsigned char** array, int maxEll) {
	unsigned char* left;
	unsigned char* right;

	if (maxEll < 2) return;
	int mid = maxEll / 2;
	left = (unsigned char*)malloc(mid * sizeof(unsigned char));
	right = (unsigned char*)malloc((maxEll - mid) * sizeof(unsigned char));

	for (int i = 0; i < mid; i++)
	{
		left[i] = (*array)[i];
	}
	for (int i = mid; i < maxEll; i++)
	{
		right[i - mid] = (*array)[i];
	}
	mergeSort(&left, mid);
	mergeSort(&right, maxEll - mid);
	merge(array, left, right, mid, maxEll - mid);
}
void medianFiltration(Pixel* pixels, BMPFile bmpFile, int windowSize) {
	Pixel* temp = (Pixel*)malloc(bmpFile.dhdr.height * bmpFile.dhdr.width * sizeof(Pixel));
	memcpy(temp, pixels, bmpFile.dhdr.width * sizeof(Pixel) * bmpFile.dhdr.height);
	unsigned char* redWindow = (unsigned char*)malloc(sizeof(unsigned char) * windowSize * windowSize);
	unsigned char* greenWindow = (unsigned char*)malloc(sizeof(unsigned char) * windowSize * windowSize);
	unsigned char* blueWindow = (unsigned char*)malloc(sizeof(unsigned char) * windowSize * windowSize);
	Pixel* newPixels = (Pixel*)malloc(sizeof(Pixel) * bmpFile.dhdr.width * bmpFile.dhdr.height);

	for (int i = 0; i < bmpFile.dhdr.height; i++)
	{
		for (int j = 0; j < bmpFile.dhdr.width; j++)
		{
			fillWindow(j, i, bmpFile, windowSize, pixels, redWindow, 1);
			fillWindow(j, i, bmpFile, windowSize, pixels, greenWindow, 2);
			fillWindow(j, i, bmpFile, windowSize, pixels, blueWindow, 3);
			mergeSort(&redWindow, windowSize * windowSize);
			mergeSort(&greenWindow, windowSize * windowSize);
			mergeSort(&blueWindow, windowSize * windowSize);
			temp[i * bmpFile.dhdr.width + j].r = redWindow[windowSize * windowSize / 2];
			temp[i * bmpFile.dhdr.width + j].g = greenWindow[windowSize * windowSize / 2];
			temp[i * bmpFile.dhdr.width + j].b = blueWindow[windowSize * windowSize / 2];
		}
	}
	memcpy(pixels , temp, bmpFile.dhdr.width * sizeof(Pixel) * bmpFile.dhdr.height);
	free(redWindow);
	free(greenWindow);
	free(blueWindow);
}

void fillWindow(int x, int y, BMPFile bmpFile, int windowSize, Pixel* pixels , unsigned char* window, int color)
{
	int k;
	int l;
	int half_window = windowSize / 2;
	for (int i = y - half_window, k = 0; i < y + half_window; i++, k++)
		for (int j = x - half_window, l = 0; j < x + half_window; j++, l++)
		{
			if (i < 0 || j<0 || i>bmpFile.dhdr.height || j>bmpFile.dhdr.width) window[k * windowSize + l] = 0;
			else {
				if (color == 1)	window[k * windowSize + l] = pixels[i * bmpFile.dhdr.width + j].r;
				if (color == 2) window[k * windowSize + l] = pixels[i * bmpFile.dhdr.width + j].g;
				if (color == 3)	window[k * windowSize + l] = pixels[i * bmpFile.dhdr.width + j].b;
			}
		}
}
void monohrome(Pixel* pixels, BMPFile bmpFile) {
	for (int i = 0; i < bmpFile.dhdr.dataSize / 3; i++) {
		int I = 0.2125*pixels[i].r + 0.7154*pixels[i].g + 0.0721*pixels[i].b;
		pixels[i].r = I;
		pixels[i].g = I;
		pixels[i].b = I;
	}
}
void negotive(Pixel* pixels, BMPFile bmpFile) {
	for (int i = 0; i < bmpFile.dhdr.dataSize/3; i++) {
		pixels[i].r = 255- pixels[i].r;
		pixels[i].g = 255 - pixels[i].g;
		pixels[i].b = 255 - pixels[i].b;
	}
}
void gammaCorrection(Pixel* pixels, BMPFile bmpFile, float gamma) {
	for (int i = 0; i < bmpFile.dhdr.height; i++)
		for (int j = 0; j < bmpFile.dhdr.width; j++)
		{
			pixels[(i * bmpFile.dhdr.width + j)].b = (unsigned char)(pow((float)pixels[(i * bmpFile.dhdr.width + j)].b / 255, gamma) * 255);
			pixels[(i * bmpFile.dhdr.width + j)].g = (unsigned char)(pow((float)pixels[(i * bmpFile.dhdr.width + j)].g / 255, gamma) * 255);
			pixels[(i * bmpFile.dhdr.width + j)].r = (unsigned char)(pow((float)pixels[(i * bmpFile.dhdr.width + j)].r / 255, gamma) * 255);
		}
}