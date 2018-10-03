#include <bits/stdc++.h>
using namespace std;
#define NN 505
int a[NN] , b[NN] , c[NN] ,d[NN] ,startTime[NN], vis[NN] , match[NN], h , m;
map < int , std::vector<int > > adj;
int bipartite(int u){
    if(vis[u] == 1) return 0;
    vis[u] = 1;
    for(int i=0;i<adj[u].size();i++){
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
    cin >> test;
    while(test--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d:%d %d %d %d %d",&h,&m, &a[i],&b[i],&c[i],&d[i]);
            startTime[i] = h*60+m;
        }
 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(startTime[i]+ abs(a[i]-c[i]) + abs(b[i]-d[i]) + abs(c[i]-a[j]) + abs(d[i] - b[j]) < startTime[j]){
                    adj[i].push_back(j);
                }
            }
        }
        int res = 0;
        memset(match,-1,sizeof match);
 
        for(int i=0;i<n;i++){
            memset(vis,0,sizeof vis);
            res += bipartite(i);
        }
 
        printf("Case %d: %d\n",cs++ ,n-res);
        adj.clear();
    }
}