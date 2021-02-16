#include <iostream>
#include <fstream>
#include "maxSpeciesAmount.cpp"
#include "mutation.cpp"
#include "immunity.cpp"

int maxSpeciesAmount(std::string genotypes[1000], int &species);
int mutation(std::string genotypes[1000], int &mostGenes, int &longestGene);
void immunity(std::string genotypes[1000], int &normalImmunity, int &strongImmunity);

int main()
{
    std::fstream in, out;
    in.open("dane_geny.txt", std::ios::in);
    out.open("wyniki.txt", std::ios::out);

    int mostGenes{0};
    int longestGene{0};
    int strongImmunity{0};
    int normalImmunity{0};

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
            << "Największa liczba osobników reprezentujących ten sam gatunek wynosi: "
            << maxSpeciesAmount(genotypes,species)
            << '\n' << '\n';

        out << "Zadanie 2 \n"
            << mutation(genotypes, mostGenes, longestGene)
            << '\n' << '\n';

        out << "Zadanie 3 \n"
            << "Największa ilość genów w genotypie: "
            << mostGenes
            << '\n'
            << "Najdłuższy gen: "
            << longestGene
            << '\n' << '\n';

            immunity(genotypes, normalImmunity, strongImmunity);

        out << "Zadanie 4 \n"
            << "Ilość odpornych: "
            << normalImmunity
            << '\n'
            << "Ilość silnie odpornych: "
            << strongImmunity
            << '\n' << '\n';


    }
    else
    {
        out << "FSTREAM ERROR";
    }

    return 0;
}
