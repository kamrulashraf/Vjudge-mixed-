#include <bits/stdc++.h>
using namespace std;
bool vis[30001];
int level[30001], lev[30001];
map < int , vector <pair <int,int> > > g;
int bfs(int s, int *level){
 memset(vis,0,sizeof(vis));
 int mmax = 0,save = 0;
 queue < int > q;
 q.push(s);
 vis[s] = 1;
 while(!q.empty()){
    int u = q.front();
    for(int i = 0 ; i< g[u].size() ; i++){
       int v = g[u][i].first;
       int cost = g[u][i].second;
       if(!vis[v]){
          vis[v] = 1;
          q.push(v);
          level[v] = level[u]+cost;
          if(level[v] > mmax){
             mmax = level[v];
             save = v;
          }
       }
    }
    q.pop();
 }

 return save;
}
int main()
{
     int test ,  cs = 1;
      scanf("%d", &test);
      while(test--){
        memset(vis,0,sizeof(vis));
        int node;
        scanf("%d", &node);
        for(int i = 1 ; i< node ; i++){
           int a, b , w;
           scanf("%d%d%d",&a,&b,&w);
           g[a].push_back(make_pair(b,w));
           g[b].push_back(make_pair(a,w));
        }

      int temp = bfs(0,level);
      memset(level,0,sizeof(level));
      temp = bfs(temp,level);
      bfs(temp,lev);
      printf("Case %d:\n",cs++);
      for(int i = 0 ; i< node ; i++){
         printf("%d\n",max(level[i],lev[i]));
      }
      g.clear();
      memset(level,0,sizeof(level));
      memset(lev,0,sizeof(lev));
  }

}
