#include <bits/stdc++.h>
using namespace  std;
#define NN 55
#define ll long long
ll dp[NN][2*NN];
ll call(int n , int m, int kk){
   for(int i = 0 ; i< kk ; i++) dp[0][i] = 1;
   for(int i = 1 ; i<= m ; i++){
       for(int j = 1 ; j<= n ; j++){
           dp[i][j] = dp[i-1][j-1] + dp[i][j-1] - (j - kk-1 >= 0 ? dp[i-1][j-kk-1] : 0);
       }
   }
//   for(int i  = 0 ; i<= m ; i++){
//      for(int j = 0 ; j<= n ; j++){
//         cout << dp[i][j] << ' ';
//      } cout << endl;
//   }
    return dp[m-1][n-1];
}

// void raough(){
//    for(int i = 0 ; i<= m ; i++){
//        for(int j = 1 ; j<= n ; j++){
//            dp[i][j] = dp[i-1][j-1] + dp[i][j-1] + (j - k >= 0 ? dp[i][j-k] : 0);
//        }
//    }
// }
int main()
{
   int n  , m , k;
   int test , cs = 1;
   cin >> test;
   while(test--){
   	   scanf("%d%d%d",&n , &m , &k);
       memset(dp,0,sizeof(dp));
       ll res = call(n,m,k);
       printf("Case %d: %lld\n",cs++ , res);
   }
}
