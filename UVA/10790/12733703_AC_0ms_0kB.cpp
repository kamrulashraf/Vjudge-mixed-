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
    int n , m;

    int cs = 1;
    while(scaa(n,m)){
        if(n == 0 && m == 0) break;

        ll res = 0;
        for(int i = 0 ; i< m ; i++){
             res += m-(i+1);
        }

        n = ((n)*(n-1))/2;

        res *=n;
        printf("Case %d: %lld\n",cs++ , res);
    }
}