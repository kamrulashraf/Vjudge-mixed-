#include <bits/stdc++.h>
using namespace std;
long long fac[1000005];
long long mod = 1e9+7;
#define ll long long
std::vector< int > v[1000005];

template < class T> T big(T b , T p , T mod){
    if(p == 0) return 1;
    if(!(p&1)){
        T x = big(b,p/2,mod);
        return (x*x)%mod;
    }
    else return (b*big(b,p-1,mod))%mod;
}

void factorial(){

     fac[0] = 1;
     for(int i =1 ; i<= 1000000 ; i++){
         fac[i] =  (fac[i-1]*i)%mod;
         if(fac[i] < 0) fac[i] += mod;
     }

     for(int i = 1; i<= 1000000 ; i++){
         for(int j = i ; j<= 1000000 ; j+= i)
            v[j].push_back(i);
     }
}



int main()
{
//    freopen("in.txt","r",stdin);
    int test , cs=  1;
    scanf("%d",&test);
    factorial();
    while(test--){
        int n;
        scanf("%d",&n);
        int sz = v[n].size();
        ll res = 0;
        for(int i = 0 ; i< sz ; i++){
            ll temp = fac[n];
            ll tt = n/v[n][i];
            ll temp1 = fac[v[n][i]];
            temp1 = big(temp1,mod-2,mod);
            temp1 = big(temp1,tt,mod);
            ll temp2 = big(fac[tt],mod-2,mod);
            res = (res + ((temp*temp1)%mod)*temp2)%mod;
            if(res < 0) res += mod;
        }
        if(res < 0) res += mod;
        printf("Case %d: %lld\n",cs++ ,res);
    }
}
