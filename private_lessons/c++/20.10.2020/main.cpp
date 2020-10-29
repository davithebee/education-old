#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int potega(int a, int b){
  int w=1;
  for(int i=0; i<b; i++){
    w*=a;
  }
  return w;
}

int horner(string liczba, int base)
{
  int ujemna=1;
  int y;

  if(liczba[0]=='-'){
    liczba=liczba.substr(1,liczba.size());
    ujemna=-1;
  }

  y=(int)liczba[0]-48;

  for(int i=1; i<liczba.size(); i++){
    y=y*base+(int)liczba[i]-48;
  }

  return y*ujemna;
}

//-------------------------ZAD1----------------------------------
void decimal_to_binary(fstream &wynik, int liczba){
  vector<int> bin;
  char ujemna='-';

  if(liczba<0){
    wynik<<ujemna;
    liczba*=-1;
  }

  while(liczba>0){
    bin.push_back(liczba%2);
    liczba/=2;
  }

  for(int i=bin.size()-1; i>=0; i--){
    wynik<<bin[i];
  }
  wynik<<endl;
}
//--------------------------------------------------------------



int main()
{
    int czas1[1095], czas2[1095], czas3[1095];
    int temp1[1095], temp2[1095], temp3[1095];
    string czas_tmpr, temp_tmpr;

    fstream plik1, plik2, plik3, wynik;
    plik1.open("dane_systemy1.txt", ios::in);
    plik2.open("dane_systemy2.txt", ios::in);
    plik3.open("dane_systemy3.txt", ios::in);
    wynik.open("wynik.txt", ios::out);

    if(plik1.good()){

      for(int i=0; i<1095; i++){
        plik1>>czas_tmpr;
        czas1[i]=horner(czas_tmpr,2);
        plik1>>temp_tmpr;
        temp1[i]=horner(temp_tmpr,2);

        plik2>>czas_tmpr;
        czas2[i]=horner(czas_tmpr,4);
        plik2>>temp_tmpr;
        temp2[i]=horner(temp_tmpr,4);

        plik3>>czas_tmpr;
        czas3[i]=horner(czas_tmpr,8);
        plik3>>temp_tmpr;
        temp3[i]=horner(temp_tmpr,8);
      }

      int min1=temp1[0],min2=temp2[0],min3=temp3[0];

      for(int i=1; i<1095; i++){
        if(temp1[i]<min1) min1=temp1[i];
        if(temp2[i]<min2) min2=temp2[i];
        if(temp3[i]<min3) min3=temp3[i];
      }

//-------------------------ZAD2----------------------------------
      int stan=12, licznik=0;

      for(int i=0; i<1095; i++){
        if(czas1[i]!=stan && czas2[i]!=stan && czas3[i]!=stan){
          licznik++;
        }
        stan+=24;
      }
//---------------------------------------------------------------

//-------------------------ZAD3----------------------------------

      int maks_1=temp1[0], maks_2=temp2[0], maks_3=temp3[0];
      int dni_rekordowe=1;

      for(int i=1; i<1095; i++){
        int rekord=0;

        if(temp1[i]>maks_1){
          maks_1=temp1[i];
          rekord++;
        }
        if(temp2[i]>maks_2){
          maks_2=temp2[i];
          rekord++;
        }
        if(temp3[i]>maks_3){
          maks_3=temp3[i];
          rekord++;
        }
        if(rekord>0){
          dni_rekordowe++;
        }

      }

//---------------------------------------------------------------

//-------------------------ZAD4----------------------------------
      int rij, skok, maks_skok=0;
      double wynik_dzielenia;

      for(int i=0; i<1095; i++){
        for(int j=i+1; j<1095; j++){
          rij=potega((temp1[i]-temp1[j]),2);
          wynik_dzielenia=(double)rij/abs(i-j);
          skok=ceil(wynik_dzielenia);
          if(skok>maks_skok) maks_skok=skok;
        }
      }

//---------------------------------------------------------------

    wynik<<"Zadanie 1"<<endl;
    decimal_to_binary(wynik, min1);
    decimal_to_binary(wynik, min2);
    decimal_to_binary(wynik, min3);
    wynik<<endl;

    wynik<<"Zadanie 2"<<endl;
    wynik<<licznik<<endl;
    wynik<<endl;

    wynik<<"Zadanie 3"<<endl;
    wynik<<dni_rekordowe<<endl;
    wynik<<endl;

    wynik<<"Zadanie 4"<<endl;
    wynik<<maks_skok<<endl;

    }else{
      cout<<"ERROR";
    }

    return 0;
}
