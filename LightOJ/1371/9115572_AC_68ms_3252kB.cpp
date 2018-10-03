#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <cassert>
#define ll long long
using namespace std;

#define pii pair<int,int>
#define ff first
#define ss second
#define N 100000
long long MOD = 1e9+7;
int w[N];
int c[N];
long long dp[N];
int main()
{
	int test , cs = 1, flag;
	scanf("%d",&test);
	while(test--){
		int n ;
		scanf("%d",&n);
		for(int i = 1 ; i<= n ; i++){
			 scanf("%d",&w[i]);
		}
		for(int i = 1 ; i<= n ; i++){
			 scanf("%d",&c[i]);
		}
		sort(w+1,w+n+1);
		sort(c+1,c+n+1);
        dp[0] = 1;
		for(int i = 1 ; i <= n ; i++){
			  int cur = 0;
			  for(int j = 1 ; j<= i ; j++){
			  	 if(c[j] >= w[i])
			  	 	 cur++;
			  }
			  dp[i] = (dp[i-1]*cur)%MOD;
		}
		if(dp[n] < 0) dp[n] += MOD;
        printf("Case %d: %lld\n",cs++ , dp[n]);
	}
}