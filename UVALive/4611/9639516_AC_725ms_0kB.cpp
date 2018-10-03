#include <bits/stdc++.h>
using namespace std;
#define N 5000005
long long a[N], cul[N], dp[N];
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
         memset(dp,0,sizeof dp);
         long long d , n;
         scanf("%lld%lld",&d,&n);
         for(int i = 1 ; i<= n ; i++){
             scanf("%lld",&a[i]);
         }

         for(int i = 1 ; i <= n ; i++){
              cul[i] = (cul[i-1] + a[i])%d;
         }
         dp[0] = 1;
         long long res = 0;
         for(int i = 1 ; i<= n ; i++){
             res += dp[cul[i]];
             dp[cul[i]]++;
         }
         printf("%lld\n",res);
    }
    return 0;
}
