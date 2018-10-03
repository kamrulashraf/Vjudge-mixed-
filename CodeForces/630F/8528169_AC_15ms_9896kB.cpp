#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y)  for(int i=x;i<y;i++)
#define ull    unsigned long long
#define N 1001
int target;
long long ncr[N][N];
long long dp[N];
int mod = 10056;
long long call(long long n,long long r){
    long long temp = max(n-r,r);
    long long ret =1, ret1 = 1 ;
    for(long long i = temp+1, j = 1 ; i<= n ;i++,j++){
        ret *= i;
        ret1 *= j;
        long long g = __gcd(ret,ret1);
        ret /= g;
        ret1 /=g;
        // cout << ret << ' ' << ret1 << ' ' << g <<  endl;
    }

    return ret/ret1;
}


int main(){
    int n;
    scanf("%d",&n);
    long long res = 0;
    for(int i = 5 ; i<= 7 ; i++){
       res += call(n,i);
       // cout << res << endl;
    }
    printf("%lld\n",res);
    return 0;

}
