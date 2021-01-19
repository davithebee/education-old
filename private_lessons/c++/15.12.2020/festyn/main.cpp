#include <iostream>
#include <fstream>

int countPoints(int**targetAppearanceTime, int targetAmount, bool*isTargetHit, int*timeOfShots, int shotsTaken);
int maxTargetAppearanceTime(int**targetAppearanceTime, int targetAmount);

void drawArray1(int*tab, int w){
    for(int i{0}; i<w; i++){
        std::cout << tab[i] << '\n';
    }
}

void drawArray2(int**tab, int w, bool*tab2){
    for(int i{0}; i<w; i++){
        std::cout << tab[i][0] << " - " << tab[i][1] << " - " << tab2[i] << '\n';
    }
}

int main()
{
    std::fstream input, output;
    input.open("festyn.txt",std::ios::in);
    output.open("wyniki.txt",std::ios::out);


    if(input.good())
    {
        std::cout << "INPUT - OK" << '\n' << '\n';

        int setCount{ 0 };
        int targetAmount{};
        int shotsTaken{};

        while(!input.eof())
        {
            setCount++;
            std::cout << "TEST SET " << setCount << " - OK" << '\n' << '\n';

            input >> targetAmount;

            int**targetAppearanceTime = new int*[targetAmount];
            for(int i{ 0 }; i < targetAmount; i++)
                {
                    targetAppearanceTime[i] = new int[2];
                    input >> targetAppearanceTime[i][0];
                    input >> targetAppearanceTime[i][1];
                }

            bool*isTargetHit = new bool[targetAmount];
            for(int i{ 0 }; i < targetAmount; i++)
                {
                    isTargetHit[i] = false;
                }

            //drawArray2(targetAppearanceTime, targetAmount, isTargetHit);

            input >> shotsTaken;

            int*timeOfShots = new int[shotsTaken];
            for(int i{ 0 }; i < shotsTaken; i++)
                {
                    input >> timeOfShots[i];
                }

            //drawArray1(timeOfShots, shotsTaken);

            output << "TEST SET - " << setCount << '\n' << '\n';
            output << "ZADANIE 1:" << '\n';
            output << countPoints(targetAppearanceTime, targetAmount, isTargetHit, timeOfShots, shotsTaken) << '\n';
            output << "ZADANIE 2:" << '\n';
            output << maxTargetAppearanceTime(targetAppearanceTime, targetAmount) << '\n' << '\n' << '\n';

            //| Zwolnienie pamięci |//
            for(int i{ 0 }; i < targetAmount; i++)
                {
                    delete []targetAppearanceTime[i];
                }
            delete []targetAppearanceTime;
            delete []isTargetHit;
            delete []timeOfShots;
        }
    }
    else
    {
        std::cout << "INPUT - ERROR";
    }

    return 0;
}
