#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
long long MOD = 1000000007;
#define ll long long
 
 
inline ll gcd(ll a, ll b) {
  while (a > 0 && b > 0) {
    if (a > b) a %= b;
    else b %= a;
  }
  return a + b;
}
template < class T > inline T big(T b, T p, T N){
    if(!p) return 1;
    if(!(p&1)){
            T x = big(b,p/2,N);
            return (x * x)%N;
       }
    return (b * big(b,p-1,N))%N;
}
 
long long modInverse(ll n, ll mod){
  return big((ll) n,mod-2, mod);
}
 
 
using namespace std;
int main()
{
   int test , cs = 1;
   scanf("%d",&test);
   while(test--){
       ll n , color;
       scanf("%lld%lld",&n, &color);
       ll res = 0;
       for(ll i = 0 ; i< n ; i++){
             res = (res+big(color,gcd(i,n),MOD))%MOD;
       }
       res = (res * modInverse(n,MOD))%MOD;
 
       if(res < 0) res += MOD;
       printf("Case %d: %lld\n",cs++ , res);
   }
}
 