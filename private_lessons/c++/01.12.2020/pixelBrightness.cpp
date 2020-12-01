#include <iostream>

void pixelBrightness(int image[][320], int &brightestPixel, int &darkestPixel, int imageHeight, int imageWidth){

    for(int coordY{imageHeight-1}; coordY >= 0; coordY--)       //| Proper coordinates,
        {                                                       //| kinda useless here
            for(int coordX{0}; coordX < imageWidth; coordX++)   //| but whatever.
                {
                    if(image[coordY][coordX] > brightestPixel)
                    {
                        brightestPixel = image[coordY][coordX];
                    }
                    if(image[coordY][coordX] < darkestPixel)
                    {
                        darkestPixel = image[coordY][coordX];
                    }
                }
        }

}
