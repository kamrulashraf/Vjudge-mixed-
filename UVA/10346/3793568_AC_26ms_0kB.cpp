#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int num,n,blank,drink;
    while(scanf("%d %d", &num, &n)==2)
    {
        drink =num;
        blank = num;
        while(blank>=n)
        {
            drink = drink + blank / n;
            blank = blank / n + blank%n;
        }
        cout << drink << "\n";
    }
}
