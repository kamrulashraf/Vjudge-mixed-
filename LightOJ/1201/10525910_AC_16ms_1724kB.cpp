#include <bits/stdc++.h>
using namespace std;
#define NN 1005
int vis[NN] , color[NN], parent[NN];
std::vector< int > adj[1005];
 
int maximumBipartite(int u){
    if(vis[u] == 1) return 0;
    vis[u] = 1;
    for(int i = 0 ; i< adj[u].size() ; i++){
        int v = adj[u][i];
        // cout << u << ' ' << v << endl;
        if(parent[v] == -1 || maximumBipartite(parent[v])){
            parent[v] = u;
            return 1;
        }
    }
    return 0;
}
void bicolor(int u){
   vis[u] = 1;
   for(int i = 0 ; i< adj[u].size() ; i++){
      int v = adj[u][i];
      if(!vis[v]){
        color[v] = 1 - color[u];
        bicolor(v);
      }
   }
}
 
int main()
{
   int test, cs = 1 ;
   scanf("%d", &test);
   while(test--){
       int node , edge;
       scanf("%d%d",&node,&edge);
       for(int i = 0 ; i< edge ; i++){
            int a , b;
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
       }
       memset(parent , -1 , sizeof parent);
       int res = 0;
       memset(color,0,sizeof color);
       memset(vis, 0 , sizeof vis);
       for(int i = 1 ; i<= node ; i++){
         if(!vis[i]) bicolor(i);
       }
       for(int i = 1 ; i<= node ; i++){
          int x = i;
          // cout <<  i << ' ' << color[i] << endl;
          memset(vis,0,sizeof vis);
          if(color[x]){
           int flag = maximumBipartite(x);
           res += flag;
         }
       }
       // cout << res << endl;
       res = max(res, node-res);
       printf("Case %d: %d\n",cs++ , res);
       for(int i = 0 ; i<= 1000 ; i++) adj[i].clear();
 
   }
}
 