#include <bits/stdc++.h>
using namespace  std;

#define N 100005
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
int c[N];
int dp[5005][105];
int main()
{
   int n , m , x;
   while(~scaaa(m,n,x)){
            memset(dp,0,sizeof dp);
           for(int i = 0 ; i< n ; i++)
             sca(c[i]);

           sort(c,c+n);

           int fish = 0;
           for(int i = 1 ; i<= x ; i++){
               for(int j = 0 ; j< n ; j++){
                   if(dp[i][j] == 0){
                      fish++;
                      if(fish > m) break;
                      for(int k = i ; k< i+c[j] ; k++){
                         dp[k][j] = fish;
                         if(k > 5001) break;
                      }
                   }
               }
           }
           int mmax  = 0;

           for(int i = 1 ; i <= x; i++){
              for(int j = 0 ; j< n ; j++){
        //          cout << dp[i][j] << ' ';
                  mmax = max(mmax,dp[i][j]);
              }
        //      cout << endl;
           }

        //   for(int i = 0)
           int res = 0;
           for(int i = 0 ; i < n ; i++){
              if(dp[x][i] == dp[x+1][i] && dp[x][i]) res++;
        //      cout << dp[x][i] << ' ' << dp[x+1][i] << endl;
           }

           cout << m - mmax << ' '  << res << endl;
    }
}
