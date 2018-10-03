#include <bits/stdc++.h>
using namespace std;
int counter;
bool vis[10005];
int num[10005], low[10005],par[10005];
map < int , vector <int> > g;
set <int> s;

void dfs(int u){
  int child = 0;
  vis[u] = 1;
  num[u] = low[u] = ++counter;
  for(int i = 0 ; i< g[u].size() ; i++){
      child++;
      int v = g[u][i];
      if(!vis[v]){
         par[v] = u;
         dfs(v);
         low[u] = min(low[u],low[v]);
         if(u == 1 && child > 1)
            s.insert(u);
         if(low[v] >= num[u]){
            if(u!=1){
               s.insert(u);
            }
         }
     }
      else if(par[u] != v){
         low[u] = min(low[u],num[v]);
      }
  }
}
int main()
{
 // freopen("a.txt","w",stdout);
  int test , cs = 1;
  scanf("%d", &test);
  while(test--){
       int node , edge;
       scanf("%d%d", &node , &edge);
       for(int i = 0 ; i< edge ; i++){
           int a ,b;
           scanf("%d%d",&a,&b);
           g[a].push_back(b);
           g[b].push_back(a);
       }
       counter = 0;
       memset(vis,0,sizeof(vis));
       dfs(1);
       printf("Case %d: %d\n",cs++ ,s.size());
       g.clear();
       s.clear();
       memset(low,0,sizeof(low));
       memset(num,0,sizeof(num));
  }
}
