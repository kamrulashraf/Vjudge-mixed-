
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define NN 100005
int  a[NN];
int n;
bool vis[NN];
double dp[NN];
double call(int in){
    if(in >= n) return 0.0;
    int len = n-in;
    double res = 0;
    if(vis[in]) return dp[in];
    if(len >= 6){
      for(int i = 0 ; i< 6 ; i++){
          res += (a[i+in]+call(in+i+1))/6.0;
      }
    }
    else{
      for(int i=0;i< len ; i++){
         double temp;
         temp = (a[in+i]+call(in+1+i))/6.0;
         res += temp;
         // cout << in << ' ' << len << ' ' << a[in+i] << ' ' <<  call(in+i+1) << ' ' << temp << ' ' << res <<   endl;
      }
      res = (res*6.0)/len;
    }
    vis[in] = true;
    return dp[in] = res;
}
int main()
{
   int test ,cs = 1;
   scanf("%d",&test);
   while(test--){
        scanf("%d",&n);
        for(int i = 0 ; i< n ; i++){
            scanf("%d",&a[i]);
        }
        memset(vis,0,sizeof vis);
        double res = call(1);
        res += a[0];
        printf("Case %d: %.9lf\n",cs++ ,res);
 
 
 
   }
}
 