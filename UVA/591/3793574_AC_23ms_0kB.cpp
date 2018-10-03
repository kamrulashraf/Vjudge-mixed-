#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int n,i,sum,sum1,c,num,caseno = 0;
    int arr[100];
    while((scanf("%d", &n)==1) && n !=0)
    {   caseno ++;
        sum1 = 0;
        for(sum=0,i=0;i<n;i++)
            {
             scanf("%d", &arr[i]);
             sum = sum + arr[i];
            }
         num = sum / n;
        for(c = 0, i=0;i<n;i++)
        {
            c = arr[i] - num;
            if(c>0)
                sum1 = sum1 + c;

        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", caseno,sum1);

    }
}
