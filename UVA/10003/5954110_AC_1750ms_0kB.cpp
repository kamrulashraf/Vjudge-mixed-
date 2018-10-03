#include <bits/stdc++.h>
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define inf  10000000
using namespace std;
int a[55],dp[1000][1000], n;
int call(int b , int e){
    bool flag = 0;
    if(dp[b][e] != inf) return dp[b][e];
    for(int i = 0 ; i< n ; i++){
       int v = a[i];
       if(v > b && v < e){
         flag = 1;
         dp[b][e] = min(e-b + call(b,v) + call(v,e), dp[b][e]);
       }
    }
    if(flag == 0) return 0;
    else
    return dp[b][e];
}
int main()
{
   int val;
   while(cin >> val){
      if(!val) break;
      rep(i,0,1000) rep(j,0,1000) dp[i][j] = inf;
      cin >> n;
      for(int i = 0 ; i< n ; i++){
         cin >> a[i];
      }
      int ans = call(0,val);
      printf("The minimum cutting is %d.\n", ans);
   }
}
