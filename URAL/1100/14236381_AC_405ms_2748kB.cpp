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
bool cmp(pii a , pii b){
   return a.ss > b.ss ;
}
int main()
{
	int n ;
	sca(n);
	vector < pii > v;
	F(i,n){
		int a , b;
		scaa(a,b);
		v.push_back(MP(a,b));
	}
	stable_sort(v.begin() , v.end(), cmp);
	F(i,n){
		printf("%d %d\n",v[i].ff , v[i].ss );
	}
}
