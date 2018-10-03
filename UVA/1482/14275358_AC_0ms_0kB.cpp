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
//int call(int n, int counter){
//    if(n == 0) return 1;
//    if(n == 1) return 1;
//    map < int , int > mark;
//    vector < int > v;
//    int temp ;
//    if(n&1) temp = n/2;
//    else temp = n/2;
////    cout << temp  << endl;
////    cout << n << endl;
//    for(int i = n -1 ; i> temp ; i--){
////       cout << i << endl;
//       v.push_back(call(i,counter+1));
//    }
//    for(auto x : v){
//       mark[x] = 1;
//       if(n == 5) cout << x << ' ' ;
//    }
//
//    for(int i = 0 ; i<= 20 ; i++){
//       if(mark[i] == 0) return i;
//    }
//}

ll fun(ll num){
    if(num&1) return fun(num/2);
    else return num/2;
}
int main()
{

   // freopen("out.txt","w" , stdout);
//    cout << call(6,1) << endl;
//   for(int i = 1 ; i<= 20 ; i++){
//      cout << i << ' ' << call(i,0) << endl;
//   }
    int test , cs = 1;
    sca(test);

    while(test--){
       int n;
       sca(n);
       ll res = 0;
       for(int i = 0 ; i< n ; i++){
           ll temp;
           scanf("%lld",&temp);
           temp = fun(temp);
           res ^= temp;
       }
       if(res) printf("YES\n");
       else printf("NO\n");
    }
}
