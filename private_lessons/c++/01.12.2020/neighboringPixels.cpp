#include <iostream>

int neighboringPixels(int image[][320], int imageHeight, int imageWidth){

    int contrastingPixels{0};

    for(int coordY{imageHeight-1}; coordY >= 0; coordY--)
        {
            for(int coordX{0}; coordX < imageWidth; coordX++)
                {
                    bool isContrasting{false};

                    if(coordX > 0)
                    {
                        if(abs(image[coordY][coordX] - image[coordY][coordX - 1]) > 128)
                        {
                            isContrasting = true;
                        }
                    }

                    if(coordX < 319)
                    {
                        if(abs(image[coordY][coordX] - image[coordY][coordX + 1]) > 128)
                        {
                            isContrasting = true;
                        }
                    }

                    if(coordY < 199)
                    {
                        if(abs(image[coordY][coordX] - image[coordY + 1][coordX]) > 128)
                        {
                            isContrasting = true;
                        }
                    }

                    if(coordY > 0)
                    {
                        if(abs(image[coordY][coordX] - image[coordY - 1][coordX]) > 128)
                        {
                            isContrasting = true;
                        }
                    }

                    if(isContrasting == true)
                    {
                        contrastingPixels++;
                    }
                }
        }

    return contrastingPixels;
}
