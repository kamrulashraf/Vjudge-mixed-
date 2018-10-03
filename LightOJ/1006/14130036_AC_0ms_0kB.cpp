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
int dp[1000005];
int main()
{
//	freopen("in.txt","r" ,stdin);
	int test , cs = 1;
	sca(test);
	while(test--){
		 int a[7];
		 F(i,6){
		 	 sca(dp[i]);
		 	 dp[i]%=10000007;
		 }
		 int n;
		 sca(n);
		 for(int i = 6 ; i<= n  ; i++){
             dp[i] = 0;
             for(int j = 1 ; j<= 6 ; j++){
 				dp[i] = (dp[i]+dp[i-j])%10000007;
             }


		 }
//		 for(int i = 0 ; i<=  n ; i++){
//		 	 cout << i << ' ' << dp[i] << endl;
//		 }
		 printf("Case %d: %d\n",cs++,dp[n]%10000007);
	}
}
