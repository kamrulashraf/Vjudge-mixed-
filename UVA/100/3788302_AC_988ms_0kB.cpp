#include <stdio.h>
int main()
{
 int temp,i,j,k,num=1;
 while(scanf("%d %d", &i,&j)==2)
     { printf("%d %d ", i,j);
     if(i>j)
         {
          temp=i;
          i=j;
          j=temp;
         }
    int max=1;
        for(k=i;k!=j+1;k++)
         {while (i!=1)
            {if(i%2==1)
                {
                i=3*i+1;
                num++;
                }
            else
                {
                i=i/2;
                num++;
                }
            if(num>max)
                {max=num;}
                }
        i=k+1;
        num=1;
         }
    printf("%d\n", max);
     }
return 0;
}
