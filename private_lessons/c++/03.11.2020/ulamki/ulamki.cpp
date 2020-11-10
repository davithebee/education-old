#include <iostream>
#include <fstream>
using namespace std;

int NWD(int a, int b){
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

//-------ZADANIE-1---------------------------

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

//-------ZADANIE-2---------------------------

int count=0;
for(int i=0; i<1000; i++){
  if(NWD(licz[i],mian[i])==1) count++;
}

wyniki<<"ZADANIE 2"<<endl;
wyniki<<"Ilosc nieskracalnych ulamkow: "<<count<<endl<<endl;

//-------ZADANIE-3---------------------------

int suma=0;
for(int i=0; i<1000; i++){
  suma+=(licz[i]/NWD(licz[i],mian[i]));
  //np nwd z 15/3 jest rowne 5, wiec 15/5=3 (3/1)
}

wyniki<<"ZADANIE 3"<<endl;
wyniki<<"Suma licznikow ulamkow nieskracalnych: "<<suma;

return 0;
}
