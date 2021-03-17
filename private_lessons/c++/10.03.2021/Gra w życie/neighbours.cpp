#include <iostream>

int neighbours(int **board, int y, int x, int currentPosY, int currentPosX)
{
    int alive{0};

    for(int i{currentPosY+1}; i >= (currentPosY-1); i--)
        {
            for(int j{currentPosX-1}; j <= (currentPosX+1); j++)
                {
                    /*std::cout<<"( "<<(i+y)%y<<", "<<(j+x)%x<<" )";
                    std::cout<<"   ";*/

                    if(i != currentPosY || j != currentPosX)
                       {
                          alive += board[(i+y)%y][(j+x)%x];
                       }
                }
                /*std::cout<<'\n';*/
        }

    return alive;
}
