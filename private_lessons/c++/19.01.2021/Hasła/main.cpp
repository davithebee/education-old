#include <iostream>
#include <fstream>

int onlyNumerical(std::string passwords[200]);
int multipleUses(std::string passwords[200]);

int main()
{
    std::fstream in, out;
    in.open("hasla.txt",std::ios::in);
    out.open("wyniki.txt",std::ios::out);

    std::string passwords[200];

    if(in.good())
    {
        for(int i{0}; i<200; i++)
            {
                in >> passwords[i];
            }
        in.close();


        out << "Zadanie 1" << '\n'
            << "Liczba hase³ z³o¿onych \n"
            << "ze znaków numerycznych: " << onlyNumerical(passwords) << '\n' << '\n';

        out << "Zadanie 2" << '\n';
        out.close();
        multipleUses(passwords);
    }
    else
    {
        std::cout << "fstream ERROR";
    }

    return 0;
}
