#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y)  for(int i=x;i<y;i++)
#define ull    unsigned long long
#define N 1001
long long arr[105];
long long brr[105];
int main(){
    long long n;
    while(scanf("%lld",&n)==1){
        int k;
        scanf("%d",&k);
        for(int i = 0 ; i< k ; i++){
           scanf("%lld",&arr[i]);
           brr[i] = 1;
        }

        long long ret= 1, ret1 = 1;
        for(long long i = 1 ; i<= n ; i++){
             ret *= i;
             for(int j = 0 ; j< k ; j++){
                if(arr[j] >= brr[j]){
                    ret1 *= brr[j];
                    brr[j]++;
                    long long g = __gcd(ret,ret1);
                    ret /= g;
                    ret1 /= g;
                }
             }
        }

        long long res = ret/ret1;
        printf("%lld\n",res);
    }
    return 0;

}
