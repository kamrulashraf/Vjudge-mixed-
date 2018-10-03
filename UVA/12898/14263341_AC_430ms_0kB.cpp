#include <bits/stdc++.h>
using namespace  std;

#define N 100005
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
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
string l , u;
int dp[65][2] , vis[65][2][2];

string convString(ll var){
	string ret;
	for(ll i = 62 ; i >= 0 ; i--){
		if(var & (1LL<<i)) ret += '1';
		else ret += '0';
	}
	return ret;
}
int call(int indx , int high , int low){
       if(indx == 63) return 1;
       if(vis[indx][high][low] != -1) return vis[indx][high][low];
       int bl = l[indx]-48;
       int bu = u[indx]-48;
       for(int i = 0 ; i< 2 ; i++){
          if(low && i < bl) continue;
          if(high && i > bu) continue;
          dp[indx][i] |= call(indx+1, low & (bl == i) , high & (bu==i));
       }
       return vis[indx][high][low]=dp[indx][0]|dp[indx][1];
}
int main()
{
	int test, cs= 1 ;
	sca(test);
	while(test--){
		ll a , b;
		memset(vis,-1,sizeof vis);
		memset(dp,0,sizeof dp);
		scanf("%lld %lld",&a,&b);
		l = convString(a);
		u = convString(b);


        call(0,1,1);
//        for(int i = 0 ; i< 64; i++){
//           cout << i << ' ' <<  dp[i][0] << ' ' << dp[i][1] << endl;
//        }
        ll res1 = 0 , res2 = 0;
        for(int i = 62 ; i >= 0 ; i--){
            int temp = 62-i;
            if(dp[i][1])
               res1 |= (1LL<<temp);
            if(dp[i][0] == 0)
             res2 |= (1LL<<temp);
        }
//        cout << res1 << ' ' << res2 <<endl;
        printf("Case %d: %lld %lld\n",cs++ ,res1 , res2);
	}
}