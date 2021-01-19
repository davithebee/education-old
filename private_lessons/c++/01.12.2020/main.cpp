#include <iostream>
//#include <bits/stdc++.h>
#include <fstream>

void pixelBrightness(int image[][320], int &brightestPixel, int &darkestPixel, int imageHeight, int imageWidth);
int verticalSymmetry(int image[][320], int imageHeight, int imageWidth);
int neighboringPixels(int image[][320], int imageHeight, int imageWidth);
int tallestColumn(int image[][320], int imageHeight, int imageWidth);

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
        << "Najjaśniejszy piksel: " << brightestPixel << '\n'
        << "Najciemniejszy piksel: " << darkestPixel <<'\n' << '\n';

    out << "Zadanie 2: \n"
<<<<<<< HEAD
        << "Aby uzyskać symetrię pionową \n"
=======
        << "Aby uzyskaæ symetrię pionową \n"
>>>>>>> 1dbeddd376a53d6f8df7b444f3fef835973e0fc9
        << "należy usunąć " << verticalSymmetry(image, 200, 320)
        << " wierszy. \n \n";

    out << "Zadanie 3: \n"
        << "Liczba pikseli dla których \n"
        << "istnieje piksel kontrastujący: " << neighboringPixels(image, 200, 320) << '\n' << '\n';

    out << "Zadanie 4: \n"
<<<<<<< HEAD
        << "Długość najdłuższej \n"
        << "linii pionowej wynosi: " << tallestColumn(image, 200, 320) << '\n' << '\n';
=======
        << "Wysokość najdłuższej \n"
        << "linii pionowej: " << tallestColumn(image, 200, 320) << '\n' << '\n';
>>>>>>> 1dbeddd376a53d6f8df7b444f3fef835973e0fc9

    }
    else
    {
        std::cout << "ERROR";
        return 0;
    }

    return 0;
}
