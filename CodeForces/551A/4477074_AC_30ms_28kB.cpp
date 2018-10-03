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
  int test , arr[2500] , i , j;
  while(cin >> test)
  {
      int hit[2500] = {0}, b[2500] = {0};
      for(i = 0 ; i<test ; i++)
          {
              cin >> arr[i];
              b[i] = arr[i];
          }
      sort(arr , arr+test);
      for(i = test - 1 ; i >= 0 ; i--)
      {
          if(hit[arr[i]] == 0)
          hit[arr[i]] = test - i;
      }
      for(i = 0 ; i< test ; i++)
        cout << hit[b[i]] << ' ';
      cout << "\n";


  }

}
