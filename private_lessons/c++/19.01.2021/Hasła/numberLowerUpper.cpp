#include <iostream>

int numberLowerUpper(std::string passwords[200]){

    int goodPasswordsAmount{0};
    bool isNumerical{false};
    bool isLower{false};
    bool isUpper{false};

    for(int i{0}; i<200; i++)
        {
            isNumerical = false;
            isLower = false;
            isUpper = false;

            for(int characterIndex{0}; characterIndex < passwords[i].size(); characterIndex++)
            {
                if(passwords[i][characterIndex] <= '9' && passwords[i][characterIndex] >= '0')
                {
                    isNumerical = true;
                }
                if(passwords[i][characterIndex] <= 122 && passwords[i][characterIndex] >= 97)
                {
                    isLower = true;
                }
                if(passwords[i][characterIndex] <= 90 && passwords[i][characterIndex] >= 65)
                {
                    isUpper = true;
                }
            }

            if(isNumerical == true && isLower == true && isUpper == true)
            {
                    goodPasswordsAmount++;
            }
        }

    return goodPasswordsAmount;
}
