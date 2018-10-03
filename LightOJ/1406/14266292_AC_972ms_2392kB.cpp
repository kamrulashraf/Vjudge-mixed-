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

int n , m;
vector < int > adj[N];
bool vis[N][(1<<15)+15];
bool check[(1<<15)+15];
bool path[(1<<15)+15];
int dp[(1<<15)+15];
void markAllPath(int u , int mask){
    vis[u][mask] = 1; // check cycle at postion u which i find before

    path[mask] = 1;
//    cout << u << ' ' << mask << endl;
    for(int i = 0 ; i< adj[u].size() ; i++){
       int v = adj[u][i];
       int temp = mask|(1<<v);
       if(vis[v][temp]== 0){
          markAllPath(v,temp);
       }
    }
}


int call(int mask){
    if(mask == 0) return 0;
    if(check[mask]) return dp[mask];
    int ret = inf;
    for(int i = mask ; i> 0 ; i=(i-1)&mask){
        int temp = mask^i;
//        cout << i << ' ' << temp << endl;
        if(path[i])
            ret = min(ret, 1+ call(temp));
    }
    check[mask] = 1;
    return dp[mask] = ret;
}
int main()
{
  int test , cs= 1;
  sca(test);
  while(test--){
    for(int i= 0 ; i<= 15 ; i++){
            adj[i].clear();
    }
    memset(vis,0,sizeof vis);
    memset(path, 0 , sizeof path);
    memset(dp,0,sizeof dp);
    memset(check,0,sizeof check);

    scaa(n,m);
    for(int i = 0 ; i < m ; i++){
      int u , v;
      scaa(u,v);
      u-- ; v--;
      adj[u].push_back(v);
    }
    for(int i = 0 ; i< n ; i++){
        markAllPath(i,(1<<i));
    }


//    for(int i = 0 ; i< (1<<n) ; i++){
//        cout << i << '#' << path[i] << endl;
//    }
    int temp = (1<<n)-1;
    int res = call(temp);
    printf("Case %d: %d\n",cs++, res);
  }
}
