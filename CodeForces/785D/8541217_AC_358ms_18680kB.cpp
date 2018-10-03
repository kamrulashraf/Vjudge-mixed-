#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
char s[N];
int pre[N] , suf[N];
long long fac[N];
long long mod = 1e9+7;
template < class T> T big(T b , T p , T mod){
    if(p == 0) return 1;
    if(!(p&1)){
        T x = big(b,p/2,mod);
        return (x*x)%mod;
    }
    else return (b*big(b,p-1,mod))%mod;
}


long long modInverse(ll n, ll mod){
  long long ret = big((ll) n,mod-2LL, mod);
  return (ret+mod)%mod;
}


void factor(){
   fac[0] = 1;
   for(long long i = 1 ; i< 400005 ; i++){
      fac[i] = (fac[i-1]*i)%mod;
      if(fac[i] < 0) fac[i] += mod;
   }
}

long long ncr(long long n , long long r){
    long long ret = fac[n];
    long long temp = modInverse(fac[r],mod);
    long long temp1 = modInverse(fac[n-r],mod);
    ret = (ret*temp)%mod;
    ret = (ret*temp1)%mod;
    
    if(ret < 0) ret += mod;
    return ret;
}
int main()
{
   // freopen("input.txt","r",stdin);
   factor();
   scanf("%s",&s[1]);
   int len = 0;
   for(int i = 1 ; s[i] ; i++){
      len++;
      pre[i] += pre[i-1]+(s[i]=='(');
   }
   for(int i = len ; i>= 1 ; i--){
      suf[i] = suf[i+1]+(s[i]==')');
   }
    
   long long res = 0;

   for(int i = 1 ; i<= len; i++){
        if(s[i] == '('){
             long long x = pre[i];
             long long y = suf[i];
             long long temp = ncr(x+y-1,x);
             // cout << i << ' ' << x << ' ' << y << ' ' << temp <<  endl;
             if(temp < 0) temp += mod;
             res = (res+temp)%mod;
             if(res < 0) res += mod;
        }
   }
   printf("%lld\n",res);
}