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
  int i;
  long int j , test , a,b;
  cin >> test;
  while(test--)
  {
      long int sum = 0, num;
      cin >> a >> b;
      for(i = 0, sum = 0 ; i<a ; i++)
      {
          cin >> num ;
          sum += num;
      }
      if(sum > b)
        cout << "Warning" << endl;
      else cout << "Safe" << endl;
  }
}
