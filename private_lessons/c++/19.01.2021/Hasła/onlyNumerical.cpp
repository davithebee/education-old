#include <iostream>

int onlyNumerical(std::string passwords[200]){

    int numericalPasswordsAmount{0};
    bool isNumerical{true};

    for(int i{0}; i<200; i++)
        {
            isNumerical = true;

            for(int characterIndex{0}; characterIndex < passwords[i].size(); characterIndex++)
            {
                if(passwords[i][characterIndex] < '0' || passwords[i][characterIndex] > '9')
                {
                    isNumerical = false;
                }
            }

            if(isNumerical == true)
            {
                    numericalPasswordsAmount++;
            }
        }

    return numericalPasswordsAmount;
}
