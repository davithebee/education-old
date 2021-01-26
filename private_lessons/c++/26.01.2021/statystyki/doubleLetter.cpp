#include <iostream>

int doubleLetter(std::string *words)
{

    int wordsWithDoubleLetters{0};

    for(int i{0}; i<1876; i++)
    {
        for(int characterIndex{0}; characterIndex < words[i].size()-1; characterIndex++)
        {
            if(words[i][characterIndex] == words[i][characterIndex+1])
            {
                wordsWithDoubleLetters++;
                characterIndex = words[i].size();
            }
        }
    }

    return wordsWithDoubleLetters;
}
