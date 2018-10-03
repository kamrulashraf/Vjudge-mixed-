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

int main()
{
  int n, dp[105],a[105][105], mmax;
  cin >> n;
      int ans = -999999;
      memset(a,0,sizeof(a));
      rep(i,1,n+1)  rep(j,1,n+1){
         int temp;
         cin >> temp;
         a[i][j] += a[i-1][j] + temp;
      }

       rep(i,1,n+1)  rep(j,i,n+1){
            int sum = 0;
            mmax = -999999;
            for(int k = 1, l = 1 ; k<= n ; k++){
                dp[k] = a[j][k] - a[i-1][k];
                sum += dp[k];
               // cout << sum << ' ';
                mmax = max(sum,mmax);
                while(sum <= 0 && l <= k){
                   sum -= dp[l];
                   l++;
                }
            }
            //cout << "\n";
            ans = max(ans, mmax);
       }

       cout << ans << endl;



}
