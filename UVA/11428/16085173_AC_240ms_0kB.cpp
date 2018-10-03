
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

int b, d;
int main()
{
    ll n;
    std::vector< ll > v , vv;

    for( ll i = 0 ;  i < 100000 ; i++){
         ull temp = i*i*i;
         if(temp > 1e16) break;
         v.pb(temp);
         vv.pb(i);
    }


    while(scanf("%lld",&n)){
        if(n == 0) break;
        ll save = v.size()-1, save1 = 0;
        bool f = 0;
         for(ll i = 0 ; i< v.size() ; i++){
            int pos = lower_bound(v.begin() , v.end() , v[i]+n) - v.begin();
            if(v[pos] == v[i]+n){

               if(v[pos] < v[save]){
                  save = pos;
                  save1 = i;
               }
               f = 1;
            }
         }
         if(f == 0){
            printf("No solution\n");
         }
         else{
            printf("%lld %lld\n",vv[save] , vv[save1]);
         }
    }
//    cout << endl;
}
