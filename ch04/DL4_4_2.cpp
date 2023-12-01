#include <iostream>
#include <cmath>
using namespace std;

#define EPS (0.001)

int main(){
   double VL1=0,VL2=0;
   double delta=1;
   for (int i=0;delta>EPS;i++){
      double tmp1,tmp2;
      tmp1=0.45*VL1+0.45*VL2;
      tmp2=0.45*VL1+0.45*VL2-0.5;
      delta=max(fabs(VL1-tmp1),fabs(VL2-tmp2));
      VL1=tmp1;
      VL2=tmp2;
   }
   cout << "VL1 : " << VL1 << endl;
   cout << "VL2 : " << VL2 << endl;
}
