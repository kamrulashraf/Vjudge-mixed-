#include <bits/stdc++.h>
using namespace  std;

#define N 400005
#define inf 1e16
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
#define write() freopen("out.txt", "w" , stdout)
#define read() freopen("in.txt" , "r", stdin)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
int n , m;
int a[N];
int counter[20];
int save[20][20];
ll dp[1<<17];

void calc(){

     for(int i = 0 ; i< n ; i++){
         counter[a[i]]++;

         for(int j = 0 ; j< m ; j++){
             if(a[i] == j) continue;
             save[a[i]][j] += counter[j];
         }
     }
}

ll call(int mask){
      if(mask == (1<<m)-1) return 0;

      ll &ret = dp[mask];
      if(ret != -1) return ret;
      ll res = inf;
      for(int i = 0 ; i< m ; i++){
         if(!(mask&(1<<i))){
            ll temp = 0;
              for(int j = 0 ; j< m ; j++){
                 if(mask&(1<<j)){
                    temp += save[i][j];
                 }
              }

              temp = temp + call(mask | (1<<i));
              res = min(res,temp);

         }

      }
      ret = res;
      return res;
}
int main()
{
    int test , cs = 1;
    sca(test);
    while(test--){
         memset(counter,0,sizeof counter);
         memset(save,0,sizeof save);
         memset(dp,-1,sizeof dp);
         scaa(n , m);
         F(i , n){
            sca(a[i]);
            a[i]--;
         }

         calc();

         ll res = call(0);
         printf("Case %d: %lld\n",cs++ , res);
    }
}
