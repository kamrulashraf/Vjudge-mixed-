#include <bits/stdc++.h>
using namespace std;
#define N 15
int a[N][N],target, n;
int save[N][1<<N];
int dp[1<<N];
void subset(){
      for(int i = 0 ; i < (1<<n) ; i++){
          for(int j = 0 ; j < n ; j++){
             if(i & (1<<j)){
                 for(int k = 0 ; k < n ; k++){
                      save[k][i] += a[k][j];
                 }
             }
          }
      }
}

int call(int mask){
    int temp, ret = 1e9;
    if(mask == target) return 0;
    if(dp[mask] !=-1) return dp[mask];
    for(int i = 0 ; i< n ; i++){
         if( (mask&(1<<i)) == 0 ){
            temp = mask;
            temp |= (1<<i);
            ret  = min(ret,save[i][temp]+call(temp));

         }
    }

    return  dp[mask] = ret;
}
int main()
{
      // freopen("in.txt","r" , stdin);
     int test , cs = 1;

     scanf("%d",&test);
     while(test--){
         memset(dp,-1,sizeof dp);
         memset(save,0,sizeof save);
         scanf("%d",&n);
         for(int i = 0 ; i < n ; i++){
              for(int j = 0 ; j < n ; j++){
                 scanf("%d",&a[i][j]);
              }
         }
         target  = 0;
         for(int i = 0 ; i< n ; i++){
              target |= (1<<i);
         }
         subset();
         int res = call(0);
         printf("Case %d: %d\n",cs++ , res);

     }
}
