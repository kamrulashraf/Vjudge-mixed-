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
#define N 1000005
#define ll long long
ll block = 550;
ll a[N];
std::vector< ll > v[550];


int query(ll l , ll r ,  ll x){
     ll res = 0 , i;
     for( i = l ; i<= r && i%block ; i++)
         res += (a[i] < x);
     for(  ; i+block <= r ; i+=block){
         int t = i/block;
         int tt = lower_bound(v[t].begin(),v[t].end(),x)-v[t].begin();
         res += tt;
     }
     for( ; i <= r ; i++)
         res += (a[i]<x);
     return res;

}
void update(int indx , ll val){
    int blockNo = indx/block;
    int pos = lower_bound(v[blockNo].begin(),v[blockNo].end(),a[indx])-v[blockNo].begin();
    a[indx] = val;
    v[blockNo][pos]=val;
    sort(v[blockNo].begin(),v[blockNo].end());
}
int main()
{
    // freopen("inputf.in","r",stdin);
    ll n , q ,u;
    scanf("%lld%lld%lld",&n , &q, &u);
    for(int i = 0 ; i< n ; i++){
       scanf("%lld",&a[i]);
       v[i/block].push_back(a[i]);
    }
    for(int i = 0 ; i< block ; i++){
       sort(v[i].begin() , v[i].end());
    }
    ll l , r , v, p;
    while(q--){
         scanf("%lld%lld%lld%lld",&l,&r,&v,&p);
         int k = query(l-1,r-1,v);
         long long val = (u*k)/(r-l+1);
         update(p-1,val);
    }
    for(int i=0;i<n;i++)
      printf("%lld\n",a[i]);
}
