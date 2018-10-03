#include <bits/stdc++.h>
using namespace  std;

#define N 100005
#define inf 2e9
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
int n ,dp[2050][21][21];

int r , c , sx, sy;
vector < pii > v;
int call(int indx , int mask , int x , int y){
	int res = inf;
	if(indx == n) return abs(sx-x)+abs(sy-y);
	if(dp[mask][x][y] != -1) return dp[mask][x][y];
	for(int i = 0 ; i< n ; i++){
		 if(mask & (1<<i)){

		 }
		 else{
		 	int temp = mask | (1<<i);
//		 	cout << temp << '#' << abs(x-v[i].ff) + abs(y-v[i].ss) << endl;
		 	res = min(res, abs(x-v[i].ff) + abs(y-v[i].ss) + call(indx+1,temp , v[i].ff , v[i].ss));
		 }
	}
	return dp[mask][x][y] = res;
}
int main()
{
	int test , cs = 1;
	sca(test);
	while(test--){
        v.clear();
        memset(dp,-1,sizeof dp);
		int x , y;
		scaa(r,c);
		scaa(x,y);
		sx = x;
		sy = y;
		sca(n);
		F(i,n){
			int a , b;
			scaa(a,b);
			v.push_back(MP(a,b));
		}
		int res = call(0,0,x,y);
		printf("The shortest path has length %d\n",res);
	}
}