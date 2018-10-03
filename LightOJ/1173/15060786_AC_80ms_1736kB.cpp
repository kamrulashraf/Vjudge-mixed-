#include <bits/stdc++.h>
using namespace  std;

#define N 55
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

ull dp[N][N][2] = {0};

ull call(int a , int b, int flag){
    if(a == 0 && b == 0) return 1;
    if(a <= 0 && flag == 0) return 0;
    if(b <= 0 && flag == 1) return 0;
    ll res = 0;

//    cout << a << ' ' << b << ' ' << flag << endl;
    ull &ret = dp[a][b][flag];
    if(ret != -1) return ret;
    if(flag == 0){
    	 for(int i = 1 ; i<= a ; i++){
    	 	 res += call(a-i , b+i-1 , 1);
    	 }
    }
    else{

    	 for(int i = 1 ; i<= b ; i++){
    	 	 res += call(a+i-1,b-i , 0);
    	 }
    }
    ret = res;
    return res;
}
int main()
{
//    freopen("out.txt","w",stdout);
	int test , cs =1;
	sca(test);
	while(test--){
		 int n , m;
		 scaa(n , m);
		 ull res = 0;
		 memset(dp,-1,sizeof dp);
		 if(n <= 2){
		 	 res = 1;
		 }
		 else if(m == 1){
             res = call(1,n-3,0);
		 }
		 else{
		 	res = call(m-1,n-m,0);
		 }
		 printf("Case %d: %llu\n",cs++ , res);
	}
}
