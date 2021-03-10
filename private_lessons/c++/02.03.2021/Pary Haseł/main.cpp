#include <iostream>
#include <fstream>

bool isAnagram(std::string leftPwd, std::string rightPwd);
bool triples(std::string pwd, int *ABC_count, int *ABC_fileCount);

int main()
{
    std::fstream in, out;
    in.open("hasla.txt", std::ios::in);
    out.open("wyniki.txt", std::ios::out);
    int ABC_count[6]{0};
    int ABC_fileCount[6]{0};

    if(in.good())
    {
        std::string leftPwd[1000];
        std::string rightPwd[1000];
        int anagramCount{0};
        int alphabetLetterAmount[26]{0};

        for(int i{0}; i < 1000; i++)
        {
            in >> leftPwd[i];
            for(int j{0}; j < leftPwd[i].size(); j++)
                {
                    alphabetLetterAmount[(int)leftPwd[i][j] - 65]++;
                }
            in >> rightPwd[i];
            for(int j{0}; j < rightPwd[i].size(); j++)
                {
                    alphabetLetterAmount[(int)rightPwd[i][j] - 65]++;
                }
        }

        /*for(int i{0}; i < 26; i++)
            {
                std::cout << char(i+65) << ": " << alphabetLetterAmount[i] << '\n';
            }*/

        int mostFreqLetter{0};
        int leastFreqLetter{54056};

        for(int i{0}; i < 26; i++)
            {
                if(alphabetLetterAmount[i] > mostFreqLetter)
                {
                    mostFreqLetter = alphabetLetterAmount[i];
                }

                if(alphabetLetterAmount[i] < leastFreqLetter)
                {
                    leastFreqLetter = alphabetLetterAmount[i];
                }
            }

        int a{0};
        int b{0};
        int c{0};
        int d{0};

        for(int i{0}; i < 26; i++)
            {
                if(alphabetLetterAmount[i] == mostFreqLetter)
                {
                    a++;
                    c = i;
                }
                if(alphabetLetterAmount[i] == leastFreqLetter)
                {
                    b++;
                    d = i;
                }
            }

        /*std::cout << mostFreqLetter <<'\n';
        std::cout << leastFreqLetter << '\n';*/

        for(int i{0}; i < 1000; i++)
        {
            anagramCount += isAnagram(leftPwd[i],rightPwd[i]);
        }

        out << "Zadanie 1 \n"
            << "Ilość anagramów: "
            << anagramCount << '\n' << '\n';

        out << "Zadanie 2 \n"
            << "Hasła zawierające co najmniej dwie trójki: \n";

        for(int i{0}; i < 1000; i++)
        {
            if(triples(leftPwd[i], ABC_count, ABC_fileCount))
            {
                out << leftPwd[i] << '\n' << '\n';
            }
            if(triples(rightPwd[i], ABC_count, ABC_fileCount))
            {
                out << rightPwd[i] << '\n' << '\n';
            }
        }

        out << "ABC: " << ABC_fileCount[0] << '\n';
        out << "ACB: " << ABC_fileCount[1] << '\n';
        out << "BAC: " << ABC_fileCount[2] << '\n';
        out << "BCA: " << ABC_fileCount[3] << '\n';
        out << "CAB: " << ABC_fileCount[4] << '\n';
        out << "CBA: " << ABC_fileCount[5] << '\n' << '\n';

        out << "Zadanie 3 \n";

        if(a == 1)
        {
           out << "Najczęściej wystepująca litera: " << char(c + 65) << '\n';
        }
        else
        {
           out << "Brak najczęściej wystepującej litery.\n";
        }
        if(b == 1)
        {
           out << "Najrzadziej wystepujaca litera: " << char(d + 65) << '\n';
        }
        else
        {
           out << "Brak najrzadziej wystepujacej litery.\n";
        }



        return 0;
    }

    std::cout << "FSTREAM ERROR";
    return 0;
}
