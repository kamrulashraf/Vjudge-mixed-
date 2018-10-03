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
  long long int i , j , k,sum,test,arr[100008] = {0};
  scanf("%I64d", &test);

  for(i = 0; i < test ; i++)
  {
      scanf("%I64d", &arr[i]);
  }
  for(i = 0,sum = arr[0] ; i< test-1 ; i++)
  {
      sum += abs(arr[i] - arr[i+1]);
  }
  sum += 2*test-1;
  cout << sum << endl;
}
