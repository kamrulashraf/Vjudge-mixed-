#include <bits/stdc++.h>
#define f(i) i-1
using namespace std;
int dp[105][105];
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
int main()
{
  int test , cs = 1;
  cin >> test;
  while(test--){
    string s, srev ;
    cin >> s;
    srev = s;
    reverse(srev.begin() , srev.end());
    memset(dp,0,sizeof(dp));
    int ans = lcs(s,srev);
    ans = s.size() - ans;
    printf("Case %d: %d\n", cs++ , ans);
  }
}

