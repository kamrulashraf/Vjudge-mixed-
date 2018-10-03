#include <bits/stdc++.h>
using namespace std;
#define NN 20005
#define white 0
#define black 2
#define grey 1
int num[NN] , vis[NN] , low[NN], counter, newCounter, parent[NN], leaf;
stack <int> st;
std::vector< int > adj[NN];
std::vector<int > g[NN];
void scc(int u){
     vis[u] = grey;
     low[u] = num[u] = ++counter;
     st.push(u);
     for(int i = 0 ; i< adj[u].size() ; i++){
        int v = adj[u][i];
        if(vis[v] == white)
            scc(v);
        if(vis[v] == grey)
            low[u] = min(low[v],low[u]);
     }

     if(low[u] == num[u]){
        newCounter++;
        // cout << newCounter << ' ';
        while(1){
            int temp = st.top();
            parent[temp] = newCounter;
            vis[temp] = black;
            // cout << temp << ' ';
            st.pop();
            if(u == temp) break;
        }
        // cout << endl;
     }
}

void shirnk(int node){
    for(int i = 1 ; i<= node ; i++){
        for(int j = 0 ;  j< adj[i].size() ; j++){
            if(parent[i] != parent[adj[i][j]]){
                    g[parent[i]].push_back(parent[adj[i][j]]);
            }
        }
    }
}

void topsort(int u){
    vis[u] = 1;
    for(int i = 0 ; i< g[u].size() ; i++){
        int v = g[u][i];
        if(!vis[v])
            topsort(v);
    }
    st.push(u);
}

void dfs(int u){
    vis[u] = 1;
    // cout << u << ' ' ;
    for(int i = 0 ; i< g[u].size() ; i++){
        int v = g[u][i];
        if(!vis[v])
            dfs(v);
    }
    if(g[u].size() == 0){
       // cout << u << endl;
       leaf++;
    }
}
int main()
{
   int test, cs = 1;
   scanf("%d", &test);
   while(test--){
     int node ,edge , a, b;
     scanf("%d%d", &node,&edge);
     for(int i = 0 ; i< edge ; i++){
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
     }
     newCounter = 0;
     for(int i = 1 ; i<= node ; i++){
        counter = 0;
        if(vis[i] == 0){
            scc(i);
        }
     }

     // print 
     // for(int i =  1 ; i<= node ; i++)
     //     cout << i << ' ' << parent[i] << endl;

     shirnk(node);
     memset(vis,0,sizeof vis);
     for(int i = 1 ; i<= newCounter ; i++){
        if(!vis[i]){
            topsort(i);
        }
     }
     memset(vis,0,sizeof vis);
     leaf = 0;
     int ans = 0;
     while(!st.empty()){
        int temp = st.top();
        if(!vis[temp]){
            dfs(temp);
            // cout << endl;
            ans++;
        }
        st.pop();
     }
     if(newCounter == 1) ans = 0;
     else ans = max(leaf , ans);
     printf("Case %d: %d\n",cs++ ,ans);
     for(int i = 0 ; i<= node ; i++){
         adj[i].clear();
         g[i].clear();
         low[i] = 0;
         num[i] = 0;
         vis[i] = 0;
     }

   }
}