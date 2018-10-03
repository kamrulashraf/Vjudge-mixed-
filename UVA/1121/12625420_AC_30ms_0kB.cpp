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
ll a[N] , cul[N];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n  , s;
    while(cin >> n >> s){
        memset(cul,0,sizeof cul);
    	for(int i = 0 ; i< n ; i++){
    		 cin >> a[i+1];
    	}


        for(int i = 1 ; i<= n ; i++){
        	 cul[i] = cul[i-1] + a[i];
        }
        ll mmin = inf;
        for(ll i = 0 ; i < n ; i++){
        	 ll temp = cul[i] + s;

        	 ll pos = lower_bound(cul+i,cul+n+1,temp) - cul;
        	 // cout << temp << ' ' << i << ' ' <<  pos << endl;
        	 if(cul[pos]-cul[i] >= s)
        	 mmin = min(mmin,pos-i);
        }
        if(mmin == inf) cout << 0 << endl;
        else
        cout << mmin << endl;
    }
}
