#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;
#define ll long long
#define N 5005
string s ;
int k, sz;

int dp[1<<11][10005];
int fac[12];
long long call(int indx , int mask, int num){
    long long res = 0;
    if(num<0) num += k;
    if(indx >= sz){
       if(num%k==0){
//              cout << num  << ' ' << s << endl;
         return 1;
       }
       return 0;
    }
    // cout << indx << '#' << num << endl;
    if(dp[mask][num] != -1) return dp[mask][num];
    for(int i = 0 ; i< sz ; i++){
        if(mask &(1<<i)) continue;
        int temp = mask;
        temp |= (1<<i);
        int send = num*10+s[i]-48;
        // cout << indx << '*' << send <<  endl;
        send %= k;
        res += call(indx+1,temp,send);
    }
    return dp[mask][num] = res;
}

void factorial(){
   fac[0] = 1;
   for(int i = 1 ; i< 11 ; i++){
      fac[i] = fac[i-1]*i;
   }
}
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    factorial();
    while(test--){
        int mark[15] = {0};
        memset(dp,-1,sizeof dp);
        cin >> s;
        cin >> k;
        sz = s.size();
        long long res = call(0,0,0);
        for(int i = 0 ; i<sz ; i++){
            mark[s[i]-48]++;
        }
        for(int i = 0;i<10 ; i++){
            res /= fac[mark[i]];
        }
        printf("%lld\n",res);


    }
}
