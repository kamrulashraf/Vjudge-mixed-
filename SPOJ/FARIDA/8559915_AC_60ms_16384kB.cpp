#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[10005];
ll dp[10005];
       int n;

long long call(int indx){
     ll p1 = 0;
     ll p2 = 0;
    if(indx >= n) return 0;
    if(dp[indx] != -1) return dp[indx];
    p1 = a[indx]+call(indx+2);
    p2 = call(indx+1);
    return dp[indx]=max(p1,p2);
}
int main()
{
   int test ,cs = 1;
   scanf("%d",&test);
   while(test--){
       memset(dp,-1,sizeof dp);
       scanf("%d",&n);
       for(int i = 0 ; i< n ; i++){
          scanf("%lld",&a[i]);
       }

       ll res = call(0);
       printf("Case %d: %lld\n",cs++ ,res);
   }
}