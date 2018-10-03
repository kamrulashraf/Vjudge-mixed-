#include <bits/stdc++.h>
using namespace std;
map < int , vector <int> > g;
int level1[250], level2[250];
bool vis[250];
void bfs(int temp, int level[ ]){
    memset(vis,0,sizeof(vis));
    queue < int > q;
    q.push(temp);
    vis[temp] = 1;
    while(!q.empty()){
       int u = q.front();
       for(int i = 0 ; i< g[u].size() ; i++){
          int v = g[u][i];
          if(!vis[v]){
              vis[v] = 1;
              level[v] = level[u]+1;
              q.push(v);
          }
       }
      q.pop();
    }


}
int main()
{
   int test, cs = 1;
   cin >> test;
   while(test--){
      int node , edge;
      cin >> node >> edge;
      for(int i = 0 ; i< edge ; i++){
         int a,b;
         cin >> a >> b;
         g[a].push_back(b);
         g[b].push_back(a);
      }
      int s ,d;
      memset(level1 ,0 , sizeof(level1));
      memset(level2,0,sizeof(level2));
      cin >> s >> d;
      bfs(s,level1);
      bfs(d,level2);
      int mmax = 0;
      for(int i = 0 ; i< node ; i++){
          mmax = max(mmax,level1[i]+level2[i]);
      }
      printf("Case %d: %d\n",cs++ , mmax);
      g.clear();

   }

}
