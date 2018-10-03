#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define N 1000005
int a[N] , n, dp[N];


int call(int i){
     int res1 = 0, res = 0;
     if(i >= n) return 0;
     if(dp[i] != -1) return dp[i];
     res += a[i]+call(i+3);
     res1 += call(i+1);
     return dp[i] = max(res1,res);

}
int main()
{
     // freopen("in.txt","r" , stdin);
 
     scanf("%d",&n);
     for(int i = 0 ; i< n ; i++)
         scanf("%d",&a[i]);
     memset(dp,-1,sizeof dp);
     int res = call(0);
     cout << res << endl;

}
