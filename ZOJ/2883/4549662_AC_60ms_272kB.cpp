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
 int i , j ;
 int test,sum,num, arr[100005];
 cin >> test;
 while(test--)
 {
     cin >> num;
     int save = num%3;
     for(i = 0 ; i<num ; i++)
        cin >> arr[i];
     sort(arr, arr+num);
     for(i = 0,sum = 0 ; i<num/3 ; i++)
        sum += arr[i*3+save];
     cout << sum << endl;
 }
}
