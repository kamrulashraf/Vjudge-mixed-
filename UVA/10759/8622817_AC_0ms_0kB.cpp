
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define NN 150
#define ull unsigned long long

ull dp[25][151];
ull p[25];
int target;
        int n , m;

ull call(int indx , int sum){
     if(indx >= n){
        if(sum >= target){
           return 1;
        }
        return 0;
     }
     if(dp[indx][sum] != -1) return dp[indx][sum];
     ull res = 0;
     for(int i = 1 ; i<= 6 ; i++){
         int temp = sum+i;
         res += call(indx+1,temp);
     }
     return dp[indx][sum] = res;
}
int main()
{
     // freopen("inputf.in","r", stdin);
    int test , cs = 1;
    p[0] = 1;
    for(int i = 1 ; i<= 24 ; i++)
        p[i] = p[i-1]*6;
    while(scanf("%d%d",&n,&m)==2){
        if(m==0 && n==0) break;
        memset(dp,-1,sizeof dp);
        target = m;
        ull res = call(0,0);
        // cout << res << endl;
        ull y = p[n];
        ull g = __gcd(res,y);
        res /= g;
        y /= g;
        if(res == 0){
          printf("0\n");
        }
        else if(y==1) printf("%llu\n",res);
        else printf("%llu/%llu\n",res,y);
    }
}
