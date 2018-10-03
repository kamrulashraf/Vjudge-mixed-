#include <bits/stdc++.h>
using namespace std;
#define NN 105
#define inf 1e7
int a[NN];
int dp[NN][NN];
int  call(int l , int r){
     int mmax = -inf;
     if(l>r) return 0;
     int sum = 0;
     if(dp[l][r] != -1) return dp[l][r];
     for(int i = l ; i<= r ; i++){
          sum += a[i];
          mmax = max(mmax, sum-call(i+1,r));
     }
     sum = 0;
     for(int i = r ; i>= l ; i--){
         sum += a[i];
         mmax = max(mmax,sum-call(l,i-1));
     }
     return dp[l][r] = mmax;
}
int main()
{
   int test , cs = 1;
   scanf("%d",&test);
   while(test--){
        int n;
        scanf("%d", &n);
        for(int i = 1 ; i<= n ; i++){
           scanf("%d",&a[i]);
        }
        memset(dp,-1,sizeof dp);
        int res = call(1,n);
        printf("Case %d: %d\n",cs++ , res);
   }
}
 