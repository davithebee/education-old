<<<<<<< HEAD
#include <iostream>

int tallestColumn(int image[][320], int imageHeight, int imageWidth){

int columnCount{0};
int columnMaxSize{0};

    for(int coordX{0}; coordX < imageWidth; coordX++)
        {
            for(int coordY{imageHeight-1}; coordY > 0; coordY--)
                {
                    if(image[coordY-1][coordX] == image[coordY][coordX])
                    {
                        columnCount++;

                        if(columnMaxSize<columnCount)
                        {
                            columnMaxSize = columnCount;
                        }
                    }
                    else
                    {
                        columnCount = 0;
                    }
                }
        }

        return columnMaxSize;
}
=======
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
>>>>>>> 1dbeddd376a53d6f8df7b444f3fef835973e0fc9
