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

int a[N] ,dp[N][25005];
int n;

int call(int indx , int tot){
	 if(indx >= n) return 0;
	 if(dp[indx][tot] != -1){
        return dp[indx][tot];
	 }
	 int temp = tot-a[indx];
	 int res1 = 0 , res2 = 0;
	 if(temp >=0){
	 	 res1 = a[indx] + call(indx+1,temp);
	 }
	 res2 = call(indx+1,tot);
	 return dp[indx][tot] = max(res1 , res2);
}
int main()
{
//    freopen("in.txt" , "r" , stdin);
//    freopen("out.txt" , "w" , stdout);
	int test , cs = 1;
	sca(test);
	while(test--){
		 int sum = 0;
		 sca(n);
		 F(i,n){
		 	 sca(a[i]);
		 	 sum += a[i];
		 }
		 int temp = sum/2;

         memset(dp,-1,sizeof dp);
		 int res = call(0,temp);
		 res = sum - 2*res;
		 printf("%d\n",res);
	}
}
