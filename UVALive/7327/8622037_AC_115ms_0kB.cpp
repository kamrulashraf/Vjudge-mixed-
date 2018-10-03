#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;

template < class T> T big(T b , T p , T mod){
    if(p == 0) return 1;
    if(!(p&1)){
        T x = big(b,p/2,mod);
        return (x*x)%mod;
    }
    else return (b*big(b,p-1,mod))%mod;
}

int main()
{
   int test ,cs = 1;
   long long a , b;
   while(scanf("%lld%lld",&a,&b)==2){
      string s;
      cin >> s;
      long long res = 0, counter = 0;
      for(int i = 0 ; i< s.size()-1 ; i++){
          res  = (res*10+s[i]-'0');
          res %= b;
          if(res == 0) counter++;
      }
      res = (res*10+s[s.size()-1]-48);
      if(res%b==0){
        res = big(2LL,counter,mod);
      }
      else res = 0;
      if(res < 0) res += mod;
      printf("%lld\n",res);
   }
}