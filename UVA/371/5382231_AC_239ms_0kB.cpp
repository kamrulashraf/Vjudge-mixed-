// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI            2.0*acos(0.0)
#define pi            pair <int,int>
#define rep(i,x,y)      for(int i = x ; i < y ; i++)
#define fst(x)        v[x].first
#define sd(x)         v[x].second
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
map < ll , ll > hit,dp;
int main()
{
    ll a , b,save,counter, m , n;
    while(cin >> a >> b && a && b)
    {
        ll mmax = 0;
        m = a;
        n = b;
        if(a>b) swap(a,b);
        for(ll i = a ; i<= b ; i++)
        {
            counter = 0;
            ll temp = i;
            if(dp[i] == 0){
                while(1){
                    if(temp&1) temp  = 3*temp+1;
                    else temp /= 2;
                    counter++;
                    if(temp == 1) break;
                }
                dp[i] = counter;
            }
            if(dp[i]> mmax){
                mmax = dp[i];
                save = i;
            }
        }
       printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", a , b,save ,mmax);
    }
}
