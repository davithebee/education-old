//Specification:
//Data INPUT - one number above or equal to 100
//Data OUTPUT - string telling you if inputed number is even or odd
//-----------------------------------------------------------------
//Block Diagram:
//
// [INPUT A (INT)]
//       |
//       V
// [CHECK IF >= 100] -> [IF NO - OUTPUT "ERROR"] -> RETURN 0
//       |
//       V
// [IF YES - CHECK IF EVEN] -> [IF NO - OUTPUT "ODD"] -> RETURN 0
//       |
//       V
// [IF YES - OUTPUT "EVEN"] -> RETURN 0
//-----------------------------------------------------------------

//libraries
#include<iostream>
//namespace
using namespace std;
//function that checks if a number is even or odd
check(int x){
  if(x%2==0) cout<<"IT'S AN EVEN NUMBER";
  else cout<<"IT'S AN ODD NUMBER";
}
//main program
int main(){
//integer that holds user's input
int x;
//program description
cout<<"PROGRAM THAT CHECKS IF INPUTED NUMBER IS EVEN OR ODD IF IT IS EQUAL OR ABOVE 100\n";
//call to input
cout<<"INPUT A NUMBER: ";
//save input to integer x
cin>>x;
//check if the input meets the specification
if(x>=100){
//if yes - call function
  check(x);
}
//if not - abort
else cout<<"ERROR - THIS NUMBER IS NOT EQUAL OR ABOVE 100";
//return 0 - program finished work successfully
return 0;
}
