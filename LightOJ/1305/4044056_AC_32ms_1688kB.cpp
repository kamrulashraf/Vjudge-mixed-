#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int test,i;
    int ax , ay , bx , by , cx , cy , x  , y;
    cin >> test;
    for(i = 1 ; i<= test ; i++)
    {
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        y =  ay + cy - by;
        x = cx + ax - bx;
        int area = (ax*by - ay*bx) + (bx*cy - by*cx) + (cx*y - cy*x) + ( x*ay - y*ax);
        printf("Case %d: %d %d %d\n", i , x , y , abs(area/2));
    }
return 0;
}
