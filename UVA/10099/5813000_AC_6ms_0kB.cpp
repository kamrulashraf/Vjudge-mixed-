#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y)        for(int i = x ; i< y ; i++)
int dp[105][105];
void warshall(int n){
  rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1)
      dp[i][j] = max(dp[i][j] , min(dp[i][k] , dp[k][j]));
}
int main()
{
   int node , edge,cs = 1;
   while(cin >> node >> edge && node && edge){
      int a, b , c;
      memset(dp,0,sizeof(dp));
      rep(i,0,edge){
        cin >> a >> b >> c;
        dp[a][b] = c-1;
        dp[b][a] = c-1;
      }
      warshall(node);
      cin >> a >> b >> c;
      float temp = dp[a][b];
      temp = ceil(c/(float)temp);
       printf("Scenario #%d\n",cs++);
         printf("Minimum Number of Trips = %d\n\n",(int)temp);
   }
}



