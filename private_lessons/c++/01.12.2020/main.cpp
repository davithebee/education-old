#include <iostream>
//#include <bits/stdc++.h>
#include <fstream>

void pixelBrightness(int image[][320], int &brightestPixel, int &darkestPixel, int imageHeight, int imageWidth);
int verticalSymmetry(int image[][320], int imageHeight, int imageWidth);
int neighboringPixels(int image[][320], int imageHeight, int imageWidth);

int main()
{
    std::fstream in,out;
    in.open("dane.txt", std::ios::in);
    out.open("wyniki.txt", std::ios::out);

    int image[200][320];
    int brightestPixel{ 0 };
    int darkestPixel{ 255 };

    if(in.good())
    {
        //| Load data from the dane.txt file |//
        //| into the image array             |//
        for(int coordY{0}; coordY < 200; coordY++)
        {
            for(int coordX{0}; coordX < 320; coordX++)
            {
                in >> image[coordY][coordX];
            }
        }
      //| ---------------------------------- |//

    pixelBrightness(image, brightestPixel, darkestPixel, 200, 320);

    out << "Zadanie 1: \n"
        << "Najjasniejszy piksel: " << brightestPixel << '\n'
        << "Najciemniejszy piksel: " << darkestPixel <<' \n' << '\n';

    out << "Zadanie 2: \n"
        << "Aby uzyska� symetri� pionow� \n"
        << "nale�y usun�� " << verticalSymmetry(image, 200, 320)
        << " wierszy. \n \n";

    out << "Zadanie 3: \n"
        << "Liczba pikseli dla kt�rych \n"
        << "istnieje piksel kontrastuj�cy: " << neighboringPixels(image, 200, 320) << '\n' << '\n';

    }
    else
    {
        std::cout << "ERROR";
        return 0;
    }

    return 0;
}
