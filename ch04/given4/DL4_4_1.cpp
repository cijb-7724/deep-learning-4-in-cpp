#include <iostream>
using namespace std;

int main(){
   const int N=100;
   double VL1=0,VL2=0;

   for (int i=0;i<N;i++){
      double tmp1,tmp2;
      tmp1=0.45*VL1+0.45*VL2;
      tmp2=0.45*VL1+0.45*VL2-0.5;
      VL1=tmp1;
      VL2=tmp2;
   }
   cout << "VL1 : " << VL1 << endl;
   cout << "VL2 : " << VL2 << endl;
}
