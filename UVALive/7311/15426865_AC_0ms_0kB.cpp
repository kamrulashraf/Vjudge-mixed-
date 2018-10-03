#include <bits/stdc++.h>
using namespace  std;

#define N 400005
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
#define write() freopen("out.txt", "w" , stdout)
#define read() freopen("in.txt" , "r", stdin)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

int main()
{
    int test  , cs = 1;
    sca(test);
    ll x = 0 , y = 0 , z = 0;
    while(test--){

        ll a ,b , c;
        scanf("%lld %lld %lld",&a,&b,&c);
        x += a;
        y += b;
        z += c;

        ll mmin = inf;
        mmin = min(x,y);
        mmin = min(mmin,z);
        if(mmin < 30){
            printf("NO\n");
        }
        else{
            printf("%lld\n",mmin);
            x -= mmin;
            y -= mmin;
            z -= mmin;

        }
    }
}
