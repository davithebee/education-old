#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    string ciag_full, ciag_left, ciag_right;
    int for_check, two_ones_counter=0, two_ones_good_counter=0;
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

        for(int i=0; i<ciag_full.length()-2; i++){
          if(ciag_full[0] == 1 && ciag_full[1] == 1) two_ones_counter++;
        }
        if(ciag_full[ciag_full.length()-2] == ciag_full[ciag_full.length()-1]) two_ones_counter++;

        if(two_ones_counter==0) two_ones_good_counter++;
      }
    }




wyniki_ciagi<<"ZADANIE 1"<<endl<<endl;
for(int i=0; i<dwucykliczne.size(); i++){
  wyniki_ciagi<<i+1<<".  "<<dwucykliczne[i]<<endl;
}
wyniki_ciagi<<endl;

wyniki_ciagi<<"ZADANIE 2"<<endl<<endl;
wyniki_ciagi<<two_ones_good_counter<<endl<<endl;

    return 0;
}
