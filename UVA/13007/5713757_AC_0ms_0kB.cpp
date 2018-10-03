#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long mod = 1000000007;
template < class T> T big(T b , T p , T mod){
  if(p == 0) return 1;
  if( p& 1){
    return (b*big(b,p-1,mod))%mod;
  }
  else {
     T x = big(b,p/2,mod);
     return (x*x)%mod;
  }

}
int main()
{
    int  n,m , test , cs = 1,a[150];
    int ha[] = {1,10,100,1000,10000};
 //  long long b = big((ll)3,mod-2,mod);
   while(scanf("%d %d", &n , &m) != EOF){
         long long ans = 0;
         long long sum = 0, temp = 0 ,save = 0;

         for(int i = 0 ; i< m ; i++){
              sum = 0;
              for(int j = 0 ; j<= n ; j++){
                scanf("%d", &a[j]);
                sum += a[j];
              }
       //     cout << sum << endl;
            save = 0;
            if(sum-a[0] <= a[0])
                temp += a[1];
            sum -= a[0]+a[1];
         //   cout << sum << endl;
            for(int j = 0 ; j< 5 ; j++){
            //    cout << ha[j] + sum << ' ' << a[0] << endl;
                if(ha[j]+sum <= a[0])
                    save = ha[j];
            }
            ans += save;
         }
        cout << ans - temp << endl;
   }

 return 0;
}
