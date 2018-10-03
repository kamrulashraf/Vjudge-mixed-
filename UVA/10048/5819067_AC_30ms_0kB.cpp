#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define inf   1e7;
int dp[105][105];
void clr(int n){
   rep(i,0,n+1) rep(j,0,n+1)  dp[i][j] = inf;
}
void warshall(int n){
   rep( k,1,n+1) rep(i,1,n+1) rep(j,1,n+1)
       dp[i][j] = min(dp[i][j] , max(dp[i][k] , dp[k][j]));

}
int main()
{
  // freopen("a.txt" , "w", stdout);
   int node , edge , query, cs = 1;
   while(cin >> node >> edge >> query){
      clr(node);
      if(!node && !edge && !query) break;
      for(int i = 0 ; i< edge ; i++){
         int a , b , c;
         cin >> a >> b >> c;
         dp[a][b] = c;
         dp[b][a] = c;
      }
      warshall(node);
      if(cs > 1) cout << "\n";
      printf("Case #%d\n", cs++);
      for(int i = 0 ; i< query ; i++){
        int a, b;
        cin >> a >> b;
        if(dp[a][b] == 10000000)
        cout << "no path" << endl;
        else
        cout << dp[a][b] << endl;
      }
   }
return 0;
}
