#include <bits/stdc++.h>
using namespace std;
#define NN 1005
#define rep(i,x,y)  for(int i = x;i<y;i++)
int n , make;
int mod = 10056;
int fac[NN];
int ncr[NN][NN];
int dp[NN];
void factorial(int n){
   fac[0] = 1;
   for(int i = 1 ; i< n ; i++){
       fac[i] = (i*fac[i-1])%mod;
   }
}
void nCr(int n){
     rep(i,0,n+1) rep(j,0,i+1){
        if(i==j || j == 0) ncr[i][j] = 1;
        else ncr[i][j] = (ncr[i-1][j-1]+ ncr[i-1][j])%mod;
     }
}
 
int call(int n){
     int ret = 0;
     if(n==0) return 1;
     if(dp[n] != -1) return dp[n];
     for(int i  = 1 ; i<= n ; i++){
         ret = (ret+ncr[n][i]*call(n-i))%mod;
     }
     return dp[n] = ret;
}
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    nCr(1001);
    memset(dp,-1,sizeof dp);
    while(test--){
          int n;
          scanf("%d",&n);
          int res = call(n);
        printf("Case %d: %d\n",cs++,res);
    }
}