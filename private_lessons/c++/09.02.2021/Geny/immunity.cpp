#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(std::string text)
{
    for(int i{0}; i < (text.size()); i++)
    {
        if(text[i] != text[text.size()-1-i])
        {
            return false;
        }
    }
    return true;
}

std::string reverseText(std::string text)
{
    std::string newtext{""};

    for(int i{0}; i < text.size(); i++)
    {
        newtext = text[i] + newtext;
    }

    return newtext;
}

void immunity(std::string genotypes[1000], int &normalImmunity, int &strongImmunity)
{
    std::cout << "ok";

    std::vector< std::vector<std::string> > genotypesGenes;
    std::vector< std::vector<std::string> > genotypesGenesReverse;
    genotypesGenes.resize(1000);
    genotypesGenesReverse.resize(1000);

    std::string reverseGenotypes[1000];

    for(int i{0}; i < 1000; i++)
    {
        reverseGenotypes[i] = reverseText(genotypes[i]);
    }

    size_t pozAA{};
    size_t pozAA2{};
    size_t pozBB{};
    std::string kopia;

    for(int i{0}; i < 1000; i++)
    {
        if(isPalindrome(genotypes[i]))
        {
            strongImmunity++;
        }
        else
        {
            pozBB = 0;
            do
            {
                pozAA = genotypes[i].find("AA",pozBB);
                pozBB = genotypes[i].find("BB",pozAA+2);
                if(pozAA != std::string::npos && pozBB != std::string::npos)
                {
                    genotypesGenes[i].push_back(genotypes[i].substr(pozAA, (pozBB-pozAA+2)));
                }
            }
            while(pozAA != std::string::npos && pozBB != std::string::npos);

            pozBB = 0;
            do
            {
                pozAA = reverseGenotypes[i].find("AA",pozBB);
                pozBB = reverseGenotypes[i].find("BB",pozAA+2);
                if(pozAA != std::string::npos && pozBB != std::string::npos)
                {
                    genotypesGenesReverse[i].push_back(reverseGenotypes[i].substr(pozAA, (pozBB-pozAA+2)));
                }
            }
            while(pozAA != std::string::npos && pozBB != std::string::npos);

            for(int j{0}; j < genotypesGenes[i].size(); j++)
            {
                for(int k{genotypesGenesReverse[i].size()-1}; k >= 0 ; k--)
                {
                    if(genotypesGenes[i][j] == genotypesGenesReverse[i][k])
                    {
                        normalImmunity++;
                        k = genotypesGenesReverse[i].size();
                        j = genotypesGenes[i].size();
                    }
                }
            }
        }
    }
}
