#include <bits/stdc++.h>
using namespace std;
#define NN 60
int dp[NN][NN] , a[NN] , b[NN];
bool comp(int a ,int b){
   return a>b;
}
int main()
{
     int test , cs = 1 ;
     scanf("%d",&test);
     while(test--){
         int n ;
         scanf("%d", &n);
         for(int i = 0 ; i< n ; i++)
            scanf("%d",&a[i]);
        for(int i = 0 ; i< n ; i++)
            scanf("%d",&b[i]);
 
        memset(dp,0,sizeof dp);
        sort(a,a+n,comp);
        sort(b,b+n,comp);
        for(int i = 1 ; i<= n ; i++){
            for(int j = 1 ; j<= n ; j++){
               int temp = 0;
               if(a[i-1] > b[j-1]) temp = 2;
               if(a[i-1] == b[j-1]) temp = 1;
               dp[i][j] = max(max(dp[i-1][j],dp[i][j-1]),temp+dp[i-1][j-1]);
            }
        }
        int res = dp[n][n];
        printf("Case %d: %d\n",cs++ ,res);
     }
   return 0;
}