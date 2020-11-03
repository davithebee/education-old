#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int horner(string x, int y)
{
int z = (int)x[0]-48;
for(int i=1; i<x.size(); i++){
  z=z*y+(int)x[i]-48;
}
return z;
}

bool czy_polpierwsza(int x){
int liczba_czynnikow=0;
int czynnik=2;

while(x>1){
  while(x%czynnik==0){
    liczba_czynnikow++;
    x/=czynnik;
    if(liczba_czynnikow>2) return false;
  }
  czynnik++;
}

if(liczba_czynnikow==2) return true;
return false;
}

//--------------------------------------------------------------------------------

int main()
{
    string ciag_full, ciag_left, ciag_right;
    int for_check, two_ones_counter=0, two_ones_good_counter=0, ciag_dec, ciag_dec_licz=0, ciag_dec_max=0, ciag_dec_min=horner("111111111111111111",2);
    vector<string> dwucykliczne;

    fstream ciagi, wyniki_ciagi;
    ciagi.open("ciagi.txt", ios::in);
    wyniki_ciagi.open("wyniki_ciagi.txt", ios::out);

    if(ciagi.good()){

//---------------------ZAD1--------------------------------------------------------------------------------------

      for(int i=0; i<1000; i++){

        ciagi>>ciag_full;

        if(ciag_full.length()%2==0){
        ciag_left = ciag_full.substr(0, ciag_full.length()/2);
        ciag_right = ciag_full.substr(ciag_full.length()/2);
        for_check=0;

        for(int j=0; j<ciag_left.length(); j++){
          if(ciag_left[j]==ciag_right[j]){
            for_check++;
          }
        }

        if(for_check==ciag_left.length()){
          dwucykliczne.push_back(ciag_full);
        }

        }
//---------------------ZAD2--------------------------------------------------------------------------------------
        two_ones_counter=0;

        for(int i=0; i<ciag_full.length()-1; i++){
          if(ciag_full[i] == '1' && ciag_full[i+1] == '1') two_ones_counter++;
        }

        if(two_ones_counter==0) two_ones_good_counter++;

//---------------------ZAD3--------------------------------------------------------------------------------------

      ciag_dec = horner(ciag_full,2);
      if(czy_polpierwsza(ciag_dec)) ciag_dec_licz++;
      if(czy_polpierwsza(ciag_dec)){
        if(ciag_dec>ciag_dec_max) ciag_dec_max=ciag_dec;
        if(ciag_dec<ciag_dec_min) ciag_dec_min=ciag_dec;
      }
      }
    }




wyniki_ciagi<<"ZADANIE 1"<<endl<<endl;
for(int i=0; i<dwucykliczne.size(); i++){
  wyniki_ciagi<<i+1<<".  "<<dwucykliczne[i]<<endl;
}
wyniki_ciagi<<endl;

wyniki_ciagi<<"ZADANIE 2"<<endl<<endl;
wyniki_ciagi<<two_ones_good_counter<<endl<<endl;

wyniki_ciagi<<"ZADANIE 3"<<endl<<endl;
wyniki_ciagi<<ciag_dec_licz<<endl<<endl;
wyniki_ciagi<<ciag_dec_max<<endl;
wyniki_ciagi<<ciag_dec_min<<endl;

    return 0;
}
