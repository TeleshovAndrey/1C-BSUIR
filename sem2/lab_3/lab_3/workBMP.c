#include "function.h"

int main() {
	char* name = (char*)malloc(sizeof(char));
	printf("enter file name (without format) - ");
	FILE* startFile = getFile(&name);
	BMPFile bmpFile;
	fread(&bmpFile.bhdr, sizeof(BMPHeader), 1, startFile);
	fread(&bmpFile.dhdr, sizeof(DIBHeader), 1, startFile);
	
	if (bmpFile.dhdr.bitsPerPixel != 24) {
		printf("Bits for pixel not 24!");
		exit(1);
	}
	bmpFile.pixels = (Pixel*)malloc(sizeof(Pixel) * bmpFile.dhdr.dataSize / 3);
	fseek(startFile, bmpFile.bhdr.pixelOffset, SEEK_SET);
	fread(bmpFile.pixels, sizeof(*bmpFile.pixels), bmpFile.dhdr.dataSize / 3, startFile);

	int choise;
	
	printf("	Enter corection\n");
	printf("1)Monohrome\n");
	printf("2)Negotive\n");
	printf("3)Median-filter corection\n");
	printf("4)Gamma corection\n");
	scanf_s("%d", &choise);
	if (choise == 1) monohrome(bmpFile.pixels, bmpFile);
	if (choise == 2) negotive(bmpFile.pixels, bmpFile);
	if (choise == 3) {
		int filterSize;
		printf("Enter filter size\n");
		scanf_s("%d", &filterSize);
		medianFiltration(bmpFile.pixels, bmpFile, filterSize);
	}
	if (choise == 4) {
		printf("Enter gamma for gamma correction\n");
		float gamma;
		scanf_s("%f", &gamma);
		gammaCorrection(bmpFile.pixels, bmpFile, gamma);
	}

	createFile(bmpFile);
	free(bmpFile.pixels);
	free(name);
	
	return 0;
}
