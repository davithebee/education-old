#include <iostream>

int tallestColumn(int image[][320], int imageHeight, int imageWidth){

int countColumnHeight{1};
int maxColumnHeight{0};

    for(int coordX{0}; coordX < imageWidth; coordX++)
        {
            for(int coordY{imageHeight-1}; coordY > 0; coordY--)
                {
                    if(image[coordY][coordX] == image[coordY-1][coordX])
                    {
                        countColumnHeight++;
                        if(countColumnHeight > maxColumnHeight)
                        {
                            maxColumnHeight = countColumnHeight;
                        }
                    }
                    else
                    {
                        countColumnHeight = 1;
                    }
                }
        }

        return maxColumnHeight;
}
