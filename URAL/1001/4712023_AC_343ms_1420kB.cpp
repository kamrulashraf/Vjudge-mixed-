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
#define ull unsigned long long
using namespace std;
ull arr[1000005];
int main()
{
   ull num, i = 0,save;
   while(scanf("%llu", &num) != EOF)
   {
       arr[i] = num;
       save = i;
       i++;
   }
   while(i--){
    printf("%lf\n",(double) sqrt(arr[i]));
   }
  return 0;
}
