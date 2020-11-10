 /*

 NWD ( a , b )


 ITERATION:

 a = 12
 b = 14
 example of version using modulo (optimal):

 a | b | r = a % b
 -----------------
 12| 14| 12              r=a%b -> a=b -> b=r
 -----------------
 14| 12| 2               r=a%b -> a=b -> b=r
 -----------------
 12| 2 | 0               r=a%b -> a=b -> b=r
 -----------------
 2 | 0 | ---             r=a%b -> a=b -> b=r (repeat until b>0)
 -----------------


 example of version using reduction:

 1. b>a -> b=b-a -> b=14-12 -> b=2

 a=12 b=2

 2. a>b -> a=a-b -> a=12-2 -> a=10

 repeat until a==b
 return a;


 RECURSION:

 int NWD(int a, int b){
  if(b==0) return a;
  return NWD(b, a%b);
 }

 int NDW(int a, int b){
  if(a==b) return a;
  if(a>b) return NWD(a-b, b);
  return NWD(a,b-a);
 }

 */
