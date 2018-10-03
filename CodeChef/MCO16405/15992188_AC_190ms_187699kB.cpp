#include <bits/stdc++.h>
using namespace  std;

#define N 4000005
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define write() freopen("out.txt", "w" , stdout)
#define read() freopen("in.txt" , "r", stdin)
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define SET(x) memset(x , -1 , sizeof x)
#define CLR(x) memset(x , 0 , sizeof x)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};


ll a[N];
#define white 0
#define grey 1
#define black 2
int counter = 0;
int vis[N], num[N],low[N], cycle[N] ;
ll dp[N];
stack < ll > st;
ll arr[N];
map < int , vector<int> > adj , dag;
void targan(int u){
      vis[u] = grey;
      num[u] = low[u] = counter++;
      st.push(u);

      for( auto v : adj[u]){
      	 if(vis[v] == white)
      	 	targan(v);
      	 if(vis[v] == grey)
      	 	low[u] = min(low[u], low[v]);

      }

      if(low[u] == num[u]){
      	  ll sum = 0;
      	  while(1){
      	  	 int tt = st.top();
      	  	 sum += a[tt];
      	  	 st.pop();
      	  	 vis[tt] = black;
      	  	 cycle[tt] = u;
      	  	 if( tt == u) break;
      	  }
      	  arr[u] = sum;

      }
}

void shirnk(int node){
	 for(int i = 0 ; i< node ; i++){
	 	 for(int j = 0 ; j< adj[i].size() ; j++){
	 	 	 int tt = adj[i][j];
	 	 	 if(cycle[i] != cycle[tt]){
                  dag[cycle[i]].pb(cycle[tt]);
	 	 	 }
	 	 }
	 }
	 return;
}


void createDag(int n){
	counter = 1;
	while(!st.empty()) st.pop();
	dag.clear();
	CLR(num);
	CLR(vis);
	CLR(low);
	CLR(dp);
	CLR(arr);
	CLR(cycle);
	for(int i = 0 ; i< n ; i++){
		 if(!vis[i]) targan(i);
	}
	shirnk(n);
}


void dfs(int u){
     vis[u] = 1;
     // cout << u+1 << '#' << endl;

     ll res = 0;
	 for(auto x : dag[u]){
	 	 if(vis[x] == 0){
	 	    dfs(x);
	 	 }
	 }

     for(auto x : dag[u]){
     	res = max(res, dp[x]);
     }
	 dp[u] = res+arr[u];
	 return;
}
int main()
{
	//read();
	int n , m;
	scaa(n , m);

	for(int i = 0 ; i < n ; i++){
		scanf("%lld",&a[i]);
	}
	for(int i = 0 ; i< m ; i++){
		int a , b;
		scaa(a,b);
		a--;
		b--;
		adj[a].pb(b);
	}
	createDag(n);
	adj.clear();
    CLR(vis);
	for(int i = 0 ; i< n ; i++){
		if(vis[cycle[i]] == 0)
			 dfs(cycle[i]);
	}

	for(int i = 0 ; i< n ; i++){
		 if(i) printf(" %lld",dp[cycle[i]]);
		 else printf("%lld",dp[cycle[i]]);
	}
	printf("\n");

	return 0;
}
