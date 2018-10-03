#include <bits/stdc++.h>
#define rep(i,x,y)   for(int i = x ; i< y ; i++)
using namespace std;
int s[2001] , val[2001];
//map < int , map <int ,int> > dp;
int dp[2001][2001];
int maxSize , n;
int call(int i , int w){
    if(i >= n) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    int p1 = 0 , p2 = 0;
    p1 = call(i+1,w);
    if(w-s[i] >= 0)
    p2 = val[i] + call(i+1, w- s[i]);
    return dp[i][w] = max(p1 , p2);
}
int main()
{
  cin >> maxSize >> n;
  rep(i,0,n)
     cin >> s[i] >> val[i];
  memset(dp,-1,sizeof(dp));
  cout << call(0,maxSize) << endl;

}
