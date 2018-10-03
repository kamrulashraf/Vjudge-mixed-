#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
    int test,i,j,sum,k,m,n1;
    char num[100];
    int n[100];
    cin >> test;
    getchar();
    while(test--)
    {
      m=0;
      n1=0;
      gets(num);
      for(i=0,j=0;i<strlen(num); i++)
      {
         if(num[i] < 58)
            {
                n[j] = num[i] - 48;
                j++;
            }
            else continue;
      }
      for(sum = 0,i=0;i<j;i++)
        {

            sum = sum * 10;
            sum = sum + n[i];


        }
        while(sum!=0)
        {
            m = m + sum%2;
            sum = sum / 2;
        }
        cout << m << ' ';

        for(i=0;i<strlen(num);i++)
           {
               if(num[i] == '0')  n1 += 0;
               if(num[i] == '1' || num[i]== '2' || num[i]== '4' || num[i]== '8')  n1 += 1;
               if(num[i] == '3' || num[i] == '5'|| num[i]=='6' || num[i]== 'A' || num[i]== 'C' || num[i] == '9')  n1 += 2;
               if(num[i] == '7' || num[i]== 'B'|| num[i]== 'D'|| num[i]== 'E')  n1 += 3;
               if(num[i]== 'F') n1 +=4;



           }

        cout << n1 << "\n";
    }
}
