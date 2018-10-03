#include <bits/stdc++.h>
using namespace std;
double dp[1000001] = {0};
int main()
{
    int n , b, cse = 1 ;
    int test;
    for(int i = 1 ; i<=1000000 ; i++){
        dp[i] = dp[i-1]+log10(i);
    }
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &n , &b);
        double ans = dp[n]/ log10(b) +1 ;
        printf("Case %d: %lld\n" , cse++ , (long long) ans);
    }
}
