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

int p[N];
void init(int n){
     for(int i = 0 ; i<= n ; i++)
         p[i] = i;
}

int find(int u){
     if(p[u] == u) return u;
     return p[u] = find(p[u]);
}

int makeUnion(int a , int b){
     int pa = find(a);
     int pb = find(b);
     if(pa == pb) return 0;
     p[pa] = pb;
     return 1;
}
int main()
{
    int n , m , cs = 1;;
    while(cin >> n >> m){
        if(!n && !m) break;
           init(n);
           for(int i = 0 ; i< m ; i++){
             int a , b;
             scaa(a,b);
             makeUnion(a,b);
           }
           set < int > s;


           for(int i = 1 ; i<= n ; i++){
              s.insert(find(i));
           }

           int res = s.size();
           printf("Case %d: %d\n",cs++ , res);
    }
    return 0;
}
