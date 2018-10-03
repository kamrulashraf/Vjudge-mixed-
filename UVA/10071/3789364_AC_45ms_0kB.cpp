#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
int v,s,t;
float a;
while ((scanf("%d %d", &v, &t))!=EOF)
       {
        s = 2*v*t;
        printf("%d\n", s);
       }
}
