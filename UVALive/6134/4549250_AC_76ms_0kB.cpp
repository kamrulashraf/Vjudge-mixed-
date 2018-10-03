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
  int i , j , k,a  , b,counter;
  while(scanf("%d %d", &a ,&b)==2){
    for(i= a, counter = 0 ; i<= b ; i++)
    {
        int save = i;
        int hit[100] = {0};
        int flag = -1;
        while(i!= 0){
            int digit = i%10;
            if(hit[digit]==0){
                hit[digit] = 1;
            }
            else{
                flag = 1;
                break;
            }
            i /= 10;
        }
        if(flag < 0) counter++;
        i = save;
    }
    cout << counter << endl;
  }
}
