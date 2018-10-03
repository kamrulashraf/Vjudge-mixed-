#include <stdio.h>
int main()
{
    long long  s,d;
    long long i,sum;
    while(scanf("%lld %lld", &s, &d)==2)
    {   sum = 0;
        for(s;s<=d;s++)
        {
            sum = sum + s ;
            if(sum>=d)
            {
              break;
            }


        }
     printf("%lld\n", s);
    }
return 0;
}
