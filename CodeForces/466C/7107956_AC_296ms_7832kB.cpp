#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define NN 500005
ll a[NN], cul[NN];
ll power(ll b ,ll p){
     if(p == 0) return 1;
     if(p&1)
        return b*power(b,p-1);
     else{
        ll x = power(b,p/2);
        return x*x;
     }
}
int main()
{
   ios_base :: sync_with_stdio(0); cin.tie(0);
   int n;
   cin >> n;
   ll zero = 0;
   ll sum = 0 , res = 0;
   for(int i = 0 ; i< n ; i++){
      cin >> a[i];
      sum += a[i];
      if(i)
        cul[i] = cul[i-1]+a[i];
      else cul[i] = a[i];
      if(cul[i] == 0)zero++;
   }
   if(sum%3){
      cout << 0 << endl;
      return 0;
   }
   else{
      if(sum == 0){
         zero--;
         if(zero&1)
            res = zero*((zero-1)/2);
         else res = (zero/2)*(zero-1);
      }
      else{
        ll x , y , cnt1 = 0 , cnt2 = 0;
        x = sum/3;
        y = sum/3*2;
        for(int i = n-1 ; i>= 0 ; i--){
            if(cul[i] == y)
                a[i] = a[i+1]+1;
            else a[i] = a[i+1];
         //   cout << i << ' ' <<  cul[i] << ' '  << a[i] <<  endl;
        }
        for(int i = 0 ; i< n ; i++){
            if(cul[i] == x) res += a[i];
        }
      }

   cout << res << endl;
   }
}