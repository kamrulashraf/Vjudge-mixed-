#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main()
{
   long long a , b,x,y;
   int test , cs= 1;
   scanf("%d",&test);
   while(test--){
      scanf("%lld%lld",&a,&b);
      if(a==0 && b== 0){
         printf("1\n");
         continue;
      }
      if(a == 0){
         printf("2\n");
         continue;
      }
      if(b==0){
         printf("1\n");
         continue;
      }
      x = a*a - b*b;
      y = 2*a*b;
      a= x; b = y;
      if(a == 0){
         printf("%d\n",4);
         continue;
      }
      printf("TOO COMPLICATED\n");
   }
}

