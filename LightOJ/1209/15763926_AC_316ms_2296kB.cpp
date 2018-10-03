#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace  std;

#define N 1005
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
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

string a[505][3];
map < int , vector < int > > adj;
int vis[N] , l[N];
int match(int u){
	if(vis[u] == 1){
		return 0;
	}
	vis[u] = 1;
	for(int i = 0 ; i< adj[u].size() ; i++){
		int v = adj[u][i];
//		cout << v << endl;
		 if(l[v] == -1 || match(l[v])){
		 	l[v] = u;
		 	return 1;
		 }
	}
	return 0;
}

int main()
{
	 // read();
	int test , cs =  1;
	int f , m , v;
	sca(test);
	while(test--){
		 scaaa(m , f , v);
		 adj.clear();
		 memset(l,-1,sizeof l);
		 memset(vis,0,sizeof vis);
		 getchar();

		 for(int i = 0 ; i< v ; i++){
		 	 cin >> a[i][0] >> a[i][1];
//		 	 cout << i << ' ' <<  a[i][0] << ' ' << a[i][1] << endl;
		 }


		 for(int i = 0 ; i< v ; i++){
		 	  for(int j = 0 ; j< v ; j++){
		 	  	 if(i != j){
		 	  	 	 // cout << a[i][0] << ' '<< a[j][1] << endl;
		 	  	 	 if(a[i][0] == a[j][1] || a[i][1] == a[j][0]){
		 	  	 	 	adj[i].push_back(v+j);
		 	  	 	 }
		 	  	 }
		 	  }
		 }

		  // for(int i = 0 ; i< v ; i++){
		  // 	 for(auto x : adj[i]){
		  // 	 	 cout << x << ' ';
		  // 	 }
		  // 	 cout << endl;
		  // }

         int res =0;
          for(int i = 0 ; i< v ; i++){
          	  memset(vis, 0 , sizeof vis);
          	  res += match(i);
//          	  cout <<  match(i) << endl;
//          	  cout << "##" << endl;
          }

          res /= 2;
          res = v - res;

          printf("Case %d: %d\n",cs++ , res);
	}
}
