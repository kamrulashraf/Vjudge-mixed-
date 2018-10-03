#include <bits/stdc++.h>
using namespace std;
#define NN 10000
int input(int &a){
    scanf("%d",&a);
}
int a[NN], b[NN], vis[NN],match[NN];
std::vector<int > adj[NN];
int bipartite(int u){
    if(vis[u]) return 0;
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++){
         int v = adj[u][i];
         if(match[v] ==-1 || bipartite(match[v])){
            match[v] = u;
            return 1;
         }
    }
    return 0;
}
int main()
{
    int test, n , m , cs=1;
    input(test);
    while(test--){
         input(n);
         for(int i = 0 ; i< n ; i++)
            input(a[i]);
 
         input(m);
         for(int i=0;i<m;i++)
            input(b[i]);
         
 
         for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if( (a[i]&&b[j]%a[i]==0)){
                    adj[i].push_back(j);
                    // cout << a[i] << ' ' << b[j] << endl;
                }
 
         memset(match,-1,sizeof match);
         int res=0;
         for(int i=0;i<n;i++){
            memset(vis,0,sizeof vis);
            res += bipartite(i);
         }
         printf("Case %d: %d\n",cs++ , res);
         for(int i=0;i<n;i++) adj[i].clear();
    }
 
}