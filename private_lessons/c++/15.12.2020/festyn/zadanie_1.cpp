#include <iostream>

int countPoints(int**targetAppearanceTime, int targetAmount, bool*isTargetHit, int*timeOfShots, int shotsTaken)
{
    int points{ 0 };

    for(int i{ 0 }; i < shotsTaken; i++)
    {
        for(int j{ 0 }; j < targetAmount; j++)
        {
            if(isTargetHit[j] == false)
            {
                if((targetAppearanceTime[j][0] + targetAppearanceTime[j][1] - 1) >= timeOfShots[i] && targetAppearanceTime[j][0] <= timeOfShots[i])
                {
                    points++;
                    isTargetHit[j] = true;
                }
            }
        }
    }

    return points;
}
