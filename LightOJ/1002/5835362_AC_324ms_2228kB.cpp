#include <bits/stdc++.h>
using namespace std;
#define inf 1e7
#define rep(i,x,y)   for(int i = x ; i< y ; i++)
#define pi pair <int,int>
bool vis[505];
int dp[505];
void clr(int n){
   rep(i,0,n+1) dp[i]= inf;
}
map < int , vector < pair<int,int> > >g;
void dijx(int s){
    priority_queue< pi > q;
    q.push(make_pair(0,s));
    vis[s] = 1;
    while(!q.empty()){
       int u = q.top().second;
       q.pop();
       for(int i = 0 ; i< g[u].size() ; i++){
            int v = g[u][i].first;
            int cost = g[u][i].second;
         //   cout << u << ' ' << v << endl;
         //   cout << dp[u] << ' ' << dp[v] << ' ' << cost << endl;
            cost = max(dp[u],cost);
            if(cost < dp[v]){
              dp[v] = cost;
              q.push(make_pair(-dp[v],v));
            }
       }
    }
}
int main()
{
    int test,cs = 1;
    scanf("%d",&test);
    while(test--)
    {
       memset(vis,0,sizeof(vis));
       g.clear();
       int node , edge;
       scanf("%d%d",&node,&edge);
       for(int i = 0 ; i < edge ; i++){
          int a , b , c;
          scanf("%d%d%d",&a,&b,&c);
          g[a].push_back(make_pair(b,c));
          g[b].push_back(make_pair(a,c));
       }
       int t;
       clr(node);
       scanf("%d",&t);
       dp[t] = 0;
       dijx(t);
       printf("Case %d:\n",cs++);
       for(int i = 0 ; i< node ; i++){
          if(dp[i] != inf) printf("%d\n",dp[i]);
          else printf("Impossible\n");
       }
    }
}
