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
int main()
{
  int a , b, sum;
  cin >> a >> b;
  sum = a+b-1;
 // if(sum<= 10)
  cout << sum-a << ' ' << sum-b << endl;
 // else cout << 10 - a << ' ' << 10-b << endl;
}
