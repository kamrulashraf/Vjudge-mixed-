#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long a[2000006];
template < class T > inline T big(T b, T p, T N){
   if(!p) return 1;
   if(!(p&1)){
    T x = big(b,p/2,N);
    return (x * x)%N;
   }
   return (b * big(b,p-1,N))%N;
}
int main()
{
  long long n , k;
  int test , cs = 1;
  cin >> test;
  a[0] = 1;
  for(int i = 1 ; i<= 2000000 ; i++){
     a[i] = (a[i-1]*i)%mod;
  }
  while(test--){
     scanf("%lld %lld", &n , &k);
     long long t1 = a[n+k-1];
     long long t2 = (a[n]*a[k-1])%mod;
     t2 = big(t2,mod-2,mod);
     t1 = (t1*t2)%mod;
     printf("Case %d: %lld\n",cs++ , t1);
 
  }
 
 
}