#include <bits/stdc++.h>
using namespace std;
double dp[5][1001][1001];
bool vis[5][1001][1001];
double call(int flag , int w , int b){
     if(w <=0 && b <= 0) return 0;
     int tt = (flag+1)%3;
     double tot = w+b;
     double res = 0;
     if(vis[flag][w][b] == true) return dp[flag][w][b];
     if(flag == 0){
          if(w>0)
          res += w/tot;
          if(b>0)
          res += b/tot*call(tt,w,b-1);
     }
     else if(flag == 1){
         if(b>0)
           res += b/tot*call(tt,w,b-1);
     }
     else{
        if(w>0)
          res += w/tot*call(tt,w-1,b);
        if(b>0)
        res += b/tot*call(tt,w,b-1);
     }
//     cout <<tt << ' ' <<  w << ' ' << b << ' ' << res << endl;
     vis[flag][w][b] = true;
     return dp[flag][w][b] = res;
}
int main()
{
   int w , b;
   cin >> w >> b;
   memset(vis,0,sizeof vis);
   double res = call(0,w,b);
   printf("%.10lf\n",res);
}
