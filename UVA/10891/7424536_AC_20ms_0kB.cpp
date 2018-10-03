#include <bits/stdc++.h>
using namespace std;
#define NN 104
#define inf 1e9
int n;
int a[NN];
int dp[NN][NN];
int call(int b , int e){
	int mmax = -inf;
	int sum = 0;
	if(b > e) return 0;
	if(dp[b][e] != -1) return dp[b][e];
	for(int i = b ; i<= e ; i++){
		 sum += a[i];
		 mmax = max(mmax,sum-call(i+1,e));
	}
    sum = 0;
	for(int i = e ; i >= b ; i--){
		sum += a[i];
        mmax = max(mmax, sum-call(b,i-1));
	}
	return dp[b][e] = mmax;
}
int main()
{
	 while(scanf("%d",&n)){
	 	 if(n == 0) break;
         for(int i = 0 ; i  < n ; i++){
         	 scanf("%d",&a[i]);
         }
         memset(dp,-1,sizeof dp);
         int res = call(0,n-1);
         cout << res << endl;
	 }
}