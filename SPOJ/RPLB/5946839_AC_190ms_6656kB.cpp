#include <bits/stdc++.h>
#define  rep(i,x,y)   for(int i = x ; i< y ; i++)
using namespace std;
int dp[1005][1005] , a[1005], maxW;
 int n  , k;
int call(int i , int w){
 //  cout << i << ' ' << w << ' ' << n << endl;
   int p1 = 0, p2 = 0;
   if(i >= n) return 0;
   if(dp[i][w] != -1) return dp[i][w];
   p1 = call(i+1 , w);
   if(w  - a[i] >= 0)
   p2 = a[i] + call(i+2, w - a[i]);
   return dp[i][w] = max(p1 , p2);

}
int main()
{
   int test , cs = 1;
   cin >> test;
   while(test--){
      cin >> n >> k;
      rep(i,0,n)
         cin >> a[i];
      memset(dp,-1,sizeof(dp));
      int ans =  call(0,k);
      printf("Scenario #%d: %d\n", cs++ ,ans);

   }

}
