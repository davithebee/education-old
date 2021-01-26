#include <iostream>
#include <fstream>
#include <vector>

void letterSequence(std::string *words)
{

    std::fstream out;
    out.open("wyniki.txt",std::ios::app);

    int sequenceLenght{0};
    int longestSequence{0};
    int longestSequenceAmount{1};
    int longestWordIndex{0};

    for(int i{0}; i<1876; i++)
    {
        sequenceLenght = 0;
        for(int characterIndex{0}; characterIndex < words[i].size(); characterIndex++)
        {
            if(words[i][characterIndex] != 'A' && words[i][characterIndex] != 'E' && words[i][characterIndex] != 'I' &&
               words[i][characterIndex] != 'O' && words[i][characterIndex] != 'U' && words[i][characterIndex] != 'Y' )
            {
                sequenceLenght++;
            }
            else
            {
                if(sequenceLenght > longestSequence)
                {
                    longestSequence = sequenceLenght;
                    longestSequenceAmount = 1;
                    longestWordIndex = i;
                }
                if(sequenceLenght == longestSequence)
                {
                    longestSequenceAmount++;
                }
            }
        }
    }

    out << "Zadanie 3:" << '\n'
        << "D�ugo�� najd�u�szego pods�owa: " << longestSequence << '\n'
        << "Liczba s��w z pods�owem o takiej d�ugo�ci: " << longestSequenceAmount << '\n'
        << "Pierwsze s�owo o tej d�ugo�ci : " << words[longestWordIndex];
}
