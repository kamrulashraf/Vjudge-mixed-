#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull dp[25];
map <ull,int> hit;
void catalan(int num)
{
    ull i, j ;
    dp[0] = 1;
    dp[1] = 1;
    for(i = 2; i <= num ; i++)
        for(j = 0 ; j< i ; j++)
            dp[i] += dp[j]*dp[i-j-1];
}
int main()
{
    catalan(20);
    ull num;
    for(int i= 0 ; i<20 ; i++){
        hit[dp[i]] = i;
    }
    while(scanf("%llu", &num)==1){
        if(num==0) break;
        if(hit[num])
        cout << hit[num] << endl;
    }
}
