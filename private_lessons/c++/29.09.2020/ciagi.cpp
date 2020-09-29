#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool check_ciag(int*tab, int r) //sprawdza czy ciag jest arytmetyczny
{
    int roznica = tab[1] - tab[0];
    for(int i=1; i<=r-2; i++){
        if(tab[i+1] - tab[i] != roznica) return false;
    }
    return true;
}

int check_szescian(int*tab, int r)
{
    for(int i=r-1; i>=0; i--){
        for(int j=1; j<=100; j++){
            if(j*j*j==tab[i])
            return tab[i];
        }
    }
    return 0;
}

int main()
{
    fstream in,in3,out,out2,out3;
    in.open("ciagi.txt",ios::in);
    in3.open("bledne.txt",ios::in);
    out.open("wynik1.txt",ios::out);
    out2.open("wynik2.txt",ios::out);
    out3.open("wynik3.txt",ios::out);

    int r, licz=0, maxi=0;
    vector<int> v;

    if(in.good()){
        for(int i=0; i<100; i++){
            in>>r;
            int *tab = new int[r]; //tablica dynamiczna

            for(int j=0; j<r; j++){
                in>>tab[j];         //wczytujemy wartosci do tablicy
            }

            licz+=check_ciag(tab, r);
            if(check_ciag(tab, r)){ //sprawdzanie najwiekszej roznicy
                if(tab[1]-tab[0]>maxi)
                maxi=tab[1]-tab[0];
            }

            //-------------------------------------------------------------------------

            if(check_szescian(tab, r) != 0){
                v.push_back(check_szescian(tab, r));
            }

            delete []tab; //zwolnienie pamiêci
        }
    } else cout<<"ERROR - BLAD ODCZYTU";

    out<<"Zadanie 1"<<endl;
    out<<"Liczba ciagow arytmetycznych: "<<licz<<endl;
    out<<"Najwieksza roznica: "<<maxi<<endl<<endl;

    out2<<"Zadanie 2"<<endl;
    for(int i=0; i<v.size(); i++) out2<<v[i]<<endl;

    //-------ZADANIE_3----------------------------------------------------------------

     vector<int> roznice;

        if(in3.good()){
        for(int i=0; i<20; i++){
            in>>r;
            int *tab = new int[r]; //tablica dynamiczna

            for(int j=0; j<r; j++){
                in>>tab[j];         //wczytujemy wartosci do tablicy
            }

            for(int k=0; k<r-1; k++){
                v.push_back(tab[k+1]-tab[k]);
            }

            //DOKONCZ PODPUNKT 3!!

            delete []tab; //zwolnienie pamiêci
        }
    } else cout<<"ERROR - BLAD ODCZYTU";

    return 0;
}
