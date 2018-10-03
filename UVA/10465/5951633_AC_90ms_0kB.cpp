#include <bits/stdc++.h>
#define rep(i,x,y)  for(int i = x ; i<y ; i++)
#define mod  1000000
using namespace std;
int dp[10005], a[2];
int main()
{
  //freopen("a.txt","w",stdout);
  int m , n , t;
  while(cin >> a[0] >> a[1] >> t){
      memset(dp,0,sizeof(dp));
      dp[0] = 1;
      for(int i = 0 ; i<= t ; i++){
         if(dp[i])
          for(int j = 0 ; j< 2 ; j++){
            if(i+a[j] <= t)
             if(dp[i]+1 >= dp[i+a[j]]){
                 dp[i+a[j]] = dp[i]+1;
             }
          }
      }
      int ans = dp[t]-1;
      if(ans <= 0){
            bool flag = 0;
            for(int j = t ; j>= 1 ; j--){
               if(dp[j]){
                  flag = 1;
                  cout << dp[j]-1 << ' ' << t -j << endl;
                  break;
               }

            }
            if(flag == 0) cout << 0 << ' ' << t << endl;
      }
      else cout << ans << endl;
  }

}
