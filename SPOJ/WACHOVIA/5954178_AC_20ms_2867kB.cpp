#include <bits/stdc++.h>
using namespace std;
int price[55],weight[55],dp[55][1005], num, maxW;
int call(int i , int w)
{
    int p1 = 0;
    int p2 = 0;
    if(i >= num) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    p1 = call(i+1,w);
    if(w-weight[i] >= 0)
       p2 = price[i] + call(i+1 , w-weight[i]);
    return dp[i][w] = max(p1,p2);
}
int main()
{
   int test ;
   cin >> test;
   while(test--){
      cin >> maxW  >> num;
      for(int i = 0 ; i< num ; i++){
         cin >> weight[i] >> price[i];
      }
      memset(dp,-1,sizeof(dp));
      int ans = call(0,maxW);
      printf("Hey stupid robber, you can get %d.\n",ans);
   }
}

