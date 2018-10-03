#include <bits/stdc++.h>
using namespace std;
long long dp[101][101];
long long precal(int n , int m){
   if(m==1) return dp[n][m] = n;
   if(m==n) return dp[n][m] = 1;
   if(dp[n][m]!=-1) return dp[n][m];
   return dp[n][m] = precal(n-1,m-1)+precal(n-1,m);
}
int main()
{
   memset(dp,-1,sizeof dp);
   int n , m;
   while(scanf("%d%d",&n,&m) && (m && n)){
       long long res = precal(n,m);
       printf("%d things taken %d at a time is %lld exactly.\n",n,m,res);
   }
}