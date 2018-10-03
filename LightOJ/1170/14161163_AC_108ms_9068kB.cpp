#include <bits/stdc++.h>
using namespace std;
#define NN 1500
#define ll long long
long long mod = 100000007;
std::vector< ll > v;
long long dp[NN];
 
void catalan(){
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < NN ; i++)
            for(int j = 0 ; j< i ; j++)
                dp[i] = (dp[i]+ (dp[j]*dp[i-j-1])%mod)%mod;
 
}
int main()
{
    map < ll,ll > hit;
    for(long long i = 2 ; i<= 100000 ; i++){
        long long num = i*i;
        while(num <= 10000000000LL){
            if(hit[num] == 0)
               v.push_back(num);
            hit[num] = 1;
            num *= i;
        }
    }
    catalan();
    dp[0] = 0;
    sort(v.begin(),v.end());
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
       long long a , b;
       scanf("%lld%lld",&a,&b);
       a--;
       int pos = upper_bound(v.begin(),v.end(),b)- v.begin();
       pos -= upper_bound(v.begin(),v.end(),a) - v.begin();
      // cout << pos << endl;
       printf("Case %d: %lld\n",cs++ , dp[pos]);
    }
}
 