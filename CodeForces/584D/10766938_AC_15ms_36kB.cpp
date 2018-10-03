#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h>
#include <queue>
#include <cstring>
#include <list>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define ll long long
#define FOR(x,y)for(int x = 0 ; x<y ; x++)
#define ll long long
using namespace std;
int a[5000] , save[1500]={2};
void seive()
{
    int i,j;
    for(i = 3 ; i<sqrt(5000) ; i++)
        if(a[i] == 0)
        for(j = i*i ; j<= 5000 ; j+= i*2)
          a[j] = 1;
    for(i = 3 , j = 1 ; i<= 2500 ; i+= 2)
    if(a[i] == 0) {save[j] = i ; j++;}
}
int isprime(ll num)
{
    int i;
    for(i = 2 ; i*i <= num ; i++)
        if(num%i == 0) return 0;
    return 1;
}
int main()
{
  ll num, i;
  vector <ll> v;
  seive();
  scanf("%I64d", &num);
  if(isprime(num)) cout << 1 << "\n" << num << endl;
  else{
    v.push_back(3);
    num = num-3;
    for(i = 0 ; i<500 ; i++)
    {
        //cout << num - save[i] << endl;
        if(isprime(num - save[i]))
        {
            v.push_back(save[i]);
            v.push_back(num-save[i]);
            break;
        }
    }
  int s = v.size();
  cout << s << endl;
  for(i = 0 ; i< s ; i++)
  cout << v[i] << ' ';
  }


}