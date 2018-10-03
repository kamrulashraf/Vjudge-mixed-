#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;
#define ll long long
#define N 2000005
int dp[3][N];
int a[505] , b[505];
int main()
{
   int n , k;
   scanf("%d %d",&k,&n);
   for(int i = 1 ; i<= n ; i++){
       scanf("%d%d",&a[i],&b[i]);
   }
   dp[0][0] = 0;
   for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j<= k ; j++){
              if(j-b[i] >= 0)
                 dp[i&1][j]  = max(dp[(i-1)&1][j],dp[(i-1)&1][j-b[i]]+a[i]);
               else dp[i&1][j] = dp[(i-1)&1][j];
        }
   }
    int res = dp[n&1][k] ;
    printf("%d\n",res);

}
