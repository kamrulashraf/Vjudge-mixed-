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

#define N 5000005
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
int mark[N] , dp[N];
void seive(){

	 for(int i = 2 ; i<= 5000000 ; i++){
	 	 if(!mark[i]){
	 	 	 for(int j = 2*i ; j<= 5000000 ; j += i){
	 	 	 	 mark[j] += i;
	 	 	 }
	 	 }
	 }
}
int main()
{
	int test ,  cs = 1;
	seive();
	mark[1] = 1;

	for(int i = 2 ; i<= 5000000 ; i++){
		 if(mark[mark[i]] == 0){
		 	dp[i] = dp[i-1]+1;
		 }
		 else dp[i] = dp[i-1];
	}

//	for(int i = 0 ; i< 50 ; i++){
//		 cout << i << ' ' << dp[i] << endl;
//	}

	int a , b;
	while(sca(a)){
		if(a == 0) break;
		sca(b);
		if(a > b) swap(a,b);
		int res = dp[b] - dp[a-1];
		printf("%d\n",res);
	}
}
