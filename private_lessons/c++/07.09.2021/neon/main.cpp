#include <iostream>
#include <fstream>

int main()
{
    std::fstream in,out;
    in.open("instrukcje.txt", std::ios::in);
    out.open("wyniki4.txt", std::ios::out);

    if(in.good())
    {
        int counter{0};
        std::string currentWord;

        while(!in.eof())
        {
            in >> currentWord;
            if(currentWord == "DOPISZ")
            {
                counter++;
            }
            if(currentWord == "USUN" && counter > 0)
            {
                counter--;
            }
        }

        out << "ZADANIE 1" << '\n'
            << "Dlugosc napisu wynosi: " << counter << '\n';

        //-----------------------------------------------------------------

        in.seekg(0);
        std::string instrukcje[2000];
        char znaki[2000];
        int maxCiag{0};
        std::string maxCiagSlowo;
        int ciag{1};

        for(int i{0}; i < 2000; i++)
        {
            in >> instrukcje[i];
            in >> znaki[i];
        }

        for(int i{1}; i < 2000; i++)
        {
            if(instrukcje[i-1] == instrukcje[i])
            {
                ciag++;
                if(ciag > maxCiag)
                {
                    maxCiag = ciag;
                    maxCiagSlowo = instrukcje[i];
                }
            }
            else
            {
                ciag = 1;
            }
        }

        out << "ZADANIE 2" << '\n'
            << "Dlugosc maksymalnego ciagu wynosi: " << maxCiag << '\n'
            << "Jest to slowo: " << maxCiagSlowo << '\n';

        //-----------------------------------------------------------------

        int alfabet[26] {};
        int maxAlfabet{0};
        int maxAlfabetIndex{0};

        for(int i{0}; i < 2000; i++)
        {
            if(instrukcje[i] == "DOPISZ")
            {
                alfabet[(int)znaki[i]-65]++;
            }
        }

        for(int i{0}; i < 26; i++)
        {
            if(alfabet[i]>maxAlfabet)
            {
                maxAlfabet = alfabet[i];
                maxAlfabetIndex = i;
            }
        }

        out << "ZADANIE 3" << '\n'
            << "Najczesciej dopisywana litera to: " << char(maxAlfabetIndex + 65) << '\n'
            << "Wystepuje ona: " << maxAlfabet << '\n';

        //-----------------------------------------------------------------

        std::string wholeText{""};
        int przesunIndex{};

        for(int i{0}; i < 2000; i++)
        {
            if(instrukcje[i] == "DOPISZ")
            {
                wholeText+=znaki[i];
            }
            if(instrukcje[i] == "ZMIEN")
            {
                wholeText[wholeText.size()-1] = znaki[i];
            }
            if(instrukcje[i] == "USUN")
            {
                wholeText.erase(wholeText.size()-1);
            }
            if(instrukcje[i] == "PRZESUN")
            {
                przesunIndex = wholeText.find(znaki[i]);
                if(przesunIndex >= 0)
                {
                    if(int(znaki[i]) == 90)
                    {
                        wholeText[przesunIndex] = 'A';
                    }
                    else
                    {
                        wholeText[przesunIndex] = char(int(znaki[i])+1);
                    }
                }
            }
        }

        out << "ZADANIE 4" << '\n'
            << wholeText;

    }
    else
    {
        std::cout<<"ERROR LOADING FILE";
    }

    return 0;
}
