#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    long long int i , j , k, test,save, x , y;
    scanf("%lld", &test);
    while(test--)
    {
        scanf("%lld %lld", &x, &y);
        int max = 0;
        for(i = x ; i<= y ; i++)
        {
            int counter = 0;
            double rt = sqrt(i);
            for(j = 1 ; j<=rt ; j++)
            {
                if(i%j == 0){
                    counter++;
                    if(j<rt) counter++;
                }
            }
            if(counter> max)
            {
                max = counter ;
                save = i;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %d divisors.\n", x , y , save , max);
    }
return 0;
}
