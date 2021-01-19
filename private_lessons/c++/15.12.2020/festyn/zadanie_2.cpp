#include <iostream>

int maxTargetAppearanceTime(int**targetAppearanceTime, int targetAmount)
{
    int maxTargetAppearanceTime{ 0 };

    for(int i{ 0 }; i < targetAmount; i++)
    {
       if(targetAppearanceTime[i][1] > maxTargetAppearanceTime)
       {
            maxTargetAppearanceTime = targetAppearanceTime[i][1];
       }
    }

    return maxTargetAppearanceTime;
}
