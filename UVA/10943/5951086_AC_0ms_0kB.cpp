#include <bits/stdc++.h>
#define rep(i,x,y)  for(int i = x ; i<y ; i++)
#define mod  1000000
using namespace std;
long long dp[105][105] , sub[105][105];
int main()
{
//freopen("a.txt","w",stdout);
   int r = 101 , c = 101;
   for(int i = 1 ; i< r ; i++){
      long long sum = 0;
      for(int j = 0 ; j< c ; j ++){
         if(i == 1 || j == 0) dp[i][j] = 1;
         else dp[i][j] = sub[i-1][j];
         sum = (sum + dp[i][j])%mod;
         sub[i][j] = sum;
      }
   }

   int a , b;
   while(cin >> a >> b){
     if(!a && !b) break;
     cout << dp[b][a] << endl;
   }


}
