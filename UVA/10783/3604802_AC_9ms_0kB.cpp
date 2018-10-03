#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
int test,c=0,sum;
int a,b;
scanf("%d", &test);
while(test--)
     {
     c++;
     scanf("%d %d", &a, &b);
     if(a%2==0)
        a = a +1;
     for (sum = 0,a; a<= b;a+=2)
            {
             sum = sum + a;
            }
       printf("Case %d: %d\n",c, sum);

     }
}
