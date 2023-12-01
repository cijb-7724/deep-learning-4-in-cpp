#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define EPS (0.001)
#define G (0.9)

const pair<int,int> action[4] = {{0,1},{1,0},{0,-1},{-1,0}};

class Policy{
private:
   int height,width;
   vector<vector<vector<double>>> p;

public:
   Policy(int h,int w) : p(h,vector<vector<double>>(w,vector<double>(4,0.25))){
      this->height=h;
      this->width=w;
   }

   void set(int h,int w,vector<double> pp){
      p[h][w]=pp;
   }

   vector<vector<vector<double>>> getpolicy(){
      return p;
   }

   vector<double> getpolicy(int h,int w){
      return p[h][w];
   }
};

class StateValueFunction{
private:
   int height,width;
   double gamma;
   vector<vector<double>> svf;

   bool isin(int h,int w){
      if (0<=h && h<height && 0<=w && w<width){
         return true;
      }
      else{
         return false;
      }
   }

public:
   StateValueFunction(int h,int w,double g) : svf(h,vector<double>(w)){
      this->height=h;
      this->width=w;
      this->gamma=g;
   }

   void calc(const vector<vector<double>> rw,const vector<vector<bool>> wall,Policy p,const pair<int,int> goal){
      double delta=1;
      while (delta>EPS){
         delta=0;
         vector<vector<double>> newsvf(height,vector<double>(width,0));
         for (int i=0;i<height;i++){
            for (int j=0;j<width;j++){
               if (wall[i][j] || goal==make_pair(i,j)){
                  continue;
               }
               for (int a=0;a<4;a++){
                  int movedi=i+action[a].first;
                  int movedj=j+action[a].second;
                  if (!isin(movedi,movedj) || wall[movedi][movedj]){
                     movedi=i;
                     movedj=j;
                  }
                  newsvf[i][j]+=p.getpolicy(i,j)[a]*(rw[movedi][movedj]+gamma*svf[movedi][movedj]);
               }
               delta=max(delta,fabs(svf[i][j]-newsvf[i][j]));
            }
         }
         svf=newsvf;
      }
   }

   vector<vector<double>> getsvf(){
      return svf;
   }

   void show(){
      for (int i=0;i<height;i++){
         for (int j=0;j<width;j++){
            printf("%8.5lf ",svf[i][j]);
         }
         printf("\n");
      }
   }
};

int main(){
   int h=3;
   int w=4;

   vector<vector<bool>> wall(3,vector<bool>(4,false));
   wall[1][1]=true;

   vector<vector<double>> reward(3,vector<double>(4,0));
   reward[2][3]=1;
   reward[1][3]=-1;
   pair<int,int> goal=make_pair(2,3);

   Policy p(h,w);
   StateValueFunction s(h,w,G);

   s.calc(reward,wall,p,goal);
   s.show();
}
