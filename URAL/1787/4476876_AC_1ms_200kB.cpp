#include <stdio.h>
int main()
{
 int k,n,num[100],i,remain,sum;
 while(scanf("%d %d", &k, &n)==2)
 {
     for(sum = 0,i=0;i<n;i++)
         {
           scanf("%d", &num[i]);
           sum = sum + num[i] - k;
           if(sum<0) sum = 0;
         }
     printf("%d\n", sum);


 }
}
