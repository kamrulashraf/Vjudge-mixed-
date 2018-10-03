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

#define N 1000005
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

std::vector< int > prime[N];
std::vector< int > p;
int mark[N];
int cur = 0;
void seive(){

	for(int i = 2 ; i<= 1000000 ; i++){
		if(mark[i] == 0){
			p.pb(i);
			prime[i].pb(i);
           for(int j = 2*i ; j<= 1000000 ; j+= i){
           	  mark[j] = 1;
           	  prime[j].pb(i);
           }
		}
	}
}

double dp[N];
bool vis[N];

double call(int n, int counter){
    if(n == 1) return 0;
    int sz = upper_bound(p.begin() , p.end() , n)- p.begin();
    int temp = prime[n].size();
    if(vis[n] == 1) return dp[n];
    double res = 1;
    double need = 1 - (sz-temp)/(double) sz;
    for(int i = 0 ; i < prime[n].size() ; i++){
         int temp = n/prime[n][i];
         res += 1.0/sz * call( temp , counter+1);
    }
//    cout << res << endl;
    vis[n] = 1;
    return dp[n] = 1.0/need*res;
}
int main()
{
	seive();
	 int test , cs = 1;
	 sca(test);
//	 int mmax = 0;
//	 int save;
//	 for(int i = 1 ; i <= 1000000 ; i++){
//	    int temp = prime[i].size();
//        if(temp > mmax){
//          mmax = temp;
//          save = i;
//        }
//     }
//     cout << mmax << ' ' << save <<  endl;
//
//
//     for(auto x : prime[save]) cout << x << ' ' ; cout << endl;

	 while(test--){
	 	int a;
	 	sca(a);
//	 	memset(vis,0,sizeof vis);
	 	double res = call(a,0);
	 	printf("Case %d: %8lf\n",cs++ , res);
	 }
  return 0;
}
