#include <bits/stdc++.h>
using namespace  std;

#define N 405
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

double dp[N][N];
bool vis[N][N];
double call(int n , int m){
     if(m == 0) return 0;
     double res  = 0;
     double &ret = dp[n][m];
     if(vis[n][m] == 1) return ret;
     if( n)  res = call(n,m-1)*.5 + (call(n-1,m-1)+1)*.5;
     else res = (call(1,m-1)-1)*.5 + call(n,m-1)*.5;
     vis[n][m] = 1;
     return ret = res;

}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n , m;
    scaa(n,m);
    double res = call(n,m);
    printf("%.7lf\n",res);
}
