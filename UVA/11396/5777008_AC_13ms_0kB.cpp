#include <bits/stdc++.h>
using namespace std;
map < int , vector < int > > g;
bool vis [305];
bool color[305];
bool flag;
void dfs(int u){
vis[u] = 1;
for(int i = 0 ; i< g[u].size();i++){
  int v = g[u][i];
  if(!vis[v]){
     color[v] = 1-color[u];
     dfs(v);
  }
  else if(color[v] != 1-color[u]){
     flag = 1;
  }
}

}
int main()
{
  int node ,a , b;
  while(cin >> node && node){
     memset(vis,0,sizeof(vis));
     memset(color,0,sizeof(color));
     flag = 0;
     while(cin >>  a >> b){
        if(!a && !b) break;
        g[a].push_back(b);
        g[b].push_back(a);
     }
     for(int i = 1 ; i<= node ; i++){
        if(!vis[i]) dfs(i);
        if(flag == 1)
          break;
     }
     if(flag) cout << "NO" << endl;
     else cout << "YES" << endl;
     g.clear();
  }


}
