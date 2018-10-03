#include <bits/stdc++.h>
using namespace  std;
#define NN 1005
bool vis[NN];
int level[NN];
std::vector< int > prime[NN];
void factor(int n){
    for(int i = 2 ; i<= n ; i++){
        if(vis[i] == 0){
            for(int j = i*2 ;  j<= n ; j+= i){
                prime[j].push_back(i);
                vis[j] = 1;
            }
        }
    }
}
int bfs(int source , int target){
     queue < int > q;
     vis[source] = 1;
     level[source] = 0;
     q.push(source);
     while(!q.empty()){
        int u = q.front();
        for(int i = prime[u].size()-1 ; i >= 0 ; i--){
            int v = prime[u][i];
            if(u+v <= target && level[u+v] == 1e7){
                q.push(u+v);
                level[u+v] = min(level[u+v],level[u]+1);
                if(u+v == target) return level[target];
             }
//            cout << u << ' ' << v << ' ' << u+v << ' ' <<  level[u+v] <<  endl;
        }
        q.pop();
     }
     return -1;
}
int main()
{
    int n , k , m;
    int test , cs = 1;
    factor(1000);
    scanf("%d", &test);
    while(test--){
        memset(vis, 0  , sizeof vis);
        int source , target;
        scanf("%d%d",&source , &target);
        for(int i = 0 ; i<= target ; i++) level[i] =  1e7;
        int ans;
        if(source == target) ans = 0;
        else
        ans = bfs(source , target);
        printf("Case %d: %d\n",cs++ , ans);
    }
}
