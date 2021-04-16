#include <iostream>
#include <fstream>
#include <vector>

struct galeria
{
    std::string kod_kraju;
    std::string miasto;
    int a[70]; //dlugosc lokalu
    int b[70]; //szerokosc lokalu
};

int main()
{
    std::fstream in, out1, out2a, out2b, out3;
    in.open("galerie.txt", std::ios::in);
    out1.open("wynik_1.txt", std::ios::out);
    out2a.open("wynik_2a.txt", std::ios::out);
    out2b.open("wynik_2b.txt", std::ios::out);
    out3.open("wynik_3.txt", std::ios::out);

    if(in.good())
    {
        galeria galerie[50];

        for(int i{0}; i<50; i++)
        {
            in >> galerie[i].kod_kraju;
            in >> galerie[i].miasto;
            for(int j{0}; j<70; j++)
            {
                in >> galerie[i].a[j];
                in >> galerie[i].b[j];
            }
        }

        //-----------------------------------------------------------------------

        std::vector<std::string> unikatowe_kody;
        std::vector<int> liczba_miast;
        bool flaga{false};

        for(int i{0}; i<50; i++)
        {
            flaga = false;
            for(int j{0}; j<unikatowe_kody.size(); j++)
            {
                if(galerie[i].kod_kraju == unikatowe_kody[j])
                {
                    liczba_miast[j]++;
                    flaga = true;
                }
            }
            if(flaga == false)
            {
                unikatowe_kody.push_back(galerie[i].kod_kraju);
                liczba_miast.push_back(1);
            }
        }

        for(int i{0}; i<unikatowe_kody.size(); i++)
        {
            out1 << unikatowe_kody[i] << " " << liczba_miast[i] << '\n';
        }

        //-----------------------------------------------------------------------

        int liczba_lokali{0};
        int j{0};
        int powierzchnia_galerii{0};
        int max_powierzchnia{0};
        std::string nazwa_max_powierzchni;
        int min_powierzchnia{INT_MAX};
        std::string nazwa_min_powierzchni;

        for(int i{0}; i<50; i++)
        {
            liczba_lokali = 0;
            j = 0;
            powierzchnia_galerii = 0;
            while(galerie[i].a[j] != 0 && j<70)
            {
                powierzchnia_galerii += galerie[i].a[j]*galerie[i].b[j];
                liczba_lokali++;
                j++;
            }
            if(powierzchnia_galerii > max_powierzchnia)
            {
                max_powierzchnia = powierzchnia_galerii;
                nazwa_max_powierzchni = galerie[i].miasto;
            }
            if(powierzchnia_galerii < min_powierzchnia)
            {
                min_powierzchnia = powierzchnia_galerii;
                nazwa_min_powierzchni = galerie[i].miasto;
            }

            out2a << galerie[i].miasto << " " << powierzchnia_galerii << " " << liczba_lokali << '\n';
        }

        out2b << nazwa_max_powierzchni << " " << max_powierzchnia << '\n';
        out2b << nazwa_min_powierzchni << " " << min_powierzchnia << '\n';


    }
    else
    {
        std::cout << "FSTREAM ERROR";
        out1 << "FSTREAM ERROR";
        out2a << "FSTREAM ERROR";
        out2b << "FSTREAM ERROR";
        out3 << "FSTREAM ERROR";
    }


    return 0;
}
