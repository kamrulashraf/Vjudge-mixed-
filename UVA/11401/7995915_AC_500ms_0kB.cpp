#include <bits/stdc++.h>
using namespace std;
int main()
{
     long long n;
     while(cin >> n){
         if(n < 3) break;
         long long res = 0;
         for(int i = 1 ; i<= n ; i++){
              long long temp = n-2*i-1;
              long long sum;
              if(temp <= 0) break;
              if(temp&1)
                 sum  =   (temp)*((temp+1)/2);
              else sum = (temp/2)*(temp+1);
              res += sum;
              // cout << temp << ' ' << sum << endl;
         }
         printf("%lld\n",res);
     }
     return 0;
}
