#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
int a,i,sum,c;
while(scanf("%d", &a)==1)
{
    for(sum = 0,c = 0,i=1;   ;i++)
    {
        sum = sum + i;
        c = sum + c;
        if(c >= a)
        {
         if(c != a)
            i = i -1;
         break;
        }

    }
  cout << i << "\n";
}

}
