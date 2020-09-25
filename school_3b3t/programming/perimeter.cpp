//Pseudo-code:
// 1. Input three values corresponding to the triangle's sides into the array "a"
// 2. Sort the values into three integers, x being the biggest value corresponding
//    to the hypotenuse of the right triangle
// 3. Check if the inputed values could correspond to the lengths of the sides
//    in a right triangle
// 4a. If they can't - output an error message and return 0
// 4b. If they can, calculate and output the perimeter and the area of a triangle
//     built using sides with the lengths of the inputed values.
//-----------------------------------------------------------------
//Block Diagram:
//
// [INPUT A[0] (INT)]
//       |
//       V
// [INPUT A[1] (INT)]
//       |
//       V
// [INPUT A[2] (INT)]
//       |
//       V
// [SORT A[0-2] INTO THREE INTEGERS - X, Y AND Z WITH X BEING THE BIGGEST INT]
//       |
//       V
// [CHECK IF INTEGERS X, Y AND Z COULD CORRESPOND TO THE SIDES OF A RIGHT TRIANGLE (PYTHAGOREAN THEOREM)] ---> [IF NOT - OUTPUT AN ERROR MESSAGE] -> [RETURN 0]
//       |
//       V
// [IF YES - CALCULATE THE PERIMETER AND AREA OF THE TRIANGLE]
//       |
//       V
// [OUTPUT THE MESSAGE WITH THE PERIMETER AND AREA OF THE TRIANGLE]
//       |
//       V
// [RETURN 0]
//-----------------------------------------------------------------


#include<iostream>
using namespace std;
bool check(int x,int y,int z){
  if(x*x==y*y+z*z) return true;
  return false;
}

int main(){
  int a[2],x,y,z;
  cout<<"INPUT FIRST SIDE OF THE RIGHT TRIANGLE: ";
  cin>>a[0];
  cout<<"INPUT SECOND SIDE OF THE RIGHT TRIANGLE: ";
  cin>>a[1];
  cout<<"INPUT THRID SIDE OF THE RIGHT TRIANGLE: ";
  cin>>a[2];

  if(a[0]>a[1] && a[0]>a[2]){
    x=a[0]; y=a[1]; z=a[2];
  }
  if(a[1]>a[0] && a[1]>a[2]){
    x=a[1]; y=a[0]; z=a[2];
  }
  if(a[2]>a[0] && a[2]>a[1]){
    x=a[2]; y=a[0]; z=a[1];
  }

  if(check(x,y,z)==false){
    cout<<"ERROR - THIS TRIANGLE ISN'T TRUE";
    return 0;
  }

  cout<<"THIS TRIANGLE'S PERIMETER EQUALS TO "<<x+y+z<<endl;
  cout<<"THIS TRIANGLE'S AREA EQUALS TO "<<(y*z)/2<<endl;

return 0;
}
