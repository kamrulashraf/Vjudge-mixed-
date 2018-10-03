#include <bits/stdc++.h>
using namespace std;
#define NN 55
int n , make;
int a[NN], c[NN];
long long mod = 100000007;
long long dp[NN][1001];
 
long long call(int i , int send){
//      cout << i << ' ' << send << endl;
      if(send == make) return 1;
      if(send  > make || i >= n)
         return 0;
      long long res = 0;
      if(dp[i][send] !=-1) return dp[i][send];
      for(int j = 0 ; j<= c[i] ; j++){
         int temp =  j*a[i];
         res += call(i+1,temp+send);
         res %= mod;
      }
      return dp[i][send] = res;
}
int main()
{
     int test , cs = 1;
     scanf("%d",&test);
     while(test--){
         scanf("%d%d",&n, &make);
         for(int i = 0 ; i< n ; i++)
             scanf("%d",&a[i]);
         for(int i = 0 ; i< n ; i++)
            scanf("%d",&c[i]);
 
         memset(dp,-1,sizeof dp);
         long long  res = call(0,0);
         res %= mod;
         printf("Case %d: %lld\n", cs++ , res);
 
     }
}
 