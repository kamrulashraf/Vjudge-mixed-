#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
long long dp[31][905];
ull call(ull a , ull b){
   if(b == 1) return a*a;
   if(b == 0) return 1;
   if(dp[a][b] != -1) return (ull) dp[a][b];
   return (ull) ( ((a*a)*call(a-1,b-1)/b));
}
int main()
{
  int test, cs = 1 ;
  cin  >> test;
  memset(dp,-1,sizeof(dp));
  while(test--){
     ull squre , rook;
     cin >> squre >> rook;
     printf("Case %d: %llu\n",cs++ , call(squre , rook));
  }
 return 0;
}
