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

#define N 400005
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
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}

int a[55];

int main()
{
	int test , cs = 1;
	int n , t;
	while(scaa(n,t)){
		 if(n == 0 && t == 0) break;

         for(int i = 0 ; i< n ;  i++) sca(a[i]);
         std::vector< int > v;
		 for(int i = 0 ; i < n ; i++){
		 	 for(int j = i+1 ;j < n ; j++){
		 	 	 for(int k  = j+1 ; k< n ; k++){
		 	 	 	 for(int m = k+1 ; m < n ; m++){
		 	 	 	 	 int temp = lcm(a[i],a[j]);
		 	 	 	 	 temp = lcm(temp,a[k]);
		 	 	 	 	 temp = lcm(temp,a[m]);
		 	 	 	 	 v.pb(temp);
		 	 	 	 }
		 	 	 }
		 	 }
		 }

		 while(t--){
		 	int temp;
		 	sca(temp);
		 	int mmin = inf;
		 	int mmax = 0;
		 	for(int i = 0 ; i< v.size() ; i++){
                    int save  = temp/v[i] * v[i];
                    int l , u;
                    if(temp%v[i]==0){
                    	l = save;
                    	u = save;
                    }
                    else{
                    	l = save;
                    	u = save+v[i];
                    }

                    mmax = max(mmax,l);
                    mmin = min(mmin,u);
		 	}
		 	printf("%d %d\n",mmax , mmin);
		 }
	}
return 0;
}
