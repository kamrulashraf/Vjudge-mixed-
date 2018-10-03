#include <bits/stdc++.h>
using namespace  std;


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
ll M = 2000000011;
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
   int test , cs = 1;
   sca(test);
   while(test--){
        ll temp = 1;
        ll n;
        scanf("%lld",&n);
        if(n > 1)
        temp = big(n,n-2LL,M);
        temp %= M;
        temp = (temp+M)%M;
        if(n == 1){
           printf("Case #%d: %lld\n",cs++ , 1LL);
        }
        else{
          printf("Case #%d: %lld\n",cs++ , temp);
        }
   }
}
