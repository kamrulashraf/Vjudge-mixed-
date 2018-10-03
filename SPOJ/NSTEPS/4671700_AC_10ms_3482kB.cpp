#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define FOR(x,y)for(int x = 0 ; x<y ; x++)
using namespace std;
int main()
{
  long long x , y , test;
  scanf("%lld", &test);
  while(test--)
  {
      scanf("%lld %lld", &x , &y);
      if(y%2 == 0)
        {
            if((x+y)%2 == 0 && (x-y) <= 2 && (x-y) >= 0)
                printf("%lld\n", y+x);
            else printf("No Number\n");
        }
      if(y%2 != 0)
        {
            if((x+y-1)%2 == 1 && (x-y) <= 2 && (x-y) >= 0)
            printf("%lld\n", y+x-1);
            else printf("No Number\n");

        }
  }
 return 0;
}
