#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
  int num,sum;
  while((scanf("%d", &num))==1)
       {
           if(num==0) break;
        sum = 0;
        num = num + 1;
        while(1)
                {sum = sum + num/3;
                 num = (num/3 + num%3);
                  if(num<3)
                    break;
                }
        printf("%d\n", sum);
        }
}

