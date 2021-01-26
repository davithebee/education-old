#include <iostream>
#include <fstream>
#include <iomanip>

void statistics(std::string *words)
{

    std::fstream out;
    out.open("wyniki.txt",std::ios::app);

    int alphabet[26] {0};
    int characterCount {0};

    for(int i{0}; i<1876; i++)
    {
        for(int characterIndex{0}; characterIndex < words[i].size(); characterIndex++)
        {
            alphabet[words[i][characterIndex] - 65]++;
            characterCount++;
        }
    }

    out << "Zadanie 2" << '\n'
        << "Statystyki:" << '\n';

    for(int i{0}; i<26; i++)
        {
            out << (char)(i+65) << ": " << alphabet[i] << " (" << std::fixed << std::setprecision(2) <<(double)alphabet[i]/characterCount*100 << "%)" << '\n';
        }

    out.close();
}

