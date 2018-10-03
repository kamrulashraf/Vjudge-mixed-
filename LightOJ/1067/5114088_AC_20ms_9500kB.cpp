#include <bits/stdc++.h>
using namespace std;
#define N (ll) 1000003
#define ll long long
ll dp[1000000+5];
void fac(void)
{
    dp[0] = 1;
    dp[1] = 1;
    for(ll i = 2 ; i<= 1000000 ; i++)
        dp[i] = (dp[i-1]*i)%N;
}
ll bigmod(ll num , ll power)
{
  if(power == 0) return 1;
  if(power&1) return (num%N * bigmod(num, power-1)%N)%N;
  else{
    ll x = bigmod(num, power/2);
    return (x%N * x%N)%N;
  }
}
int main()
{
    ll a , b ;
    int caseno = 1;
    int test;
    fac();
    cin >> test;
    while(test--)
    {
        scanf("%lld %lld", &a , &b);
        ll save = (dp[b]%N * dp[a-b]%N)%N;
        save = bigmod(save , N-2);
        ll ans = (save%N * dp[a]%N)%N;
        printf("Case %d: %lld\n", caseno++, ans);
    }
 return 0;
}
