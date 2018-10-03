#include <bits/stdc++.h>
using namespace  std;

#define N 105
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
int n;
int a[N] , dp[N][N][N];

int call(int indx , int l , int r){
     if(indx >= n) return 0;
	 int res = 0;
	 if(dp[indx][l][r] != -1){
	    return dp[indx][l][r];
	 }
	 if(a[indx] >= a[l] && a[indx] <= a[r]){

	 		int res2 =1+call(indx+1,indx,r);

	 		int res3 =1+call(indx+1,l,indx);
	 	    res = max(res2 , res3);

	 }
	 int res1 = call(indx+1,l,r);
	 return dp[indx][l][r] = max(res,res1);
}
int main()
{
	int test , cs = 1;
	sca(test);
	while(test--){
		sca(n);
		F(i,n){
			 sca(a[i]);
		}
		memset(dp,-1,sizeof dp);
		a[101] = -inf;
		a[102] = inf;
		int res =call(0,101,102);
		printf("Case %d: %d\n",cs++ , res);
	}
}
