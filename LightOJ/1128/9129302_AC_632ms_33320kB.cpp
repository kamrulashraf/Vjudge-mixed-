#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;
#define N 100005
long long MOD = 1000000007;
#define ll long long
#define inf 1e9;
bool vis[N];
int level[N], cost[N];
int table[N][25],mmax[N][25] , p[N];
int n , q , u ;
map < int , vector < int > > adj;
void dfs(int u){
	 vis[u] = 1;
	 for(int i = 0 ; i< adj[u].size() ; i++){
	 	  int v = adj[u][i];
	 	  if(vis[v] == 0){
	 	  	 level[v] = level[u]+1;
	 	  	 dfs(v);
	 	  }
	 }
}

void makeTable(){
	for(int i = 0 ; i < n ; i++)
		 table[i][0] = p[i];

    for(int len = 1 ; 1 << len <= n ; len++){
    	  for(int i = 0 ; i <= n ; i++){
    	  	  if(table[i][len-1] != -1)
    	  	  	  table[i][len] = table[table[i][len-1]][len-1];
    	  	  else
    	  	  	  table[i][len] = -1;
    	  	  
    	  }
    }
}
int main()
{
     // freopen("inputf.in","r" , stdin);
	 int test , cs = 1;
	 scanf("%d",&test);
	 while(test--){
	 	  printf("Case %d:\n",cs++);
	 	  memset(vis,0,sizeof vis);
	 	  memset(p,-1,sizeof p);
	 	  cost[0] = 1;
	 	  scanf("%d %d",&n,&q);
	 	  for(int i = 1 ; i< n ; i++){
	 	  	 scanf("%d%d",&p[i],&cost[i]);
	 	  	 adj[p[i]].push_back(i);

	 	  }
	 	  // dfs(0);
	 	  makeTable();
	 	  // for(int i = 0 ; i< n ; i++){
     //         cout << i << ' ' <<  mmax[i][0] << ' ' << table[i][0] << endl;
     //     }

          int k , val;
          while(q--){
          	 scanf("%d%d",&k,&val);
             for(int i = 24 ; i>= 0 ; i--){
                    if(cost[table[k][i]] < val) continue;
                    k = table[k][i];
                      if(cost[k] == val) break;
                   // cout << i << '#' << k << ' ' << cost[table[k][i]] << ' ' << table[k][i] << endl;

             }
             printf("%d\n",k);
             adj.clear();
          }
	 }
}
