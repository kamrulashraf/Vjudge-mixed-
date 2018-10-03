#include <bits/stdc++.h>
using namespace  std;

#define N 100005
#define inf 2e17
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define MP make_pair
#define PB push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

ll vis[N] , dis[N];
vector < pii > adj[N];


void dfs(int s){
	 priority_queue < pii , vector<pii> , greater <pii> > q;
	 q.push(MP(0,s));

	 for(int i = 0 ; i< N ; i++) dis[i] = inf;
	 dis[s] = 0;
     while(!q.empty()){
        pii v = q.top();
        int cost = v.ff;
        int vv = v.ss;
        q.pop();
        for(int i = 0 ; i< adj[vv].size() ; i++){
             int a = adj[vv][i].ff;
             int b = adj[vv][i].ss;
             if(a+dis[vv] < dis[b]){
             	dis[b] = a+dis[vv];
             	q.push(MP(dis[b],b));
             }
        }
     }

}
int main()
{
	int test , cs = 1;
	sca(test);
	while(test--){
		 int n , m, s , t , node;
		 scaa(n,m);
		 scaaa(s,t,node);
		 for(int i = 0 ; i< m ; i++){
		 	int  a , b , c;
		 	scaaa(a,b,c);
		 	adj[a].push_back(MP(c,b));
		 	adj[b].PB(MP(c,a));
		 }

		 dfs(s);
		 for(int i = 1 ; i<= n ; i++){
		    vis[i] = dis[i];
		 }

		 dfs(node);
		 for(int i = 1 ; i<= n ; i++){
		    vis[i] = dis[i]+vis[i];
		 }
		 dfs(t);
		 ll res = inf;
         for(int i = 1 ; i<= n ; i++){
            vis[i] += dis[i];
            res = min(res,vis[i]);
         }

         printf("%lld\n",res);
         F(i,n+1) adj[i].clear();
	}
}
