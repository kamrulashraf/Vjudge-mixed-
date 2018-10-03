#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <math.h>
#include <stack>
#include <cstring>
#include <string>
using namespace std;
int main()
{
 double a , b ,c ,d;
 int test, i;
 cin >> test;
 for(i = 1 ; i<= test ;i++)
 {
   cin >> a >> b >> c >> d;
   d = d /(d+1);
   printf("Case %d: %.7lf\n", i , a*sqrt(d));
 }
}
