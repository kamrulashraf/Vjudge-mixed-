#include <bits/stdc++.h>
using namespace std;
#define NN 22
#define PP 405
int row , col;
char ch[NN][NN];
int match[PP], color[PP] , vis[PP];
vector < int > adj[PP];
int fx[]= {0,1};
int fy[]= {1,0};
void dfs(int u){
    vis[u] = 1;
    for(int i = 0 ; i< adj[u].size() ; i++){
        int v = adj[u][i];
        if(!vis[v]){
            color[v] = 1-color[u];
            dfs(v);
        }
    }
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
        ios_base::sync_with_stdio(0); cin.tie(0);

    int test ,cs = 1;
    cin >> test;
    while(test--){
        int gold = 0;
        int save[NN][NN] = {0};
        cin >> row >> col;
        for(int i = 0 ; i< row ; i++){
             for(int j = 0 ; j < col ; j++){
                 cin >> ch[i][j];
                 if(ch[i][j] == '*'){
                    gold++;
                    save[i][j] = gold;
                 }
             }
        }
        // make adjacent list
        std::vector< int > v;
        for(int i = 0 ; i< row ; i++){
            for(int j = 0 ; j< col ; j++){
                if(ch[i][j] == '*'){
                    if(save[i][j]) v.push_back(save[i][j]);
                    for(int k = 0 ; k<2 ; k++){
                            int x = fx[k]+i;
                            int y = fy[k]+j;
                            if(ch[x][y] == '*' && x < row && y < col){
                                adj[save[i][j]].push_back(save[x][y]);
                                adj[save[x][y]].push_back(save[i][j]);
                            }
                    }
                }
            }
        }

        memset(color,0,sizeof color);
        memset(vis,0,sizeof vis);
        for(int i = 0 ; i< v.size() ; i++){
            int x = v[i];
            if(!vis[x])
                dfs(x);
        }

       memset(match,-1,sizeof match);
       int res = 0;


       for(int i = 0 ; i< v.size() ; i++){
          memset(vis, 0 , sizeof(vis));
          if(color[v[i]])
          res += bipartite(v[i]);
       }
       res = (gold - 2*res) + res;
       printf("Case %d: %d\n",cs++ , res );
       v.clear();
       for(int i = 0 ; i<= PP ; i++) adj[i].clear();


    }
}
