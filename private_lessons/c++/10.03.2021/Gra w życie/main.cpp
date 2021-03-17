#include <iostream>
#include <fstream>

int neighbours(int **board, int y, int x, int currentPosY, int currentPosX);

void draw(int **board, int y, int x)
{
    // -------------- DRAW ------------------
    for(int i{0}; i < y; i++)
    {
        for(int j{0}; j< x; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << '\n';
    }
    // -------------- /DRAW ------------------
}

int main()
{
    // --- FSTREAM from file ---
    std::fstream in, out;
    in.open("gra.txt", std::ios::in);
    out.open("wyniki.txt", std::ios::out);
    // --- /FSTREAM from file ---

    if(in.good())
    {
        // -- FIND SIZE OF THE GAME BOARD --
        int y{0};
        std::string charactersInRow;
        while(!in.eof())
        {
            in >> charactersInRow;
            y++;
        }
        int x{charactersInRow.size()};

        in.seekg(0);
        // -- /FIND SIZE OF THE GAME BOARD --

        // --- CREATE ARRAY BASED ON THE SIZE OF THE BOARD --
        int** board = new int *[y];
        for(int i{0}; i < y; i++)
        {
            board[i] = new int[x];
        }
        // --- /CREATE ARRAY BASED ON THE SIZE OF THE BOARD --

        // --- FILL ARRAY WITH ALIVE AND DEAD CELLS ( 1 AND 0 ) ---
        char tempChar;

        for(int i{0}; i < y; i++)
        {
            for(int j{0}; j < x; j++)
            {
                in >> tempChar;

                if(tempChar == '.')
                {
                    board[i][j] = 0;
                }
                if(tempChar == 'X')
                {
                    board[i][j] = 1;
                }
            }
        }
        // --- /FILL ARRAY WITH ALIVE AND DEAD CELLS ( 1 AND 0 ) ---

        // --- CREATE ARRAY FOR THE NEXT GEN BASED ON THE SIZE OF THE BOARD --
        int** newBoard = new int *[y];
        for(int i{0}; i < y; i++)
        {
            newBoard[i] = new int[x];
        }
        // --- /CREATE ARRAY FOR THE NEXT GEN BASED ON THE SIZE OF THE BOARD --

        // ----- DRAW FIRST GEN ------
        draw(board, y, x);
        for(int i{0}; i<(2*x-1); i++)
            {
                std::cout<<"-";
            }
        std::cout<<'\n';
        // ----- /DRAW FIRST GEN ------

        // ----- GENERATE NEXT GEN -----
        for(int i{0}; i < y; i++)
        {
            for(int j{0}; j < x; j++)
            {
                if(board[i][j] == 1)
                {
                    if(neighbours(board, y, x, i, j) == 2 || neighbours(board, y, x, i, j) == 3)
                    {
                        newBoard[i][j] = 1;
                    }
                    else
                    {
                        newBoard[i][j] = 0;
                    }
                }
                if(board[i][j] == 0)
                {
                    if(neighbours(board, y, x, i, j) == 3)
                    {
                        newBoard[i][j] = 1;
                    }
                    else
                    {
                        newBoard[i][j] = 0;
                    }
                }
            }
        }
        // ----- /GENERATE NEXT GEN -----

        // ----- DRAW SECOND GEN ------
        draw(newBoard, y, x);
        // ----- /DRAW SECOND GEN ------


        // ----- RELEASE MEMORY -----
        for(int i{0}; i < y; i++)
        {
            delete []board[i];
        }
        delete []board;

        for(int i{0}; i < y; i++)
        {
            delete []newBoard[i];
        }
        delete []newBoard;
        // ----- /RELEASE MEMORY -----
    }
    else
    {
        std::cout << "FSTREAM ERROR";
        out << "FSTREAM ERROR";
    }

    return 0;
}
