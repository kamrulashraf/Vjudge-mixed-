#include <bits/stdc++.h>
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define inf     10000000
using namespace std;
int dp[105][105];
void clr(int n){
   rep(i,0,n+1) rep(j,0,n+1) dp[i][j] = inf;
}
void warshall(int n){
  rep(k,0,n+1) rep(i,0,n+1) rep(j,0,n+1)
      if(dp[i][k] + dp[k][j] < dp[i][j])
           dp[i][j] = dp[i][k] + dp[k][j];
}
int main()
{

  int test, cs = 1;
  cin >> test;
  while(test--){
     int node , edge;
     cin >> node >> edge;
     clr(node);
     for(int i = 0 ; i < edge ; i++){
        int a, b , c;
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b] , c);
        dp[b][a] = min(dp[b][a] , c);
     }
     warshall(node);
     if(dp[1][node] == inf)  printf("Case %d: Impossible\n",cs++);
     else printf("Case %d: %d\n",cs++ ,dp[1][node]);
  }
}
