#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define pi           pair <int,int>
map < int , vector <int> > g;
vector < pi > ans;
int vis[N], num[N], low[N], parent[N],save[N];
int counter = 0;
void dfs(int u)
{
    int child = 0;
    counter++;
    num[u] = counter;
    low[u] = counter;
    vis[u] = 1;
    for(int i = 0 ; i< g[u].size() ; i++)
    {
        child++;
        int v = g[u][i];
        if(!vis[v])
        {
            vis[u] = 1;
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
          //  cout << u << ' ' << v << ' ' << low[v] << ' ' << num[u] << endl;
          // equal cause oi edge er sathe back edge thakleO lav nai
            if(low[v] > num[u]){
               int a = min(u,v);
               int b = max(u,v);
               ans.push_back(make_pair(a,b));
            }
        }
        else if(parent[u] != v)
            low[u] = min(low[u],num[v]);
    }

}
int main()
{
 // freopen("a.txt","w",stdout);
  int test, cs = 1;
  scanf("%d", &test);
  while(test--){
     int node ;
     scanf("%d", &node);
     for(int i = 0 ; i< node ; i++){
        int a, b;
        scanf("%d (%d)", &a , &b);
        for(int j = 0 ; j<b ; j++){
           int c;
           scanf("%d", &c);
           g[a].push_back(c);
           g[c].push_back(a);
        }
        counter = 0;
     }
     printf("Case %d:\n",cs++);
     for(int i = 0 ; i< node ; i++){
       counter = 0;
       if(!vis[i])
          dfs(i);
     }
     sort(ans.begin() , ans.end());
     printf("%d critical links\n",ans.size());
     for(int i = 0 ; i< ans.size() ; i++)
         printf("%d - %d\n", ans[i].first , ans[i].second);
     g.clear();
     memset(vis,0,sizeof(vis));
     memset(num,0,sizeof(num));
     memset(low,0,sizeof(low));
     memset(parent,0,sizeof(parent));
     ans.clear();

  }
  return 0;
}
