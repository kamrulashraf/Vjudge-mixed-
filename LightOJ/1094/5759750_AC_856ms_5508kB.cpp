#include <bits/stdc++.h>
using namespace std;
bool vis[30001];
map < int , vector < pair <int,int> > > g;
int bfs(int s, long long &ans){
 int save, mmax = 0;
 long long level[30001];
 memset(level,0,sizeof(level));
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
   //       cout << u <<  ' ' << v << ' ' << cost << ' ';
    //      cout << level[v] << endl;
          if(level[v] > mmax){
             mmax = level[v];
             save = v;
          }
       }
    }
    q.pop();
 }
 //cout << "*************" << endl;
 ans = mmax;
// cout << ans << ' ' << save << endl;
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
    long long ans;
    int temp = bfs(0, ans);
    memset(vis,0,sizeof(vis));
    bfs(temp , ans);
    printf("Case %d: %lld\n", cs++ ,ans);
    g.clear();
  }

}
