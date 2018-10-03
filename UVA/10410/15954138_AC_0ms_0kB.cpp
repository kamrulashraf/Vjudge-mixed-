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

#define N 400005
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

#define SET(x) memset(x , -1 , sizeof x)
#define CLR(x) memset(x , 0 , sizeof x)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

int a[N] , b[N]  , dis[N];


// logic bfs e kom distance er node gula age thake. and parent hole distace 1 er ceye kom and age thakbe
int main()
{
	int n;
	while(~sca(n)){
		map < int , vector < int > > adj;
		for(int i = 0 ; i <n ; i++){
			 sca(a[i]);
			 dis[a[i]] = i;
		}

		stack < int > st;

		int root;
		sca(root);
		st.push(root);

		for(int i = 1 ; i < n ; i++){
			 int temp;
			 sca(temp);

			 while(1){
			 	 int par = st.top();

			 	 if(par == root || dis[par]+1 <  dis[temp]){ // distace 1 kom hole sibling hote pare
			 	 	adj[par].pb(temp);
			 	 	st.push(temp);
			 	 	break;
			 	 }
			 	 else st.pop();
			 }
		}

		for(int i = 1 ; i<= n ; i++){
			 printf("%d:",i);

			 for(int j = 0 ; j< adj[i].size() ; j++){
			 	printf(" %d",adj[i][j]);
			 }
			 printf("\n");
		}
	}

	return 0;
}
