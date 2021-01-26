#include <iostream>
#include <algorithm>

int fourASCII(std::string passwords[200]){

    int goodPasswords{0};
    std::string fourCheck;

    for(int i{0}; i<200; i++)
        {
            for(int characterIndex{0}; characterIndex < passwords[i].size()-3; characterIndex++)
            {
                fourCheck = passwords[i].substr(characterIndex, 4);
                sort(fourCheck.begin(), fourCheck.end());

                if(fourCheck[0] + 1 == fourCheck[1] && fourCheck[1] + 1 == fourCheck[2] && fourCheck[2] + 1 == fourCheck[3] )
                {
                    goodPasswords++;
                    characterIndex = passwords[i].size();
                }
            }
        }

    return goodPasswords;
}
