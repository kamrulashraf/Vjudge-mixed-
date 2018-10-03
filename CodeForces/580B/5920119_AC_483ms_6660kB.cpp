#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int main()
{
    ll m, mmax = 0 , n,fs[N],sd[N] ,a ,b , sum[N];
    vector < pair<ll,ll> > v;
    cin >> m >> n;
    for(int i = 0 ; i< m ; i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin() , v.end());
    for(int i = 0 ; i< m ; i++)
       {
           sum[i] = sum[i-1]+v[i].second;
       //    cout << v[i].first << ' ' << v[i].second << ' ' << sum[i] << endl;
       }
    for(int i=  0 ; i< m ; i++) fs[i] = v[i].first;
    for(int i = 0 ; i< m ; i++){
    int pos =  lower_bound(fs , fs+m ,fs[i]+n) - fs-1;
    ll ans = sum[pos] - sum[i-1];
    mmax = max(mmax,ans);
    }
    cout << mmax << endl;


}