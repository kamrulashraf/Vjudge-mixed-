#include <bits/stdc++.h>
using namespace std;

long long d[35];
long long ncr[35][35];
void dearrangement(){
    d[0] = 1;
    d[1] = 0;
    d[2] = 1;

    for(int i = 3 ; i<= 30 ; i++){
       d[i] = (i-1)*(d[i-2]+d[i-1]);
    }
}


long long call(int n , int r){
    if(n==r) return 1;
    if(r == 0) return 1;
    if(ncr[n][r] != -1) return ncr[n][r];
    return ncr[n][r] = call(n-1,r-1)+call(n-1,r);
}
int main()
{
   dearrangement();
   memset(ncr,-1,sizeof ncr);
   long long n , m;
   while(scanf("%lld%lld",&n,&m)==2){
        long long res = 0;
        for(int i = 0 ; i<= m ; i++){
           res += call(n,i)*d[n-i];
        }
        printf("%lld\n",res);
   }

   return 0;
}
