#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace  std;

#define N 105
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < ll , ll>
#define ll long long
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define sca(a) scanf("%lld",&a)
#define scaa(a,b) scanf("%lld%lld",&a,&b)
#define scaaa(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define write() freopen("out.txt", "w" , stdout)
#define read() freopen("in.txt" , "r", stdin)
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define SET(x) memset(x , -1 , sizeof x)
#define CLR(x) memset(x , 0 , sizeof x)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};


ll vis[N];
ll dis[11][N];
ll d , k , s;
map < ll , vector< pii > > adj;


int bfs(int s){
    CLR(vis);
    F(i,10) F(j,100) dis[i][j] = inf;
    vis[s] = 0;
    dis[0][s] = 0;
    priority_queue < pii , vector <pii > , greater < pii > > q;

    q.push(mp(0,s));

    while(!q.empty()){
        pii u = q.top();
        q.pop();

      // cout << u.ss << ' ' << u.ff << ' ' << vis[u.ss] <<  endl;

        if(vis[u.ss] > k) continue;
        dis[vis[u.ss]][u.ss] = u.ff;
        vis[u.ss]++;


        for(int i = 0 ; i< adj[u.ss].size() ; i++){
             int v = adj[u.ss][i].ss;

             ll cost = u.ff + adj[u.ss][i].ff;
             q.push(mp(cost,v));
        }

    }

    return dis[k-1][d];

}


void init(){
  adj.clear();
}
int main()
{
  // read();
    ll node , edge;
    while(~scaa(node,edge)){

         if(node == 0 && edge == 0) break;
         scaaa(s,d,k);
         init();

         for(int i = 0 ; i < edge ; i++){
             ll a , b , c;
             scaaa(a,b,c);
             adj[a].pb(mp(c,b));
           //  adj[b].pb(mp(c,a));
         }

         ll res = bfs(s);
         if(res == inf){
            printf("-1\n");
         }
         else printf("%lld\n",res);
    }
}
