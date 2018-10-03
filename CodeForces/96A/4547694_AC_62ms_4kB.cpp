#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int i , j , k , len, sum , flag;
    char s[200];

    while(gets(s))
    {
    len = strlen(s);
    for(i = 0 ; i< len ; i++)
        {
             for(j = i, sum = 0 ; j < i+7 ; j++)
             {
                 if(i+7 > len)
                 {
                      sum = 5;
                      break;
                 }
                 sum += s[j] - '0';
             }
             if(sum == 0 || sum == 7)
             {
                 flag = 1;
                 cout << "YES" << endl;
                 break;
             }
             else flag = 0;
         }
      if(flag==0) cout << "NO" << endl;
    }
}
