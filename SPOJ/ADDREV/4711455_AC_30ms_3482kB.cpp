#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
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
using namespace std;
int call(int num)
{
    int sum = 0;
    while(num)
    {
       sum = sum*10 + num%10;
       num = num/10;
    }
    return sum;
}
int main()
{
  int i , j , k,a,b , test;
  cin >> test;
  while(test--)
  {
      scanf("%d %d", &a , &b);
      int m = call(a)+call(b);
      cout << call(m) << endl;

  }
}
