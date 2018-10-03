#include <bits/stdc++.h>
#define  rep(i,x,y)   for(int i = x ; i< y ; i++)
using namespace std;
int n , maxW, a[105], dp[105][25001];
int call(int i , int w){
    int p1 = 0 , p2 = 0;
    if(i >= n) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    p1 = call(i+1, w);
    if(w-a[i] >= 0)
    p2 = a[i] + call(i+1,w-a[i]);
    return dp[i][w] = max(p1,p2);

}
int main()
{
   int test;
   cin >> test;
   while(test--){
      cin >> n;
      int sum = 0;
      rep(i,0,n){
         cin >> a[i];
         sum += a[i];
      }
      maxW = sum/2;
      memset(dp,-1 , sizeof(dp));
      maxW = call(0,maxW);
      cout << sum - 2*maxW << endl;

   }

}
