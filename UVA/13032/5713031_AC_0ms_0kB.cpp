#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main()
{
   long long  n  , test , cs = 1, a[1000];
   cin >> test;
   while(test--){
        cin >> n;
       for(int i = 0 ; i< n ; i++ )
           cin >> a[i];
       sort(a,a+n);
       long long ans = 1;
       for(int i = 0 ; i< n ; i++){
          long long temp = a[i]-i;
          if(temp<0) temp = 0;
          ans = (ans*temp)%mod;
       }
     printf("Case %lld: %lld\n", cs++ , ans);
   }
 return 0;
}
