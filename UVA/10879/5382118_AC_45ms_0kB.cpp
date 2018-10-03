#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   ll n,test,cse = 1;
   cin >> test;
   while(test--)
   {
       cin >> n;
       printf("Case #%lld: %lld = ",cse++, n);
       for(ll i = 2,counter = 0 ; i<= n ; i++)
       {
           if(n%i == 0){
            counter++;
            if(counter == 1)
            printf("%lld * %lld = ",i,n/i);
            else
             printf("%lld * %lld\n",i,n/i);
            if(counter == 2) break;

           }
       }

   }
}
