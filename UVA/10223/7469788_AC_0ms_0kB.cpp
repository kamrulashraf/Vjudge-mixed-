#include <bits/stdc++.h>
using namespace std;
         // make dp global variable // this is precalculation
        unsigned long long dp[100] ;
    template <class T> void catalan(T num){
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= num ; i++)
            for(int j = 0 ; j< i ; j++)
                dp[i] += dp[j]*dp[i-j-1];
    }

int main()
{
    catalan(23);
    long long n;
    while(cin >> n){
         int pos = lower_bound(dp+1,dp+23,n)-dp;
         cout << pos << endl;
    }
}