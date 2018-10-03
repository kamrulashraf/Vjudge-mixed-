#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <string>
#include <queue>
#include <cstring>
#include <list>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <utility>

#define ll long long
#define FOR(x,y)for(int x = 0 ; x<y ; x++)
ll a[1000000+5] , save[1000000] = {2};
using namespace std;
void seive()
{
    ll  i , j;
    for(i = 3 ; i*i < 1000000 ; i+= 2)
        if(a[i] == 0)
        for(j = i*i ; j<1000000 ; j+= 2*i)
         a[j] = 1;
    for(i = 3, j = 1 ; i<1000000 ; i+= 2)
        if(a[i] == 0)
        {
            save[j] = i;
            j++;
        }
}
int main()
{
 ll test ,i ,j, num;
 seive();
 scanf("%lld", &test);
 while(test--)
 {
     scanf("%lld", &num);
     printf("%lld\n", save[num-1]);
 }

}
