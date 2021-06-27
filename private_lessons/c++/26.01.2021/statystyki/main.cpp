#include <iostream>
#include <fstream>
#include "statistics.cpp"
#include "doubleLetter.cpp"
#include "letterSequence.cpp"

int doubleLetter(std::string *words);
void statistics(std::string *words);
void letterSequence(std::string *words);

int main()
{
    std::fstream in, out;
    in.open("tekst.txt",std::ios::in);
    out.open("wyniki.txt",std::ios::out);

    std::string words[1876];

    if(in.good())
    {
        for(int i{0}; i<1876; i++)
        {
            in >> words[i];
        }

        out << "Zadanie 1" << '\n'
            << "Liczba słów w których" << '\n'
            << "występują pod rząd" << '\n'
            << "dwie takie same litery: " << doubleLetter(words) << '\n' << '\n';
        out.close();
        statistics(words);
        letterSequence(words);


    }
    else
    {
        std::cout << "fstream error";
    }

    return 0;
}
