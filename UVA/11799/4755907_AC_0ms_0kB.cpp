#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
   int test, i , j, num , arr[100000], caseno = 0;
   cin >> test;
   while(test--)
   {
       caseno++;
       cin >> num;
       for(i = 0 ; i<num ; i++)
         cin >> arr[i];
       sort(arr, arr+num);
       printf("Case %d: %d\n", caseno, arr[num-1]);

   }
 return 0;
}
