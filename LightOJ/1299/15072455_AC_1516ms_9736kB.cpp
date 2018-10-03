#include <bits/stdc++.h>
using namespace  std;

#define N 1015
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
// const long long MOD[] = {1000000007LL, 2117566807LL};
// const long long BASE[] = {1572872831LL, 1971536491LL};
ll const mod = 1000000007;
ll dp[N][N];
string s;
int sz;
ll call(int indx , int empty){
     if(empty < 0) return 0;
     if(indx == sz && empty == 0) return 1;
     else if(indx == sz && empty) return 0;
     ll res = 0;
     ll &ret = dp[indx][empty];
     if(ret != -1) return ret;
     if(s[indx] == 'U'){
         res = (res+call(indx+1 , empty+1))%mod;
         if(empty){
             res = (res%mod + empty*call(indx+1, empty))%mod;
         }
     }
     else if(s[indx] == 'D'){
        res = (res %mod + (empty*empty*call(indx+1,empty-1)%mod))%mod;
        res = (res%mod + empty*call(indx+1,empty))%mod;
     }
     else res = call(indx+1,empty)%mod;

     res %= mod;
     if(res < 0) res += mod;
     ret = res%mod;

     return ret;
}
int main()
{
//    freopen("out.txt", "w" , stdout);
    int test , cs = 1;
    sca(test);
    while(test--){
         char str[1001];
         memset(dp, -1 , sizeof dp);
         scanf("%s",str);
         s = str;
         sz = s.size();

         ll res = call(0,0);
         printf("Case %d: %lld\n",cs++ ,res);

    }
    return 0;
}
