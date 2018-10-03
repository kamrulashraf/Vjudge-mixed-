#include <bits/stdc++.h>
using namespace  std;
#define NN 1005
int arr[NN], vis[NN];
int save[NN];
map < int , std::vector<int > > g;
void dfs(int u){
    vis[u] = 1;
    save[u]++;
    // cout << u << ' ' << save[u] << ' ' << g[u].size() <<  endl;
    for(int i = 0 ; i< g[u].size() ; i++){
         int v = g[u][i];
         // cout << u << ' ' << v << ' ' << vis[v] << endl;
         if(!vis[v])
            dfs(v);
    }
}
int main()
{
    int n , k , m;
    int test , cs = 1;
    scanf("%d", &test);
    while(test--){
        scanf("%d%d%d", &k , &n , &m);
        for(int i = 0 ; i< k ; i++){
            scanf("%d", &arr[i]);
        }
        for(int i = 0 ; i< m ; i++){
            int a , b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            // cout << a << ' ' << b << endl;
        }
        for(int i = 0 ; i< k ; i++){
            memset(vis,0,sizeof vis);
            // cout << arr[i] << endl;
            dfs(arr[i]);
        }
        int counter = 0;
        for(int i = 1 ; i<= n ; i++){
            if(save[i] == k) counter++;
        }
        printf("Case %d: %d\n",cs++ , counter );
        memset(save,0,sizeof save);
        g.clear();
    }
}
