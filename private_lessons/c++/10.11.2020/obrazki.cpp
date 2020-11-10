#include <iostream>
#include <fstream>

using namespace std;

void draw(int tab[][21]){
  for(int w=0; w<21; w++){
      for(int k=0; k<21; k++){
        cout<<tab[w][k];
        }
      cout<<endl;
      }
  cout<<endl<<endl;
}

int count_black(int tab[][21]){
    for(int w=0; w<20; w++){
      for(int k=0; k<20; k++){
            //-----tutaj rob dalej
        }
      }
}

int main()
{
  fstream dane_obrazki, wyniki;
  int tab[21][21];
  char z;
  int for_count=0;

  dane_obrazki.open("dane_obrazki.txt", ios::in);
  wyniki.open("wyniki.txt", ios::out);

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
    draw(tab);
    }
  }
  else cout<<"ERROR";
}
