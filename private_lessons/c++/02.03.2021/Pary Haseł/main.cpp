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

        for(int i{0}; i < 1000; i++)
        {
            in >> leftPwd[i];
            in >> rightPwd[i];
        }


        for(int i{0}; i < 1000; i++)
        {
            anagramCount += isAnagram(leftPwd[i],rightPwd[i]);
        }

        out << "Zadanie 1 \n"
            << "Iloœæ anagramów: "
            << anagramCount << '\n' << '\n';

        out << "Zadanie 2 \n"
            << "Has³a zawieraj¹ce co najmniej dwie trójki: \n";

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
        out << "CBA: " << ABC_fileCount[5] << '\n';

        return 0;
    }

    std::cout << "FSTREAM ERROR";
    return 0;
}
