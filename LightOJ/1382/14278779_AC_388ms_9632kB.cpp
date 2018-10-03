#include <bits/stdc++.h>
using namespace  std;

#define N 1007
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

ll mod = 1e9+7;
ll ncr[N][N];
map < int , vector < int > > adj;
template < class T> T big(T b , T p , T mod){
    if(p == 0) return 1;
    if(!(p&1)){
        T x = big(b,p/2,mod);
        return (x*x)%mod;
    }
    else return (b*big(b,p-1,mod))%mod;
}
 
    void nCr(int n){
         rep(i,0,n+1) rep(j,0,i+1){
            if(i==j || j == 0) ncr[i][j] = 1;
            else ncr[i][j] = (ncr[i-1][j-1]+ ncr[i-1][j])%mod;
         }
    }
 
 
stack < int > st;
bool vis[N];
ll dp[N];
int counter[N];
void topSort(int u){
    vis[u] = 1;
    for(int i = 0 ; i< adj[u].size() ; i++){
        int v = adj[u][i];
        if(vis[v] == 0)
            topSort(v);
    }
    st.push(u);
}
 
 
ll dfs(int u){
     vis[u] = 1;
     dp[u] = 1;
     counter[u] = 1;
     for(int i = 0 ; i< adj[u].size() ; i++){
         int v = adj[u][i];
         if(vis[v] == 0){
            dfs(v);
          }
 
          counter[u] += counter[v];
          dp[u] = ((dp[u]*ncr[counter[u]-1][counter[v]])%mod*dp[v])%mod;
          if(dp[u] <0) dp[u]+= mod;
 
     }
     return dp[u];
 
 
}
int main()
{
   // freopen("inputf.in","r",stdin);
   nCr(1000);
   int test , cs = 1;
   scanf("%d",&test);
   while(test--){
       memset(vis,0,sizeof vis);
       memset(dp,0,sizeof dp);
       int n;
       scanf("%d",&n);
       for(int i = 1 ; i< n ; i++){
           int u  , v;
           scanf("%d%d",&u,&v);
           adj[u].push_back(v);
       }
 
 
       for(int i = 1 ; i<= n ; i++){
          if(vis[i] == 0) topSort(i);
       }
       memset(vis,0,sizeof vis);
       ll res = 0;
       while(st.size()){
           int temp = st.top();
           st.pop();
           if(vis[temp]==0){
             res = dfs(temp);
           }
       }
 
       // for(int i = 1 ; i<= n ; i++){
       //    cout << i << ' ' << counter[i] <<' ' << dp[i] << endl;
       // }
       printf("Case %d: %lld\n",cs++ , res);
       adj.clear();
   }
}
 