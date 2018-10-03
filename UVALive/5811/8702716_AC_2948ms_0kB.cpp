#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
bool vis[17][17][17][17][3][3][3][3];
double dp[17][17][17][17][3][3][3][3];
double call(int x , int y, int z , int w , int ra , int rb , int rc  , int rd){
      if(x+ra >= a && y+rb >= b && z+rc >= c && w+rd >= d) return 0.0;
      double total = 54-(x+y+z+w+ra+rb+rc+rd);
      int remx = 13-x;
      int remy = 13-y;
      int remz =  13-z;
      int remw = 13-w;
      double ret = 0.0;
      if(vis[x][y][z][w][ra][rb][rc][rd] == 1) return dp[x][y][z][w][ra][rb][rc][rd];
      if(x < 13) ret += (1+call(x+1,y,z,w,ra,rb,rc,rd))*(remx)/total;
      if(y<13) ret += (1+call(x,y+1,z,w,ra,rb,rc,rd))*(remy)/total;
      if(z < 13) ret += (1+call(x,y,z+1,w,ra,rb,rc,rd))*(remz)/total;
      if(w<13) ret += (1+call(x,y,z,w+1,ra,rb,rc,rd))*(remw)/total;
      double mmin = 1e5;
      int totalJokerUse = ra+rb+rc+rd;
      if(totalJokerUse < 2){
          mmin = min(mmin,(1+call(x,y,z,w,ra+1,rb,rc,rd))*(2-totalJokerUse)/total);
          mmin = min(mmin,(1+call(x,y,z,w,ra,rb+1,rc,rd))*(2-totalJokerUse)/total);
          mmin = min(mmin,(1+call(x,y,z,w,ra,rb,rc+1,rd))*(2-totalJokerUse)/total);
          mmin = min(mmin,(1+call(x,y,z,w,ra,rb,rc,rd+1))*(2-totalJokerUse)/total);
          ret += mmin;
      }
      vis[x][y][z][w][ra][rb][rc][rd] = 1;
//      cout << x << ' ' <<  y << ' ' << z << ' ' << w << ' '  << total << endl;
      return dp[x][y][z][w][ra][rb][rc][rd] = ret;

}

int check(int a){
   if(a>13) return a-13;
   return 0;
}
bool solveAble(int a, int b ,int c ,int d){
     int sum = 0;
     sum += check(a);
     sum += check(b);
     sum += check(c);
     sum += check(d);
     if(sum > 2) return 0;
     return 1;

}
int main()
{
   int test , cs = 1;
   scanf("%d",&test);
   while(test--){
       memset(vis,0,sizeof vis);
       scanf("%d%d%d%d",&a,&b,&c,&d);

       if(!solveAble(a,b,c,d)){
        printf("Case %d: %.3lf\n",cs++ , -1.0);
       }
       else{
         double res = call(0,0,0,0, 0,0,0,0);
         printf("Case %d: %.3lf\n",cs++ , res);
       }
   }
}
