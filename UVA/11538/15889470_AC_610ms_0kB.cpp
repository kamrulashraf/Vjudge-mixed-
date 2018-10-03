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

int main()
{
   ull n , m;
   // read();
   // write();
   // draw 6*3 grid then think diagonal relation from diagonal size 1 to n
   while(scanf("%llu %llu",&n , &m) == 2){
   	  // cout << n << ' ' << m << endl;
   	  if(n == 0 && m== 0) break;

   	  ull mmax = max(m , n);
   	  ull mmin = min(m , n);
       ull res  = 0;
   	  for(ull i = 1 ; i< mmin ; i++){
         res += (i)*(i-1);
         res += (i)*(i-1);

   	  }
//   	  cout << res << endl;
   	  res += (mmax-mmin+1)*(mmin*(mmin-1));
//   	  cout << res << endl;

   	  res *= 2;

   	  res += n*m*(m-1) + n*m*(n-1);
//   	  res += m*(n-1);
   	  printf("%llu\n",res);
	}
	return 0;
}

