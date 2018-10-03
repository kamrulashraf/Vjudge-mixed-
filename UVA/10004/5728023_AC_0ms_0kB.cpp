#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i = x; i< y ; i++)
int vis[205], flag, color[205];
map<int , vector <int> > g;
void dfs(int u)
{
    vis[u] = 1;
    rep(i,0,g[u].size()){
      int v = g[u][i];
      if(!vis[v]){
        color[v] = 1-color[u];
        dfs(v);
      }
      else if(color[v] != 1-color[u])
         flag = 1;

    }
}
int main()
{
  //  freopen ("myfile.txt","w",stdout);
    int node , edge,a,b;
    while(cin >> node && node){
        flag = 0;
        memset(vis,0,sizeof(vis));
        cin >> edge;
        rep(i,0,edge){
          cin >> a >> b;
          g[a].push_back(b);
          g[b].push_back(a);
        }
        dfs(0);
        if(flag == 1) cout << "NOT BICOLORABLE." << endl;
        else cout << "BICOLORABLE." << endl;
        g.clear();
    }
}
