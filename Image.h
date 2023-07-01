#pragma once

#include "Config.h"

//------------------------------------------------------------------------------------------------------------------
class AImage
{
public:
	AImage();

	void Get_Image_Info();

private:

	class APixel
	{
	public:
		APixel();
		APixel(int r, int g, int b);

		string Get_Info();

	private:
		int R;
		int G;
		int B;
	};

	static const int Pixel_Length = 5;

	APixel Pixels[Pixel_Length];
};
//------------------------------------------------------------------------------------------------------------------
