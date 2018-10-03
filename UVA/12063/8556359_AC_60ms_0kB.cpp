#include <bits/stdc++.h>
using namespace std;
#define N 105
#define inf 1e9
long long dp[65][N][132];
int n , k;
long long call(int indx , int num, int diff){
     if(num <0) num += k;
     if(indx == n){
        if(num%k==0 && diff==65) return 1;
        return 0;
     }
     // cout << indx << ' ' << num << endl;
     if(dp[indx][num][diff]  != -1) return dp[indx][num][diff];
     int temp = (num*2)%k;
     int temp1 = (num*2+1)%k;
     long long res = 0;
     if(indx)
     res += call(indx+1,temp,diff+1);
     res += call(indx+1,temp1,diff-1);
     return dp[indx][num][diff] =  res;
}

int main()
{
   // freopen("input.txt","r",stdin);
   int test , cs = 1;
   scanf("%d",&test);
   while(test--){
       memset(dp,-1,sizeof dp);
       scanf("%d%d",&n,&k);
       if(k==0){
          printf("Case %d: %d\n",cs++ , 0);
       }
       else{
         long long res = call(0,0,65);
         printf("Case %d: %lld\n",cs++ ,res);
      }
   }
}
