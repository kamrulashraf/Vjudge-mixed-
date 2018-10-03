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
#define EPS 1e-5

const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
double p , q , r , s , t, u;
double fun(double x){
     double temp = p*exp(-x)+ q*sin(x) + r*cos(x)+s*tan(x)+t*x*x+u;
     return temp;
}
int main()
{

    while(cin >> p >> q >>   r >> s >> t >> u){
          int counter = 0;
         // cout << fun(.7554) << endl;
        double b = 0 , e = 1.0;
        if(fun(0)*fun(1) > 0){
           printf("No solution\n");
           continue;

        }


        while(e-b > 1e-9){
          //  if(counter > 60) break;
            counter++;
           double m = (b+e)/2.0;
       //    cout << b << ' ' << e << ' ' << m << ' '  << fun(m) << endl;
           if(fun(m) > 0) b= m;
           else e = m;
        }

        double m = (b+e)/2;

        printf("%.4lf\n",m);


    }

    return 0;
}
