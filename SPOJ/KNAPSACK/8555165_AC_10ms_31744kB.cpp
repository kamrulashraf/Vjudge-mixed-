#include <bits/stdc++.h>
using namespace std;
#define N 2005

int dp[N][N];

int cap[N] , cost[N];
int n , capacity;
int call(int indx , int rem){
    if(indx >= n) return 0;
    int p1 = 0 , p2 = 0;
    if(dp[indx][rem] != -1) return dp[indx][rem];
    if(rem-cap[indx] >= 0)
       p1 = cost[indx]+call(indx+1,rem-cap[indx]);
    p2 = call(indx+1,rem);
    return dp[indx][rem] = max(p1,p2);
}
int main()
{
     memset(dp,-1,sizeof dp);
     cin >> capacity >> n;
     for(int i = 0 ; i< n ; i++){
        cin >> cap[i] >> cost[i];
     }

     int res = call(0,capacity);

     cout << res << endl;
}
