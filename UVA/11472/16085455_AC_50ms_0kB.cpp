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
int n , m;
ll mod = 1000000007;
ll dp[101][11][1050];

ll call(int indx , int last , int mask){
     if(last < 0 || last >= n) return 0;

 //    cout << indx << ' ' << last << ' ' << mask << endl;

     int temp = mask | (1<<last);

         if(indx == m-1){
    //         cout << (1<<n) << endl;
            if((1<<n)-1 == temp){
            //    cout << "dsg" << endl;
                return 1;
            }
            else return 0;
         }
     ll res  = 0;
     ll &ret = dp[indx][last][mask];
     if(ret != -1) return ret;

     res = call(indx+1 , last+1 , temp)%mod;
     res = (res + call(indx+1 , last-1 , temp))%mod;

     return ret = res;
}
int main()
{
    int test , cs = 1;
    sca(test);
    while(test--){
          scaa(n , m);
          SET(dp);

          ll res = 0;
          for(int j = 0 ; j< m ; j++){
              for(int i = 1 ; i< n ; i++){
                 res = (res + call(j , i , 0))%mod;
              }
          //    cout << res << endl;
          }

        //  cout << res << endl;
         printf("%lld\n",res);
    }
}
