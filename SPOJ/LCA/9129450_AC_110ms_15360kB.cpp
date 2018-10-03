#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
using namespace std;
#define N 1005
long long MOD = 1000000007;
#define ll long long
#define inf 1e9;
bool vis[N];
int level[N], cost[N];
int table[N][25],mmax[N][25] , p[N];
int n , q , u ;
map < int , vector < int > > adj;
stack < int > st;
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

void topSort(int u){
	 vis[u] = 1;
	 for(int i = 0 ; i< adj[u].size() ; i++){
	 	  int v = adj[u][i];
	 	  if(vis[v] == 0){
	 	  	 topSort(v);
	 	  }
	 }
	 st.push(u);
}

void makeTable(){
	for(int i = 0 ; i <= n ; i++){
		 table[i][0] = p[i];
    }

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
//     freopen("inputf.in","r" , stdin);
	 int test , cs = 1, t , temp;
	 scanf("%d",&test);
	 while(test--){
	 	  printf("Case %d:\n",cs++);
	 	  memset(vis,0,sizeof vis);
	 	  memset(p,-1,sizeof p);
	 	  memset(level,0,sizeof level);
	 	  scanf("%d",&n);
	 	  for(int i = 1 ; i<= n ; i++){
	 	  	 scanf("%d",&t);
	 	  	 while(t--){
                 scanf("%d",&temp);
                 adj[i].push_back(temp);
                 p[temp] = i;
	 	  	 }
	 	  }

	 	  for(int i = 1 ; i<= n ; i++)
	 	  	  if(vis[i]==0) topSort(i);
	 	  memset(vis,0,sizeof vis);
	 	  while(!st.empty()){
	 	  	 temp = st.top();
	 	  	 if(vis[temp]==0) dfs(temp);
	 	  	 st.pop();
	 	  }
	 	  makeTable();
	 	  scanf("%d",&q);
	 	  while(q--){
	 	  	  int u , v, diff;
	 	  	  scanf("%d%d",&u,&v);
	 	  	  if(level[u] < level[v])
	 	  	  	 swap(u,v);

	 	  	  while( diff = level[u]-level[v]){
                   temp = log2(diff);
                   u = table[u][temp];
	 	  	  }
	 	  	  if(u==v){
	 	  	  	printf("%d\n",u);
	 	  	  }
	 	  	  else{
	 	  	  	  for(int i = 15 ; i>= 0 ; i--){
	 	  	  	  	  if(table[u][i] == table[v][i])
	 	  	  	  	  	 continue;
	 	  	  	  	  u = table[u][i];
	 	  	  	  	  v = table[v][i];
	 	  	  	  }
	 	  	  	  printf("%d\n",table[u][0]);
	 	  	  }
	 	  }
	 	  adj.clear();

	 }
}
