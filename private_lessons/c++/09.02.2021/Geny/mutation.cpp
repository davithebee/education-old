#include <iostream>
#include <string>
#include <vector>

int mutation(std::string genotypes[1000], int &mostGenes, int &longestGene)
{
    std::vector< std::vector<std::string> > genotypesGenes;
    genotypesGenes.resize(1000);

    size_t pozAA{};
    size_t pozBB{};
    int genotypesWithMutations{0};

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

    bool isFound{false};

    for(int i{0}; i<1000; i++)
        {
            isFound = false;

            if(genotypesGenes[i].size() > mostGenes)
            {
                mostGenes = genotypesGenes[i].size();
            }

            for(int j{0}; j<genotypesGenes[i].size(); j++)
                {
                    if(genotypesGenes[i][j].find("BCDDC") != std::string::npos && isFound == false)
                    {
                        genotypesWithMutations++;
                        isFound = true;
                    }

                    if(genotypesGenes[i][j].size() > longestGene)
                    {
                        longestGene = genotypesGenes[i][j].size();
                    }
                }
        }

    return genotypesWithMutations;
}
