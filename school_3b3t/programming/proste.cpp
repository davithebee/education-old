//
//    [START]
//       |
//       V
//    [INPUT N - "A" FROM THE FIRST EQUATION]
//      |
//      V
//    [INPUT K - "A" FROM THE SECOND EQUATION]
//      |
//      V
//    [CHECK IF THE LINES ARE PARALLEL TO EACH OTHER] --YES--> [OUTPUT "THESE LINES ARE PARALLEL TO EACH OTHER"] ---> [RETURN 0]
//      |
//     NO
//      |
//      V
//    [CHECK IF THE LINES ARE PERPENDICULAR TO EACH OTHER] --YES--> [OUTPUT "THESE LINES ARE PERPENDICULAR TO EACH OTHER"] ---> [RETURN 0]
//      |
//     NO
//      |
//    [OUTPUT "THESE LINES AREN'T RELATED TO EACH OTHER IN ANY WAY"]
//      |
//      V
//    [RETURN 0]
//
//--------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;
int main(){
  float n, k, b;
  cout<<"INPUT A FROM THE FIRST EQUATION: ";
  cin>>n;
  cout<<"INPUT A FROM THE SECOND EQUATION: ";
  cin>>k;
  cout<<"INPUT B FROM THE FIRST EQUATION (COMPLETELY USELESS): ";
  cin>>b;
  cout<<"INPUT B FROM THE SECOND EQUATION (COMPLETELY USELESS): ";
  cin>>b;

  b=0;

  if(n == k) cout<<"THESE LINES ARE PARALLEL TO EACH OTHER.";
  else if(n * k == -1) cout<<"THESE LINES ARE PERPENDICULAR TO EACH OTHER.";
  else cout<<"THESE LINES AREN'T RELATED TO EACH OTHER IN ANY WAY.";

  return 0;
}
