#include <bits/stdc++.h>
using namespace std;
#define N 25

int a[N][5];
int dp[N][6];
int n;

int call(int indx , int prev){
    int mmin = 1e9;
    if(indx >= n) return 0;
    if(dp[indx][prev] != -1) return dp[indx][prev];
    for(int i = 0 ; i< 3 ; i++){
        if(i==prev) continue;
        mmin = min(mmin ,a[indx][i]+call(indx+1,i));
    }
    return dp[indx][prev] =  mmin;
}
int main()
{

     int test , cs = 1 ;
     scanf("%d",&test);
     while(test--){
         memset(dp,-1,sizeof dp);
         scanf("%d",&n);
         for(int i = 0 ; i< n ; i++){
              for(int j = 0 ; j< 3 ; j++){
                    scanf("%d",&a[i][j]);
              }
         }

         int res = call(0,5);
         printf("Case %d: %d\n",cs++ ,res);
     }

     return 0;
}
