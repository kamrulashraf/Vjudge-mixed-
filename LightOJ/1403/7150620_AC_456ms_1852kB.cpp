#include <bits/stdc++.h>
using namespace std;
#define NN 1005
std::vector< int > adj[NN];
int vis[NN] , match[NN];
int maximumBipartite(int u){
     if(vis[u] == 1) return 0;
     vis[u] = 1;
     // cout << adj[u].size() << ' ' << u << endl;
     for(int i = 0 ; i< adj[u].size() ; i++){
         int v = adj[u][i];
         // cout << u << '*' << v << endl;
         if(match[v] == -1 || maximumBipartite(match[v])){
            match[v] = u;
            return 1;
         }
     }
     return 0;
}
int main()
{
   int test, cs = 1;
   scanf("%d", &test);
   while(test--){
       int node ,edge;
       cin >> node >> edge;
       for(int i = 0 ; i < edge ; i++){
           int a , b;
           scanf("%d%d", &a,&b);
           adj[a].push_back(b);
       }
       int res = 0;
       memset(match , -1 , sizeof match);
       for(int i = 1 ; i<= node ; i++){
            memset(vis , 0 , sizeof vis);
            res += maximumBipartite(i);
       }
       res = node - res;
       printf("Case %d: %d\n",cs++ , res);
       for(int i = 0 ; i <= node ; i++) adj[i].clear();
   
   }
}
