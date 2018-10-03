#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
 long long int num,num1,sum,n=0,p;
 int test;
 cin >> test;

 while(test--)
 {   n=0;
     cin >> num;
     sum = 0;
     num1 = num;
     while(num !=0)
         {
          sum = sum *10;
          sum = sum + num%10;
          num = num/10;
         }
     num = num1 + sum;
     while(1)
     {
      n++;
      sum = 0;
      num1 = num;
      while(num !=0)
         {
          sum = sum *10;
          sum = sum + num%10;
          num = num/10;
         }
      p = sum;
      if(num1 == p)
           {
            printf("%lld %lld\n", n, num1);
            break;
           }
      else num = num1 + p;
     }

 }

}
