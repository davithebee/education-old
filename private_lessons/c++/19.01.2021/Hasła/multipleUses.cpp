#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

void multipleUses(std::string passwords[200]){

    std::fstream out;
    out.open("wyniki.txt",std::ios::app);

    std::vector<std::string> sortedPasswords;

    for(int i{0}; i<200; i++)
        {
            sortedPasswords.push_back(passwords[i]);
        }

    sort(sortedPasswords.begin(), sortedPasswords.end());

    int skip{0};
    int countIdentical{1};

    for(int i{0}; i<199; i++)
    {
        countIdentical = 1;

        if(sortedPasswords[i] == sortedPasswords[i+1])
        {
            while(sortedPasswords[i] == sortedPasswords[i+countIdentical])
            {
            countIdentical++;
            }

            i+=countIdentical-1;

            out << sortedPasswords[i] << '\n';
        }
    }
}
