#include <bits/stdc++.h>
using namespace std;
#define NN 10000010
int a[NN];
void mobius(int n){
    for(int i = 2 ; i<= n ; i++){
         if(a[i]==0){
            long long temp = i*i;
            for(int j = i ; j<= n ; j+=i){
                if(a[j] == -1) continue;
                if(j%temp == 0) a[j] = -1;
                else a[j]++;
            }
         }
    }
    a[1] = 0;
    for(int i = 2 ; i<= n ; i++){
          if(a[i] == -1) a[i] = 0;
          else if(a[i]&1) a[i] = 1;
          else a[i] = -1;
    }
}
int main()
{
    int test , cs = 1;
    mobius(10000007);
    scanf("%d",&test);
    while(test--){
        long long n;
        scanf("%lld",&n);
        long long temp = sqrt(n);
        long long res = 0;
        for(long long i = 2 ; i<= temp ; i++){
            res += a[i]*(n/(i*i));
        }
        printf("%lld\n",n-res);

    }
    return 0;
}
