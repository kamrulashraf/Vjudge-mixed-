#include <bits/stdc++.h>
using namespace std;
#define NN 105
#define ll long long
int dp[NN][NN];
ll dp1[NN][NN];
  int lcs(string a , string b){
        for(int i = 1 ; i<= a.size() ; i++){
            for(int j = 1 ; j<= b.size() ;j++){
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
            }
        }
        return dp[a.size()][b.size()];
   }
 
ll fun(string a ,string b){
     for(int i = 0; i<= b.size() ; i++)
         dp1[0][i] = 1;
     for(int i = 0 ; i<= a.size() ; i++)
         dp1[i][0] = 1;
 
     for(int i =  1; i<= a.size() ; i++){
        for(int j = 1 ; j<= b.size() ; j++){
             if(a[i-1] == b[j-1]) dp1[i][j] = dp1[i-1][j-1];
             else{
                ll curLen = i+j-dp[i][j];
                ll temp = 0;
                if(i+j-dp[i-1][j] == curLen) temp += dp1[i-1][j];
                if(i+j-dp[i][j-1] == curLen) temp += dp1[i][j-1];
                dp1[i][j] = temp;
             }
             // cout << i+j-dp[i][j] << ' ' ;
        }
        // cout << endl;
     }
 
     // for(int i = 0 ; i<= a.size() ; i++){
     //     for(int j = 0 ; j<= b.size(); j++){
     //        cout << dp1[i][j] << ' ' ;
     //     } cout << endl;
     // }
     return dp1[a.size()][b.size()];
}
int main()
{
    int test , cs = 1;
    cin >> test;
    while(test--){
        string a , b;
        cin >> a >> b;
        memset(dp,0,sizeof dp);
        ll len = lcs(a,b);
        int res1 = a.size()+b.size()-len;
        memset(dp1,0,sizeof dp1);
        len = fun(a,b);
        ll res2 = len;
        printf("Case %d: %d %lld\n",cs++ ,res1,res2);
    }
    return 0;
}
 