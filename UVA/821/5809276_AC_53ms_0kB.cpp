#include <bits/stdc++.h>
using namespace std;
float counter;
bool vis[105];
int level[105];
map < int , vector < int> > g;
int bfs(int s){
  int sum = 0;
  queue < int > q;
  q.push(s);
  vis[s] = 1;
  while(!q.empty()){
     int u = q.front();
     q.pop();
     for(int i = 0 ; i< g[u].size() ; i++){
        int v = g[u][i];
        if(!vis[v]){
           vis[v] = 1;
           level[v] = level[u]+1;
           sum += level[v];
           counter++;
           q.push(v);
        }
     }

  }
return sum;
}
int main()
{
  int a , b , node, cs= 1;
  while(cin >> a >> b){
     if(!a && !b) break;
     node = 0;
     node = max(a,b);
     g[a].push_back(b);
     while(cin >> a >> b){
        if(!a && !b) break;
        int m = max(a,b);
        node = max(node, m);
        g[a].push_back(b);
     }
     float sum = 0;
     counter = 0;
     for(int i = 1 ; i<= node ; i++){
        memset(vis,0,sizeof(vis));
        memset(level,0,sizeof(level));
        sum += bfs(i);
     }

     float ans = sum/counter;
     printf("Case %d: average length between pages = %.3f clicks\n",cs++ , ans);
     g.clear();

  }

}
