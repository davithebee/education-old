#include <iostream>
#include <algorithm>

bool isAnagram(std::string leftPwd, std::string rightPwd)
{
    if(leftPwd.size() != rightPwd.size())
        return false;

    std::sort(leftPwd.begin(),leftPwd.end());
    std::sort(rightPwd.begin(),rightPwd.end());

    if(leftPwd != rightPwd)
        return false;

    return true;
}
