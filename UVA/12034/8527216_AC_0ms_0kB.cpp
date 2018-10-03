#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y)  for(int i=x;i<y;i++)
#define ull    unsigned long long
#define N 1001
int target;
int ncr[N][N];
int dp[N];
int mod = 10056;
void NCR(){
    for(int i=0;i<1001 ; i++){
         for(int j=0;j<=i;j++){
             if(i==j || j==0) ncr[i][j]=1;
             else
             ncr[i][j] = (ncr[i-1][j]+ncr[i-1][j-1])%mod;
         }
    }
}



int call(int n){
    if(n<=1) return 1;
    if(dp[n]!=-1) return dp[n];

    int ret = 0;
    for(int i = 1 ; i<=n;i++){
        ret = (ret+ncr[n][i]*call(n-i))%mod;
    }
    return dp[n] = ret;
}

int main(){

    NCR();
    memset(dp,-1,sizeof dp);
    int test, cs = 1;
    scanf("%d",&test);
    while(test--){
        int n;

        scanf("%d",&n);
        int res = call(n);
        if(res<0) res += mod;
        printf("Case %d: %d\n",cs++ , res );
    }
    return 0;

}
