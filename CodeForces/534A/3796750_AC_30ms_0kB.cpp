#include <stdio.h>
int main()
{
 int num,i,j,n;
 while(scanf("%d", &num)==1)
 {   if(num == 1 || num == 2 ) printf("1\n");
     else if(num == 3 ) printf("2\n");
     else printf("%d\n", num);
     if(num%2==0)
       {
           j = num;
           i = num-1;
       }
     else  {
            i =num;
            j = num -1;

           }
     for(i;i>0;i-=2)
     {
         printf("%d ", i);
     }

     for(j;j>0;j-=2)
     {    if(num<=3) continue;
           printf("%d ", j);
     }


         printf("\n");
 }
}
