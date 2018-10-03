#include <bits/stdc++.h>
using namespace std;
#define NN 20005
stack < int > st;
int flag = 0;
int vis[NN];
map < int , vector <int> > adj;
void top(int u){
   vis[u] = 1;
   for(int i = 0 ; i < adj[u].size() ; i++){
       int v = adj[u][i];
       if(!vis[v])
         top(v);
   }
   st.push(u);
}

void dfs(int u){
   vis[u] = 1;
//   cout << u << endl;
   for(int i = 0 ; i < adj[u].size() ; i++){
       int v = adj[u][i];
       if(!vis[v])
         dfs(v);
      else flag = 1;
   }
   vis[u] = 2;
}
int main()
{
     int node , edge;
     cin >> node >> edge;
     for(int i = 0 ; i< edge ; i++){
        int a ,b;
        cin >> a >> b;
        adj[a].push_back(b);
     }
     memset(vis,0,sizeof vis);
     for(int i = 1 ; i<= node ; i++){
         if(!vis[i])
         top(i);
     }
     memset(vis,0,sizeof vis);
     while(!st.empty()){
         int u = st.top();
//         cout << '*' << u << endl;
         st.pop();
        if(vis[u] == 0){
            dfs(u);
         }
     }
     if(flag == 0){
         cout << "YES" << endl;
     }
     else cout << "NO" << endl;


}
