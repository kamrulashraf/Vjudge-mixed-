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
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define SET(x) memset(x , -1 , sizeof x)
#define CLR(x) memset(x , 0 , sizeof x)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

int a[N];
int main()
{
    int n;
    cin >> n;
    F(i , n) cin >> a[i];
    sort(a , a+n);
    reverse(a, a+n);
    ll res = 0;
    for(int i = 0 ; i< n ; i++){
         if(i==0) res += a[i]*2;
         else res += a[i];
    }

    cout << res << endl;
}
