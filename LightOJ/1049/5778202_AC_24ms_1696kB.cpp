#include <bits/stdc++.h>
using namespace std;
map < int , vector < int > > g;
map <int , map < int,int> > cost;
bool vis [105];
int ans;
int dfs(int u){
vis[u] = 1;

for(int i = 0 ; i< g[u].size() ; i++){
 int v = g[u][i];
 if(!vis[v]){
  //  cout << u << ' ' << v << ' ' << cost[u][v] << endl;
    ans += cost[u][v];
    dfs(v);
 }

}
return ans;
}
int main()
{
  int test , cs = 1;
  cin >> test;
  while(test--){
     int node;
     cin >> node;
     int sum = 0;
     for(int i = 0 ; i< node ; i++){
        int a , b , c ;
        cin >> a >> b>> c;
        cost[a][b] = c;
        cost[b][a] = 0;
        g[a].push_back(b);
        g[b].push_back(a);
        sum += c;
     }
     ans = 0;
     dfs(1);
     int temp = g[1][1];
     ans += cost[temp][1];
     printf("Case %d: %d\n", cs++ , min(ans , sum-ans));
     g.clear();
     memset(vis,0,sizeof(vis));
     cost.clear();
  }

}
