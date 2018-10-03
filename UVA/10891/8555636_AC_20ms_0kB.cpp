#include <bits/stdc++.h>
using namespace std;
#define N 105

int a[N];
int dp[N][N];
int n;

int call(int b , int e){
     if(b > e) return 0;
     int mmax = -1e9;
     int sum  =0;
     if(dp[b][e] != -1) return dp[b][e];
     for(int i = b ; i<= e  ; i++){
         sum += a[i];
         mmax = max(mmax,sum-call(i+1,e));
     }
     sum = 0;
     for(int i = e ; i>= b ; i--){
         sum += a[i];
         mmax = max(mmax,sum-call(b,i-1));
     }
     return dp[b][e] = mmax;
}

int main()
{

     while(scanf("%d",&n) && n){
         memset(dp,-1,sizeof dp);
         for(int i = 1 ; i<= n ; i++)
            scanf("%d",&a[i]);

          int res = call(1,n);
          printf("%d\n",res);
     }
     return 0;
}
