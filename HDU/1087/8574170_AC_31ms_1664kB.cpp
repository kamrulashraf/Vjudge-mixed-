#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;
#define ll long long
#define N 10005
int n;
int a[N];
ll dp[N];
// long long call(int indx , int prev){
//     if(indx >= n) return 0;
// //    cout << indx << ' ' << prev << endl;
//     long long p1 = 0, p2 = 0;
//     bool flag = 0;
//     if(a[indx]>prev) flag = 1;
//     else flag = 0;
//     if(dp[indx][flag] != -1) return dp[indx][flag];
//     if(a[indx] > prev)
//         p1 = a[indx]+call(indx+1,a[indx]);
//     p2 = call(indx+1,prev);

//     return dp[indx][flag] = max(p1,p2);
// }
int main()
{
    while(scanf("%d",&n) && n){
          memset(dp,0,sizeof dp);
          for(int i = 1 ; i<= n ; i++){
              scanf("%d",&a[i]);
          }
          long long res = 0;
          // cout << "bal" << endl;
          for(int i = 1 ; i<= n ; i++){
              for(int j=0;j<i;j++){
                  if(a[j] < a[i]){
                      dp[i] = max(dp[i],dp[j]+a[i]);
                      res = max(res , dp[i]);
                  }
              }
          }
          cout << res << endl;
    }
}
