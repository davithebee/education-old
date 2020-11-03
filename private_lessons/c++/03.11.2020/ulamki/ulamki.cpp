#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int licz[1000], mian[1000];
  fstream dane_ulamki, wyniki;

//-------WCZYTANIE-Z-PLIKU-------------------
  dane_ulamki.open("dane_ulamki.txt", ios::in);
  wyniki.open("wyniki.txt", ios::out);

  if(dane_ulamki.good()){

  for(int i=0; i<1000; i++){
    dane_ulamki>>licz[i]>>mian[i];
  }
  }
  else{
    cout<<"ERROR";
    wyniki<<"ERROR";
  }

  dane_ulamki.close();
//--------------------------------------------

int licz_min=licz[0];
int mian_min=mian[0];

for(int i=1; i<1000; i++){
  if(licz[i]*mian_min < licz_min*mian[i]){
    licz_min=licz[i];
    mian_min=mian[i];
  }
  if(licz_min*mian[i]==licz[i]*mian_min){
    if(mian[i]<mian_min){
      licz_min=licz[i];
      mian_min=mian[i];
    }
  }
  }

wyniki<<"ZADANIE 1"<<endl;
wyniki<<"Licznik minimalny: "<<licz_min<<endl;
wyniki<<"Mianownik minimalny: "<<mian_min<<endl<<endl;

return 0;
}
