#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
 long long unsigned int a,b,n,c,temp;
 while (scanf("%llu %llu", &a, &b)==2)
 {
     if(a%b==0) n = a/b;
     else if(a%b!=0)
        { n = 0;
         while(a%b!=0)
         {
             n = n + (a - (a%b))/b;
             temp = a%b;
             a = b;
             b = temp;
         }
         if(a%b==0) n = n+ a/b;
        }
   cout << n << "\n";

 }
}
 