#include <bits/stdc++.h>
using namespace std;
#define NN 16
long long num, n;
long long a[NN];
#define ll long long

ll gcd(ll a, ll b){
  while(a>0 && b>0) a>b? a%=b:b%=a;
  return a+b;
}

ll lcm(ll a, ll b){
  return a/gcd(a,b)*b;
}
ll call(){
    long long res = 0;
    for(int i = 0 ; i< (1<<n) ; i++){
          long long l = 1, counter = 0, flag = 0;
          for(int j = 0 ; j< n ; j++){
              if(i & (1<<j)){
                 l = lcm(l,a[j]);
                 counter++;
                 if(l> num){
                    flag = 1;
                    break;
                 }
              }
          }
          if(counter && flag == 0){
              if(counter&1) res += num/l;
              else res -= num/l;
          }
    }
    return res;
}
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
          scanf("%lld%lld",&num,&n);
          for(int i = 0 ; i< n ; i++){
             scanf("%lld",&a[i]);
          }
          long long res = call();
          printf("Case %d: %lld\n",cs++ ,num-res);
    }
    return 0;
}
