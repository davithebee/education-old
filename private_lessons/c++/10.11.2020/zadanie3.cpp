#include <iostream>
using namespace std;

int zadanie3(int tab[21][21]){
int count_invalid_col = 0, count_invalid_row = 0;
int invalid_sum = 0, sum = 0;

for(int w=0; w<20; w++){
  sum = 0;
    for(int k=0; k<20; k++){
      sum += tab[w][k];
    }
    if(tab[w][20] != sum%2) count_invalid_col++;
}

for(int k=0; k<20; k++){
  sum = 0;
  for(int w=0; w<20; w++){
    sum += tab[w][k];
  }
  if(tab[20][k] != sum%2) count_invalid_row++;
}

invalid_sum = count_invalid_col + count_invalid_row;

if(count_invalid_col==0 && count_invalid_row==0) return 0;
if(count_invalid_col<=1 && count_invalid_row<=1) return 1;
return invalid_sum;
}
