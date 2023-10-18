#include <fstream>
#include <vector>
#include "ImageExample.h"

#pragma comment (lib, "")

HRESULT ImageExample::LoadBMP(LPCWSTR filename, ID2D1Bitmap** ppBitmap)
{
    std::ifstream file;
    file.open(filename, std::ios::binary);

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    
    file.read(reinterpret_cast<char*>(&bfh), sizeof(BITMAPFILEHEADER));
    file.read(reinterpret_cast<char*>(&bfh), sizeof(BITMAPINFOHEADER));

    if (bfh.bftype != 0x4D42)
    {
        return E_FAIL;
    }
    if (bin.biBitCount != 32)
    {
        return E_FAIL;
    }


    std::vector<char> pixels(bih, biSizeImage);
    file.seekg(bfh.bfOffBits);

    file.close();

    return S_OK;
}

HRESULT ImageExample::CreateDeviceResources()
{
    D2D

    return E_NOTIMPL;
}

void ImageExample::Render()
{
}
