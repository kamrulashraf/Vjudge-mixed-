#include <bits/stdc++.h>
using namespace std;
#define N 105
int val[N];
double dp[10005];
double prob[N];
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
         double p ;
         int n;
         int sum = 0;
         scanf("%lf %d",&p,&n);
         for(int i = 0 ; i< n ; i++){
            scanf("%d %lf",&val[i],&prob[i]);
            sum += val[i];
         }
         for(int i = 1 ; i<= sum ; i++)
            dp[i] = 1;
          
         for(int i = 0 ; i< n ; i++){
             for(int j = sum ; j >= 0; j--){
                 int temp = j-val[i];
                 if(temp >= 0){
                    dp[j] = min(dp[j],dp[temp]+(1-dp[temp])*prob[i]);
                 }
             }

             // for (int j = 0; j <= sum; ++j)
             // {
             //      cout << dp[j] << ' ';  
             // } cout << endl;
         }
         int res = 0;
         for(int i = 0 ; i<= sum ; i++){
             if(dp[i] <= p){
                res = i;
             }
         }
         printf("Case %d: %d\n",cs++ , res);
    }
}
