#include <bits/stdc++.h>
using namespace std;
#define N 105
#define inf 1e9
int n , k;

int a[19][19];
int dp[1<<19];
int call(int indx , int mask){
     int ret = 0;
     if(indx>=n) return 0;
     if(dp[mask]!=-1) return dp[mask];
     for(int i =  0 ; i< n ; i++){
         if((mask&(1<<i))) continue;
         int temp = mask;
         temp |= (1<<i);
         ret = max(ret,a[indx][i]+call(indx+1,temp));

     }
     return dp[mask] = ret;
}
int main()
{

    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);
        for(int i = 0 ; i< n ; i++){
            for(int j=0; j< n ; j++){
                scanf("%d",&a[i][j]);
            }
        }

        int res = call(0,0);
        printf("Case %d: %d\n",cs++ ,res);
    }
}
