#include <iostream>
#include <fstream>
#include "maxSpeciesAmount.cpp"
#include "mutation.cpp"

int maxSpeciesAmount(std::string genotypes[1000], int &species);
int mutation(std::string genotypes[1000]);

int main()
{
    std::fstream in, out;
    in.open("dane_geny.txt", std::ios::in);
    out.open("wyniki.txt", std::ios::out);

    if(in.good())
    {
        std::string genotypes[1000];
        int species{0};

        for(int i{0}; i<1000; i++)
            {
                in >> genotypes[i];
            }


        out << "Zadanie 1 \n"
            << "Liczba gatunków wynosi: "
            << species
            << '\n'
            << "Najwiêksza liczba osobników reprezentujących ten sam gatunek wynosi: "
            << maxSpeciesAmount(genotypes,species)
            << '\n' << '\n';

        out << "Zadanie 2 \n"
            << mutation(genotypes);


    }
    else
    {
        out << "FSTREAM ERROR";
    }

    return 0;
}
