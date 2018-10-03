#include <bits/stdc++.h>
using namespace std;
bool vis[10004];
stack <int> st;
map < int , vector <int> > g;
void topSort(int u){
 vis[u] = 1;
 for(int i = 0 ; i< g[u].size() ; i++){
    int v = g[u][i];
    if(!vis[v]){
       topSort(v);
    }
 }
 st.push(u);
}
void dfs(int u){
 vis[u] = 1;
 for(int i = 0 ; i< g[u].size() ; i++){
    int v = g[u][i];
    if(!vis[v]){
       topSort(v);
    }
 }
}
int main()
{
  int test , cs = 1;
  cin >> test;
  while(test--){
    int node , edge;
    cin >> node >> edge;
    for(int i = 0 ; i< edge ; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    memset(vis,0,sizeof(vis));
    for(int i = 1 ; i<= node ; i++){
       if(!vis[i])
          topSort(i);
    }
    memset(vis,0,sizeof(vis));
    int counter = 0;
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        if(!vis[temp]){
           counter++;
           dfs(temp);
        }
    }
    printf("Case %d: %d\n",cs++ , counter);
    g.clear();
  }

}
