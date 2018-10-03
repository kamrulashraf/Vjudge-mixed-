#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
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
  long long a,b;
  while(cin >> a >> b && a && b){
     long long lob = (big(a,b+1,mod)-1)%mod;
     long long hor = big(a-1,mod-2,mod);
     long long ans = (lob*hor)%mod;
     ans = ans%mod;
     printf("%lld\n",ans-1);

  }

}
