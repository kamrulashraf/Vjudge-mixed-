#include <stdio.h>
int main()
{
double c,d,f;
int test,count= 0;
scanf("%d", &test);
   while(test--){
   scanf("%lf %lf", &c, &d);

   f = c + (5/9.0)*d;
   count ++;

   printf("Case %d: %.2lf\n", count, f);
   }
}
