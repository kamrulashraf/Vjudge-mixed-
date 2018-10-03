#include <bits/stdc++.h>
using namespace std;
map < int , vector <int> > g;
bool vis[105];
stack < int > st;
void dfs(int u){
vis[u] = 1;
for(int i = 0 ; i< g[u].size() ; i++){
   int v = g[u][i];
   if(!vis[v]) dfs(v);
}
 st.push(u);
}
int main()
{
  int node , edge;
  while(cin >> node >> edge){
     if(node == 0 && edge == 0) break;
     int a, b;
     for(int i = 0 ; i< edge ; i++){
       cin >> a >> b;
       g[a].push_back(b);

     }
     memset(vis,0,sizeof(vis));
     for(int i = 1 ; i<= node ; i++){
         if(!vis[i])
           dfs(i);
     }
     int c = 0;
     while(!st.empty()){
        int temp = st.top();
        st.pop();
        if(c) cout << " ";
        cout << temp ;
        c++;
     }
     g.clear();
     cout << "\n";
  }

}
