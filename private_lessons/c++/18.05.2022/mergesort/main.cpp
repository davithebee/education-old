#include <iostream>
#include <ctime>
#include <cstdlib>

void scal(int*t, int L, int P)
{
    int t_pom[10];

    for(int i{0}; i<10; i++)
    {
        t_pom[i] = t[i];
    }

    int S = (L+P)/2;

    int i_L {L};
    int i_P {S+1};
    int i   {L};

    while(i_L <= S && i_P <= P)
    {
        if(t_pom[i_L] < t_pom[i_P])
        {
            t[i] = t_pom[i_L];
            i_L++;
            i++;
        }
        else
        {
            t[i] = t_pom[i_P];
            i_P++;
            i++;
        }
    }

    while(i_L <= S)
    {
        t[i] = t_pom[i_L];
        i_L++;
        i++;
    }

    while(i_P <= P)
    {
        t[i] = t_pom[i_P];
        i_P++;
        i++;
    }
}

void mergesort(int*t, int L, int P)
{
    int S{};

    if(L < P)
    {
        S = (L+P)/2;

        mergesort(t, L, S);
        mergesort(t, S+1, P);

        scal(t, L, P);
    }
}

int main()
{
    int tab[10];

    srand(time(NULL));

    for(int i{0}; i<10; i++)
    {
        tab[i] = ((rand()%101)-50);

        std::cout << tab[i] << ", ";
    }

    std::cout << '\n' << "-----" << '\n';

    mergesort(tab, 0, 9);

    for(int i{0}; i<10; i++)
    {
        std::cout << tab[i] << ", ";
    }

    return 0;
}
