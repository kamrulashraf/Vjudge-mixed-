#include <bits/stdc++.h>
using namespace std;
#define pi   pair <int,int>
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define inf 1e7;
map < int , vector <pi> > g;
int dp[20005];

void clr(int n){
  rep(i,0,n+1) dp[i]= inf;
}

int dijx(int s, int t){
  priority_queue < pi >  q;
  q.push( make_pair(0,s));
  dp[s] = 0;
  while(!q.empty()){
     int u = q.top().second;
     if(u == t) return dp[u];
     q.pop();
     for(int i = 0 ; i< g[u].size() ; i++){
        int v = g[u][i].first;
        int cost = g[u][i].second;
        if(dp[u]+cost < dp[v]){
           dp[v] = dp[u]+cost;
           q.push(make_pair(-dp[v], v));
        }
     }
  }
return -1;
}
int main()
{
  int test , cs = 1;
  scanf("%d", &test);
  while(test--){
      int node , edge , source  , target;
      cin >> node >> edge >> source >> target;
      for(int i = 0 ; i< edge ; i++){
         int a, b , w;
         cin >> a >> b >> w;
         g[a].push_back(make_pair(b,w));
         g[b].push_back(make_pair(a,w));
      }
      clr(node);
      int temp = dijx(source, target);
      printf("Case #%d: ",cs++);
      if(temp == -1) cout << "unreachable" << endl;
      else cout << temp << endl;
      g.clear();
  }

}
