#include <iostream>
#include <string>
#include <vector>

int mutation(std::string genotypes[1000])
{
    std::vector< std::vector<std::string> > genotypesGenes;
    genotypesGenes.resize(1000);

    size_t pozAA{};
    size_t pozBB{};

    for(int i{0}; i<1000; i++)
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
        }while(pozAA != std::string::npos && pozBB != std::string::npos);
    }

    int genotypesWithMutations;
    return genotypesWithMutations;
}
