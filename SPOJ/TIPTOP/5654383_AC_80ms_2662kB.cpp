#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
 long long num;
 int test, cs = 1;
 cin >> test;
 while(test--){
   scanf("%lld", &num);
   long long temp = sqrt(num);
   if(temp*temp == num){
     printf("Case %d: Yes\n",cs++);
   } else printf("Case %d: No\n",cs++);
 }
 return 0;
}
