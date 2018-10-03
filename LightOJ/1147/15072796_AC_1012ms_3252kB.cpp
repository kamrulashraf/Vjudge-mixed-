#include <bits/stdc++.h>
using namespace  std;

#define N 200005
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
int a[102] ;
ll dp[N];
int main()
{
    int test , cs = 1;
    sca(test);
    while(test--){
         int n;
         sca(n);
         int sum = 0;
         F(i,n){
            sca(a[i]);
            sum += a[i];
         }

         int half = sum/ 2;
         memset(dp, 0, sizeof(dp));
         dp[0] = 1;
         for(int j = 0 ; j< n ; j++){
             for(int i = sum ;  i>= 0 ; i--){
                int temp = i+a[j];
                if(dp[i]) dp[temp] |= dp[i]<<1;
             }
         }
         int res = inf;


         ll hh = n/2;
         ll biton = 0;
         int mmin = inf;
         biton |= (1LL<<hh);
         // if hh-th bit is 1 means h-th element taken
//         for(int i = 0 ; i<= sum ; i++){
//            cout << i << ' ' << (dp[i]) << endl;
//         }
         for(int i = sum ; i>= 0 ; i--){
              if(dp[i] & biton){
                 int a = sum-i;
//                 cout << i << ' ' << a << ' ' << abs(i-a) << endl;
                 if(abs(i-a) < mmin){
                    res = i;
                    mmin = abs(a-i);
                 }
              }
         }

//         F(i, half) cout << i << ' ' << dp[i] << endl;
         printf("Case %d: %d %d\n",cs++ ,min(res,sum-res) , max(res,sum-res));

    }
}
