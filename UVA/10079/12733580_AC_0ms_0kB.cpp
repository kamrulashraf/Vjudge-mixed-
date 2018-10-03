#include <bits/stdc++.h>
using namespace  std;

#define N 3000000
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    while(cin >> n){
         if (n < 0) break;

         if(n&1){
            ll res = (n+1)/2;
            res *= n;
            res++;
            cout << res << endl;
         }
         else{
            ll res = n/2;
            res *= (n+1);
            res++;
            cout << res << endl;
         }
    }
}
