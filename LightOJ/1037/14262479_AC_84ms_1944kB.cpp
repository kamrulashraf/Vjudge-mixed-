#include <bits/stdc++.h>
using namespace  std;
 
#define N 16
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
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
 
int n;
int a[N];
int cost[N][N];
int counter  = 0;
int dp[1<<16];
 
 
string cnv(int mask){
   string ret;
   if(mask == 0){
      ret += '0';
   }
   else{
      while(mask){
         ret += mask%2 + 48;
         mask /= 2;
      }
   }
   return ret;
}
 
 
int call(int mask){
    if(mask+1 == (1<<n)) return 0;
    int mmin = inf;
    if(dp[mask] != -1) return dp[mask];
    for(int i = 0 ; i< n ; i++){
        int mmax = 1;
        if(!(mask&(1<<i))){
 
                int mmax = 1;
 
                for(int j = 0 ; j< n ; j++){
                    if(mask&(1<<j)){
                       mmax = max(mmax,cost[j][i]);
                    }
                }
 
                int temp = mask|(1<<i);
                mmin = min(mmin, (int)(a[i] / mmax) + (a[i]%mmax>0) + call(temp));
        }
    }
    return dp[mask] = mmin;
}
int main()
{
    int test , cs = 1;
    sca(test);
    while(test--){
       memset(dp,-1,sizeof dp);
       sca(n);
       getchar();
       F(i,n){
         sca(a[i]);
       }
 
 
       for(int i = 0 ; i< n ; i++){
           string s;
           char ch[16];
           scanf("%s",ch);
           s = ch;
           for(int j = 0 ; j< n ; j++){
              cost[i][j] = s[j]-48;
           }
       }
//   cout << cnv(5) << endl;
        int res = call(0);
        printf("Case %d: %d\n",cs++ , res);
 
 
    }
}
 