#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    std::fstream in, out;
    in.open("wykreslanka.txt", std::ios::in);
    out.open("wyniki4.txt", std::ios::out);

    std::string tab[100];

    if(in.good())
    {
        for(int i{0}; i<100; i++)
        {
            in >> tab[i];
        }

        std::string checked_string;
        std::vector<int> wiersz;
        std::vector<int> kolumna;

        for(int i{0}; i<100; i++)
        {
            checked_string = tab[i];

            if(checked_string.find("matura") >= 0 && checked_string.find("matura") <= 199)
            {
                wiersz.push_back(i);
            }
        }

        for(int i{0}; i<200; i++)
        {
            checked_string = "";

            for(int j{0}; j<100; j++)
            {
                checked_string += tab[j][i];
            }

            if(checked_string.find("matura") >= 0 && checked_string.find("matura") <= 99)
            {
                kolumna.push_back(i);
            }
        }

        out << "Zadanie 1" << '\n'
            << "---------" << '\n'
            << "Wiersze: " << '\n';

        for(int i{0}; i<wiersz.size(); i++)
        {
            out << wiersz[i] << " ";
        }

        out << '\n'
            << "Kolumny: " << '\n';

        for(int i{0}; i<kolumna.size(); i++)
        {
            out << kolumna[i] << " ";
        }


        int ciag_max{0};
        int ciag_counter{1};

        for(int i{0}; i<100; i++)
        {
            for(int j{1}; j<200; j++)
            {
                if(tab[i][j] == tab[i][j-1])
                {
                    ciag_counter += 1;
                }

                if(tab[i][j] != tab[i][j-1])
                {
                    if(ciag_counter > ciag_max)
                    {
                        ciag_max = ciag_counter;
                    }

                    ciag_counter = 1;
                }

                if(ciag_counter > ciag_max && j == 199)
                {
                    ciag_max = ciag_counter;
                }
            }

            ciag_counter = 1;
        }

        out << '\n' << '\n'
            << "Zadanie 2" << '\n'
            << "---------" << '\n'
            << "Dlugosc najdluzszego podciagu: " << ciag_max << '\n'
            << "Wystepuje w:" << '\n';

        for(int i{0}; i<100; i++)
        {
            for(int j{1}; j<200; j++)
            {

                if(tab[i][j] == tab[i][j-1])
                {
                    ciag_counter += 1;
                }

                if(tab[i][j] != tab[i][j-1])
                {
                    if(ciag_counter == 10)
                    {
                        out << i << '\n';
                    }

                    ciag_counter = 1;
                }

                if(ciag_counter == ciag_max && j == 199)
                {
                    out << i << '\n';
                }
            }

            ciag_counter = 1;
        }

        std::string alfabet{"abcdefghijklmnopqrstuvwxyz"};
        sort(alfabet.begin(), alfabet.end());
        std::string fragment{""};

        for(int i{0}; i < 99; i++)
        {
            for(int j{0}; j < 187; j++)
            {
                fragment = "";

                for(int k{0}; k < 13; k++)
                {
                    fragment += tab[i][j+k];
                }
                for(int k{0}; k < 13; k++)
                {
                    fragment += tab[i+1][j+k];
                }
                sort(fragment.begin(), fragment.end());
                if(fragment == alfabet)
                {
                    std::cout << j << " - " << i << '\n' << '\n';
                }
            }
        }

        for(int j{0}; j < 87; j++)
        {
            for(int i{0}; i < 199; i++)
            {
                fragment = "";

                for(int k{0}; k < 13; k++)
                {
                    fragment += tab[j+k][i];
                }
                for(int k{0}; k < 13; k++)
                {
                    fragment += tab[j+k][i+1];
                }
                sort(fragment.begin(), fragment.end());
                if(fragment == alfabet)
                {
                    std::cout << j << " - " << i << '\n' << '\n';
                }
            }
        }
    }
    else
    {
        std::cout << "ERROR READING FILE";
    }

    return 0;
}
