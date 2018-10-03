#include <bits/stdc++.h>
using namespace std;
vector < int > g[100005];
bool vis[100005];
vector < int> v;
void topSort(int u){
 vis[u] = 1;
 for(int i = 0 ; i< g[u].size() ; i++){
    int v = g[u][i];
    if(!vis[v]){
       topSort(v);
    }
 }
 v.push_back(u);
}

void dfs(int u){
 vis[u] = 1;
 for(int i = 0 ; i< g[u].size() ; i++){
    int v = g[u][i];
    if(!vis[v]){
       dfs(v);
    }
 }
 //v.push_back(u);
}
int main()
{
    int test;
    int node , edge;
    scanf("%d",&test);
    while(test--){
       scanf("%d%d",&node , & edge);
       for(int i = 0 ; i< edge ; i++){
          int a , b;
          scanf("%d%d",&a , & b);
          g[a].push_back(b);
       }
       for(int i = 1 ; i<= node ; i++){
          if(!vis[i]){
            topSort(i);
          }
       }
       int sz = v.size() , counter = 0;
       memset(vis,0,sizeof(vis));

       for(int i = sz-1 ; i>=0 ; i--){
          if(!vis[v[i]]){
             counter++;
             dfs(v[i]);
          }
       }
       printf("%d\n", counter);
       v.clear();
       for(int i = 0 ; i< 100005 ; i++)
          g[i].clear();
       memset(vis,0,sizeof(vis));
    }

}

