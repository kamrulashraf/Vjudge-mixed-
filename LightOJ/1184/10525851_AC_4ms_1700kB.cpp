#include <bits/stdc++.h>
using namespace std;
#define NN 1000
int vis[NN] , match[NN];
map < int , std::vector<int > > adj;
struct node{
   int aa , bb,  cc;
   node(int a , int b , int c){
      aa = a; bb = b ; cc = c;
   }
};
 
bool compre(node x , node y){
    if(abs(x.aa - y.aa) <= 12 && abs(x.bb-y.bb) <= 5 && x.cc == y.cc)
        return true;
    return false;
}
 
int bipartite(int u){
    if(vis[u] == 1) return 0;
    vis[u] = 1;
    for(int i = 0 ; i< adj[u].size() ; i++){
        int v = adj[u][i];
        if(match[v] == -1 || bipartite(match[v])){
            match[v] = u;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int test, cs = 1;
    scanf("%d",&test);
    while(test--){
        std::vector< node > v, v1;
        int male , female;
        scanf("%d%d", &male , &female);
 
        for(int i = 0 ; i < male ; i++){
            int a, b, c;
            scanf("%d%d%d",&a , &b , &c);
            v.push_back(node(a,b,c));
        }
 
        for(int i=0;i<female;i++){
            int a , b , c;
            scanf("%d%d%d", &a , &b , &c);
            v1.push_back(node(a,b,c));
        }
 
        for(int i = 0 ; i< male ; i++){
            for(int j=0;j< female ;j++){
                if(compre(v[i], v1[j])){
                    adj[i].push_back(j);
                }
            }
        }
 
        int res = 0;
        memset(match, -1 , sizeof match);
 
        for(int i = 0 ; i< male ; i++){
            memset(vis,0,sizeof vis);
            res += bipartite(i);
        }
       
        printf("Case %d: %d\n",cs++ ,res);
 
        adj.clear();
        v.clear();
        v1.clear();
    }
}