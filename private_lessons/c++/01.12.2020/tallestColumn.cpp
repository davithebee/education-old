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
