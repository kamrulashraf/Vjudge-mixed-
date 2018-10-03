#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
 int h,m;
 float angle,angle1;
 while(scanf("%d:%d", &h, &m)==2)
 {   if(h==0 && m==0)
           break;
     angle = 11.0/2.0*m - 30*h;
     if(angle<0) angle = angle * -1;
     angle1 = 360.0 - angle;
     angle = min(angle,angle1);
     printf("%.3f\n", angle);

 }
}
