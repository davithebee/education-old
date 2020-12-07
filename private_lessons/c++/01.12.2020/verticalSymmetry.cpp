#include <iostream>

int verticalSymmetry(int image[][320], int imageHeight, int imageWidth){

    int rowsToDelete{0};

    for(int coordY{imageHeight-1}; coordY >= 0; coordY--)         //| Proper coordinates,
        {                                                         //| kinda useless here
            bool isSymmetrical{true};                             //| but whatever.

            for(int coordX{0}; coordX < imageWidth/2; coordX++)
                {
                    if(image[coordY][coordX] != image[coordY][imageWidth - coordX-1])
                    {
                        isSymmetrical = false;
                    }
                }
            if(isSymmetrical == false)
            {
                rowsToDelete++;
            }
        }

        return rowsToDelete;
}
