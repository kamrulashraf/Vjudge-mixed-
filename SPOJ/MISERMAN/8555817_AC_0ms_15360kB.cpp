#include <bits/stdc++.h>
using namespace std;
#define N 105
#define inf 1e9
int a[N][N];
int dp[N][N];


int main()
{

     int n  , m;
     scanf("%d%d",&n,&m);
     for(int i = 1 ; i<= n ; i++){
         dp[i][m+1] = inf;
         dp[i][0] = inf;
         for(int j = 1 ; j<= m ; j++){
              scanf("%d",&a[i][j]);
         }
     }


     for(int i = 1 ; i<= n ; i++){
         for(int j = 1 ; j<= m ; j++){
             dp[i][j] = a[i][j]+min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
         }
     }

     int res = 1e9;
     for(int i = 1 ; i<= m ; i++){
          res = min(res, dp[n][i]);
     }
     cout << res << endl;
     return 0;
}
