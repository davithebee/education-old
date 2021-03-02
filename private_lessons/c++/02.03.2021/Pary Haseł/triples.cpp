#include <iostream>

bool triples(std::string pwd, int *ABC_count, int *ABC_fileCount)
{
    std::string ABC_triples[6] {"ABC","ACB","BAC","BCA","CAB","CBA"};

    for(int i{0}; i<6; i++)
    {
        ABC_count[i] = 0;
    }

    for(int i{0}; i < pwd.size()-2; i++)
    {
        for(int j{0}; j < 6; j++)
        {
            if(pwd.substr(i,3) == ABC_triples[j])
            {
                ABC_count[j]++;
                j = 6;
            }
        }
    }

    for(int i{0}; i < 6; i++)
    {
        ABC_fileCount[i] += ABC_count[i];
    }

    for(int i{0}; i < 6; i++)
    {
        if(ABC_count[i] >= 2)
        {
            return true;
        }
    }

    return false;
}
