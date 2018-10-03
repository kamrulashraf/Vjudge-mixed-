#include <bits/stdc++.h>
using namespace  std;
 
#define N 20
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
int save[1<<15] , dp[1<<15], vis[1<<15];
int a[N][N];
int counter = 0;
int call(int mask){
//   cout << mask << endl;
   if(mask == 0) return mask;
   if(vis[mask]) return dp[mask];
   int res = inf;
   for(int i = mask ; i> 0 ; i = (i-1)&mask){
      int temp = mask^i;
 
      res = min(res,save[i]+call(temp));
   }
//   cout << counter << endl;
   vis[mask] = 1;
   return dp[mask] = res;
}
int main()
{
  int test , cs = 1;
  sca(test);
  while(test--){
      memset(dp, 0 , sizeof dp);
      memset(save,0,sizeof save);
      memset(vis, 0 , sizeof vis);
      sca(n);
      for(int i = 0 ; i< n ; i++){
          for(int j =  0; j  < n ; j++){
              sca(a[i][j]);
          }
      }
      int temp = 0;
       for(int i = 0 ; i< (1<<n) ; i++){
           temp = i;
           std::vector<int > v;
           for(int j = 0 ; j< n ; j++){
             if(temp&(1<<j)){
               v.push_back(j);
             }
           }
 
           int res = 0;
//           cout << i <<'#' << endl;
//           for(auto x : v){
//              cout << x << ' ' ;
//
//           } cout << endl;
           for(int i = 0 ; i< v.size() ; i++){
               for(int j = 0 ; j< v.size() ; j++){
                   res += a[v[i]][v[j]];
               }
           }
           save[temp] = res;
       }
 
 
       temp = (1<<n)-1;
        int t = temp;
//       while(temp){
//          cout << temp << ' ' << save[temp] << endl;
//            temp = (temp-1)&t;
//
//       }
       int res = call(t);
       printf("Case %d: %d\n",cs++ , res);
 
  }
}
 