#include <bits/stdc++.h>
using namespace std;
#define N 30000
int counter;
bool vis[N+5];
map < int, vector < int> > g;
int dfs(int u){
    vis[u]=1;
    counter++;
    for(int i = 0 ; i< g[u].size() ; i++){
        int v = g[u][i];
        if(!vis[v])
          dfs(v);
    }
return counter;
}

int main()
{
 //  freopen("a.txt","w",stdout);
   int test, cs = 1;
   cin >> test;
   while(test--){
      memset(vis,0,sizeof(vis));
      g.clear();
      int node , edge;
      scanf("%d%d",&node , &edge);
      for(int i = 0 ; i< edge ; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
      }
      int mmax = 0;
      for(int i = 1 ; i<= node ; i++){
          counter = 0;
          if(!vis[i]){
             mmax = max(dfs(i),mmax);
          }
      }
      printf("%d\n",mmax);
   }

}
