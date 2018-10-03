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

string s;
int sz = 0;
ll dp[75][75];
int conutRed(char a , char b , char c){
    return (a=='R') + (b=='R') + (c=='R');
}
ll call(int b , int e){
    if(b > e) return 1;
    if((e-b+1)%3) return 0;
    ll res = 0;

//    cout << b << ' ' << e << endl;
    ll &ret = dp[b][e];
    if(ret != -1) return ret;
    for(int i = b+1 ; i<= e ; i++){
         for(int j = i+1 ; j<= e ; j++){
             int temp = conutRed(s[i] , s[j] , s[b]);
             if(temp > 1) continue;
             ll tt  = call(b+1,i-1);
             tt *= call(i+1 , j-1);
             tt *= call(j+1 , e);
//             cout << b << ' ' <<  i << ' ' << j << ' ' <<  tt << endl;
             res += tt;
         }
    }
    ret = res;
    return  res;
}
int main()
{
    int test , cs = 1;
    sca(test);
    while(test--){
        memset(dp,-1,sizeof dp);
        char ch[1005];
        scanf("%s",ch);
        s = ch;
        sz = s.size();
        ll res = call(0,sz-1);
        printf("Case %d: %lld\n",cs++ , res);

    }
}
