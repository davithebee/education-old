#include <iostream>

int maxSpeciesAmount(std::string genotypes[1000], int &species)
{
    int speciesAmount[501]{0};

    for(int i{0}; i<1000; i++)
    {
        speciesAmount[genotypes[i].size()]++;
    }

    int maxSpeciesAmount{speciesAmount[1]};

    for(int i{2}; i<501; i++)
    {
        if(speciesAmount[i]>maxSpeciesAmount)
        {
            maxSpeciesAmount = speciesAmount[i];
        }
    }

    for(int i{1}; i<501; i++)
    {
        if(speciesAmount[i] != 0)
        {
            species++;
        }
    }

    return maxSpeciesAmount;
}
