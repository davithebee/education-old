#include <iostream>
#include <fstream>
#include "zadanie3.cpp"

using namespace std;

void draw(int first[][20], fstream &wyniki){
  for(int w=0; w<20; w++){
      for(int k=0; k<20; k++){
        wyniki<<first[w][k];
        }
      wyniki<<endl;
      }
  wyniki<<endl<<endl;
}

int count_black(int tab[][21]){
  int count=0;
    for(int w=0; w<20; w++){
      for(int k=0; k<20; k++){
            if(tab[w][k]==1) count++;
        }
      }
  return count;
}

bool is_recursion(int tab[][21]){
    for(int w=0; w<10; w++){
      for(int k=0; k<10; k++){
            if(tab[w][k]!=tab[w][k+10]) return false;
            if(tab[w][k]!=tab[w+10][k]) return false;
            if(tab[w][k]!=tab[w+10][k+10]) return false;
        }
      }

return true;
}

int main()
{
  fstream dane_obrazki, wyniki;
  int tab[21][21];
  char z;
  int for_count=0;

  dane_obrazki.open("dane_obrazki.txt", ios::in);
  wyniki.open("wyniki.txt", ios::out);

  int rewers_count=0, rewers_maks=0, recursion_count=0;
  int first[20][20];
  int poprawny_count = 0, naprawialny_count = 0, nienaprawialny_count = 0;
  int max_invalid_sum = 0;

  if(dane_obrazki.good()){
    for(int i=0; i<200; i++){
    for_count=0;
      for(int w=0; w<21; w++){
          for(int k=0; k<21; k++){
            if(for_count<440){
            dane_obrazki>>z;
            for_count++;
            tab[w][k]=(int)z-48; //(ascii)
          } else tab[w][k]=5;
          }
      }
      if(count_black(tab)>200){
        rewers_count++;
        if(count_black(tab)>rewers_maks) rewers_maks=count_black(tab);
      }

      if(is_recursion(tab)){
        recursion_count++;
        if(recursion_count==1){
            for(int w=0; w<20; w++){
                for(int k=0; k<20; k++){
                    first[w][k]=tab[w][k];
                }
            }
        }
      }

      if(zadanie3(tab) == 0) poprawny_count++;
      else if(zadanie3(tab) == 1) naprawialny_count++;
      else{
        nienaprawialny_count++;
        if(zadanie3(tab) > max_invalid_sum) max_invalid_sum=zadanie3(tab);
      }

    }
  }
  else cout<<"ERROR";

  wyniki<<"ZADANIE 1"<<endl;
  wyniki<<"Liczba rewersów: "<<rewers_count<<endl;;
  wyniki<<"Maksymalna liczba czarnych pikseli: "<<rewers_maks<<endl<<endl;

  wyniki<<"ZADANIE 2"<<endl;
  wyniki<<"Liczba obrazków rekurencyjnych: "<<recursion_count<<endl;
  wyniki<<"Pierwszy obrazek rekurencyjny: "<<endl<<endl;
  draw(first, wyniki);
  wyniki<<endl<<endl;

  wyniki<<"ZADANIE 3"<<endl;
  wyniki<<"Liczba poprawnych: "<<poprawny_count<<endl;
  wyniki<<"Liczba naprawialnych: "<<naprawialny_count<<endl;
  wyniki<<"Liczba nienaprawialnych: "<<nienaprawialny_count<<endl;
  wyniki<<"Największa liczba błędów bitów parzystości: "<<max_invalid_sum;

  return 0;
}
