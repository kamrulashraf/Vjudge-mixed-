#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long mod = 1000000007;
template < class T> T big(T b , T p , T mod){
  if(p == 0) return 1;
  if( p& 1){
    return (b*big(b,p-1,mod))%mod;
  }
  else {
     T x = big(b,p/2,mod);
     return (x*x)%mod;
  }

}
int main()
{
   long long  n  , test , cs = 1;
   long long b = big((ll)3,mod-2,mod);
   cin >> test;
   while(test--){
     scanf("%lld", &n);
     long long temp;
     if(n&1)
        temp = ((n+1)/2*n)%mod;
     else temp = (n/2*(n+1))%mod;
     long long temp1 =  (temp%mod*(2*n+1)%mod)%mod;
     temp1 = (temp1*b)%mod;
     long long ans = (temp+temp1)%mod;
     printf("Case %lld: %lld\n", cs++ , ans);
   }

 return 0;
}
