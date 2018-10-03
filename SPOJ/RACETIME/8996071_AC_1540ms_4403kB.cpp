#include <stdio.h>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
#define N 200015
#define ll long long
ll a[N];
ll block = 340;
std::vector< ll > v[400];

ll query(ll l , ll r ,ll x){
    ll res = 0, i;
    for( i = l ; i <= r && i%block ; i++)
          if(a[i] <= x) res ++;
    for( ; i+block < r ; i+= block){
    	int t = i/block;
        ll tt =upper_bound(v[t].begin(),v[t].end(),x)-v[t].begin();
        // assert(tt < v[i].size());
        res += tt;
    }

    for( ;i <= r ; i++){
        if(a[i] <= x) res++;
    }
    return res;
}

void update(ll indx , ll x){
    ll t = indx/block;
    ll pos = lower_bound(v[t].begin(),v[t].end(),a[indx])-v[t].begin();
    v[t][pos] = x;
    a[indx] = x;
    sort(v[t].begin(),v[t].end());
}
int main()
{
    // freopen("inputf.in","r", stdin);
    ll n , q;
    scanf("%lld %lld",&n,&q);
    for(int i = 0 ; i< n ; i++){
       scanf("%lld",&a[i]);
       v[i/block].push_back(a[i]);
    }
    for(int i = 0 ; i< block ; i++){
        sort(v[i].begin(),v[i].end());
    }

    ll l , r  , x;
    char ch;
    for(int i = 0 ; i< q ; i++){
        getchar();
        scanf(" %c",&ch);
        if(ch == 'C'){
             scanf("%lld%lld%lld",&l,&r,&x);
             l-- , r--;
             ll res = query(l,r,x);
             printf("%lld\n",res);
        }
        else{
            scanf("%lld%lld",&l,&x);
            l--;
            update(l,x);

        }

    }
}
