#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;
#define ll long long
#define N 5005
int a[N] , b[N], c[N];
int ox , ni, n;
int dp[1000][22][80];
int call(int indx ,int remox ,int remni){
   if(remox<=0) remox = 0;
   if(remni <= 0) remni = 0;
   if(indx >= n){
      if(remox ==0 && remni == 0)
         return 0;
       else return 1e9;
   }
   if(dp[indx][remox][remni] != -1) return dp[indx][remox][remni];
   int p1 = c[indx]+call(indx+1,remox-a[indx],remni-b[indx]);
   int p2 = call(indx+1,remox,remni);
   return dp[indx][remox][remni] =  min(p1,p2);
}
int main()
{
   int test , cs = 1;
   scanf("%d",&test);
   while(test--){
       memset(dp,-1,sizeof dp);
       scanf("%d%d",&ox,&ni);
       scanf("%d",&n);
       for(int i = 0 ; i< n ; i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
       }

       int res = call(0,ox,ni);
       cout << res << endl;
   }
}
