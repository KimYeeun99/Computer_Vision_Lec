#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	BITMAPFILEHEADER hf; //14바이트
	BITMAPINFOHEADER hInfo; //40바이트
	RGBQUAD hRGB[256]; //1024바이트
	FILE* fp;
	fp = fopen("lenna.bmp", "rb");
	if (fp == NULL) {
		printf("File not found!/n");
		return -1;
	}
	fread(&hf, sizeof(BITMAPFILEHEADER), 1, fp);
	fread(&hInfo, sizeof(BITMAPINFOHEADER), 1, fp);
	fread(hRGB, sizeof(RGBQUAD), 256, fp);
	int ImgSize = hInfo.biWidth * hInfo.biHeight;
	BYTE* Image = (BYTE*)malloc(ImgSize);
	BYTE* Output1 = (BYTE*)malloc(ImgSize);
	BYTE* Output2 = (BYTE*)malloc(ImgSize);
	BYTE* Output3 = (BYTE*)malloc(ImgSize);
	fread(Image, sizeof(BYTE), ImgSize, fp);
	fclose(fp);

	for (int i = 0; i < ImgSize; i++)
	{
		Output1[i] = Image[i];
	}

	for (int i = 0; i < ImgSize; i++)
	{
		Output2[i] = Image[i] + 50;
	}


	for (int i = 0; i < ImgSize; i++)
	{
		Output3[i] = 255 - Image[i];
	}

	fp = fopen("output1.bmp", "wb");
	fwrite(&hf, sizeof(BYTE), sizeof(BITMAPFILEHEADER), fp);
	fwrite(&hInfo, sizeof(BYTE), sizeof(BITMAPINFOHEADER), fp);
	fwrite(hRGB, sizeof(RGBQUAD), 256, fp);
	fwrite(Output1, sizeof(BYTE), ImgSize, fp);
	free(Output1);

	fp = fopen("output2.bmp", "wb");
	fwrite(&hf, sizeof(BYTE), sizeof(BITMAPFILEHEADER), fp);
	fwrite(&hInfo, sizeof(BYTE), sizeof(BITMAPINFOHEADER), fp);
	fwrite(hRGB, sizeof(RGBQUAD), 256, fp);
	fwrite(Output2, sizeof(BYTE), ImgSize, fp);
	free(Output2);

	fp = fopen("output3.bmp", "wb");
	fwrite(&hf, sizeof(BYTE), sizeof(BITMAPFILEHEADER), fp);
	fwrite(&hInfo, sizeof(BYTE), sizeof(BITMAPINFOHEADER), fp);
	fwrite(hRGB, sizeof(RGBQUAD), 256, fp);
	fwrite(Output3, sizeof(BYTE), ImgSize, fp);
	free(Output3);

	fclose(fp);
	free(Image);
	return 0;
}
