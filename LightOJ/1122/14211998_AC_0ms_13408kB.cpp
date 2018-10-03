#include <bits/stdc++.h>
using namespace  std;
 
#define N 3000000
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define MP make_pair
#define PB push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
 
int a[N];
ll dp[11][10];
 
ll call(int indx , int m, int n, int prev){
     if(indx >= m) return 1;
     ll res  = 0;
     // cout << indx << ' ' << m << ' ' << n << ' ' << prev << endl;
     ll &ret  = dp[indx][prev];
     if(ret != -1) return ret;
     if(indx == 0){
        for(int i = 0 ; i< n ; i++){
             if(a[i]) res += call(indx+1,m,n ,a[i]);
        }
     }
     else{
         for(int i = 0 ; i< n ; i++){
             if(abs(a[i]-prev) <= 2){
                res += call(indx+1,m , n ,a[i]);
             }
         }
     }
     return ret = res;
 
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int test ,  cs = 1;
    sca(test);
    while(test--){
            int n , m;
            scaa(n,m);
            for(int i = 0 ; i< n ; i++){
                 sca(a[i]);
            }
 
            memset(dp,-1,sizeof dp);
 
            ll res = call(0,m,n,0);
            printf("Case %d: %lld\n",cs++ , res);
    }
 
}
 