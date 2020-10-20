#include <iostream>
#include <fstream>

using namespace std;

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

      cout<<min1;

    }else{
      cout<<"ERROR";
    }

    return 0;
}
