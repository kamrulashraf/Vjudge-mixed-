#include <bits/stdc++.h>
using namespace std;
#define NN 105
string res[NN][NN];
int dp[NN][NN];
int lcs(string a , string b){
    int sa = a.size();
    int sb = b.size();
    for(int i=1;i<=sa;i++){
      for(int j=1;j<=sb;j++){
          if(a[i-1]==b[j-1]){
             dp[i][j]=dp[i-1][j-1]+1;
             res[i][j] += res[i-1][j-1]+a[i-1];
          }
          else{
             if(dp[i-1][j]<dp[i][j-1]){
                 res[i][j] = res[i][j-1];
             }
             else if(dp[i][j-1]<dp[i-1][j]){
                 res[i][j] = res[i-1][j];
             }
             else res[i][j] = min(res[i-1][j],res[i][j-1]);
             dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
          }
      }
    }
    return dp[sa][sb];
}
int main()
{
   int test , cs = 1;
   cin >> test;
   while(test--){
       string a , b;
       cin >> a >> b;
       memset(dp,0,sizeof dp);
       for(int i = 0 ; i<= a.size() ; i++){
            for(int j = 0 ; j<= b.size() ; j++){
                res[i][j].clear();
            }
       }
       int flag = lcs(a,b);
       if(!flag)
          printf("Case %d: :(\n",cs++);
       else{
          printf("Case %d: ",cs++);
          cout << res[a.size()][b.size()] << endl;
       }
   }
}