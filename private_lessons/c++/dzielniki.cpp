#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int licz_dzielniki(int x){
    int licz=2;
    for(int i=2; i<x; i++){
        if(x%i==0) licz++;
    }
    return licz;
}

void wypisz_dzielniki(int x, fstream &out){
     for(int i=1; i<=x; i++){
        if(x%i==0) out<<i<<" ";
    }
    out<<endl<<endl;
}

int NWD(int a,int b){
    int r;
    while(b>0){
    r=a%b;
    a=b;
    b=r;
    }
    return a;
}

int main()
{
    fstream in, out;
    in.open("liczby.txt",ios::in);
    out.open("wyniki.txt",ios::out);

    vector<int> tab, tab_zad3;
    int x;

    for(int i=0;i<200;i++){
        in>>x;
        tab_zad3.push_back(x);
        if(x<1000) tab.push_back(x);
    }

    out<<"Zadanie 1 \n";
    out<<"Liczb mniejszych niz tysiac: "<<tab.size()<<endl;
    out<<"Ostatnia: "<<tab[tab.size()-1];
    out<<endl;
    out<<"Przedostatnia: "<<tab[tab.size()-2];
    out<<endl<<endl;

    in.seekg(0);

    out<<"Zadanie 2 \n";

    for(int i=0;i<200;i++){
        in>>x;
        if(licz_dzielniki(x)==18){
            out<<x<<": \n";
            wypisz_dzielniki(x, out);
        }
    }

    out<<endl<<endl;

    bool check;
    int maksi=0;

    out<<"Zadanie 3 \n";
    for(int i=0; i<tab_zad3.size(); i++){
        check=true;

        for(int j=0; j<tab_zad3.size(); j++){
            if(i!=j && NWD(tab_zad3[i],tab_zad3[j])>1){
                check=false;
            }
        }
        if(check==true && tab_zad3[i]>maksi) maksi=tab_zad3[i];
    }
    out<<maksi;

    return 0;
}
