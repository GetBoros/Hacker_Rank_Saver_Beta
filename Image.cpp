#include "Image.h"

// AImage
AImage::AImage()
    : Pixels{ APixel(0, 0, 0), APixel(1, 1, 1), APixel(2, 2, 2), APixel(3, 3, 3), APixel(4, 4, 4) }
{
}
//------------------------------------------------------------------------------------------------------------------
void AImage::Get_Image_Info()
{
    int i;

    for (i = 0; i < Pixel_Length; i++)
    {
        cout << "#" << i << " " << Pixels[i].Get_Info() << endl;
    }
}
//------------------------------------------------------------------------------------------------------------------
AImage::APixel::APixel()
    :R(0), G(0), B(0)
{
}
//------------------------------------------------------------------------------------------------------------------
AImage::APixel::APixel(int r, int g, int b)
    : R(r), G(g), B(b)
{

}
//------------------------------------------------------------------------------------------------------------------
string AImage::APixel::Get_Info()
{
    return "Pixel: R = " + to_string(R) + " G = " + to_string(G) + " B = " + to_string(B);
}
//------------------------------------------------------------------------------------------------------------------
