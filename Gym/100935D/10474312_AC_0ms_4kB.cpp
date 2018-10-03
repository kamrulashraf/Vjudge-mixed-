#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll big(ll b , ll p , ll mod){
   if( p == 0) return 1LL;
   if(p&1){
       return (b*big(b,p-1,mod))%mod;
   }
   else{
       ll x= big(b,p/2,mod);
       return (x*x)%mod;
   }
}
int main()
{

    int test , cs = 1;
    while(1){
          long long n , k , a;
          int t;
          scanf("%lld %lld %lld",&n,&k,&a);
          if(n == 0 && k ==0 && a == 0) break;

          scanf("%d",&t);
          printf("Case %d:\n",cs++);
          int flag = 0;
          while(t--){
            long long mod;
            scanf("%lld",&mod);
//            cout << k << ' ' << n << mod << endl;
            long long temp = big(k,n,mod);
//            cout << temp << endl;
            temp = (temp*a)%mod;
//            cout << temp%41 << endl;
            if(temp < 0) temp += mod;
            if(flag) printf(" ");
            printf("%lld",temp);
            flag = 1;
          }
          printf("\n");
    }
}


//3 3 6
//3
//41 71 73
//3 3 6
//3
//41 71 73
//0 0 0
