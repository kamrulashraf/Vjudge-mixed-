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
  int i , j , test ,a , b ,c,sum,sum1;
  cin >> test;
  while(test--){
    cin >> a >> b >> c;
    for(i = 1, sum = b,sum1 = b ; i <a ; i++)
        {
            sum += c;
            sum1 += sum;
        }

    cout << sum1 << endl;
  }
return 0;
}
