#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define ll long long
using namespace std;
long long MOD = 1e9+7;
long long fac[1000007];

template < class T > inline T big(T b, T p, T N){
    if(!p) return 1;
    if(!(p&1)){
            T x = big(b,p/2,N);
            return (x * x)%N;
       }
    return (b * big(b,p-1,N))%N;
}

void factorial(){
	 fac[00]=1;
	 for(int i=1;i<=1000000;i++){
	 	  fac[i]=(fac[i-1]*i)%MOD;
	 }

	 return ;
}

long long modInverse(ll n, ll mod){
      return (big((ll) n,mod-2, mod))%mod;
}


long long ncr(long long n , long long r){
    long long ret =  fac[n];
    ret = (ret*modInverse(fac[r],MOD))%MOD;
    ret = (ret*modInverse(fac[n-r],MOD))%MOD;
    return ret%MOD;
}
int main()
{
	// freopen("inputf.in", "r" , stdin);
	int test , cs = 1, n ;
	ll tt;
	scanf("%d",&test);
	factorial();
	while(test--){
		 scanf("%d",&n);
		 long long sum = 0, res = 1;
		 for(int i = 0 ; i< n ; i++){
		 	 scanf("%lld",&tt);
		 	 sum += tt;
		 	 res = (res*ncr(sum-1,tt-1))%MOD;
		 	 // cout << sum - 1 << ' ' << tt-1 << ' ' << res << endl;
		 }
		 if(res < 0) res += MOD;
		 printf("Case %d: %lld\n",cs++ ,res);
	}
}
// break the problem in smaller problem
//  j1,j1,j1,j2,j2,j2 ,j3, j3 , j3
// last er number ta same rekhe ager gulor moddhe koto vabe sajaite pari..
// j1,j1,j1,j2,j2,j2
// ..............,j2 ta change korbo na baki  gula change korbo
// assume that i get m valid way for j1,j1,j1,j2,j2,j2
// j1,j1,j1,j2,j2,j2,j3,,j3,j3
// .........................j3 last position e fixed
// m valid sequence gula paisi tader order change na kore ..
// oder moddhe j3,j3 koto vabe insert korte parbo  ncr( totoal cur unit -1,cur unit-2);
//m*ncr( totoal cur unit -1,cur unit-2)