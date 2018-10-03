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
    long long n;
    while(cin >> n){
        long long res;
        if(n < 0) break;
        if(n&1){
           res = (n+1)/2;
           res *= n;
        }
        else{
           res = n/2;
           res *= (n+1);
        }
        cout << res +1 << endl;
    }
}