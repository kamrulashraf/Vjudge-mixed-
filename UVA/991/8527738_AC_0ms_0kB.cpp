#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y)  for(int i=x;i<y;i++)
#define ull    unsigned long long
#define N 101
long long dp[N];
void catalan(int  num){

        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= num ; i++)
            for(int j = 0 ; j< i ; j++)
                dp[i] += dp[j]*dp[i-j-1];
}


int main(){
    int n;
    catalan(11);
    int counter = 0;
    while(scanf("%d",&n)==1){
        if(counter) printf("\n");
        printf("%lld\n",dp[n]);
        counter++;
    }
    return 0;

}
