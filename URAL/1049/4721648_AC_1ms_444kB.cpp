#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
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
vector <int> v;
map < ll , int> m;
int a[10000], save[10000]= {2};
void p(void)
{
    int i , j;
    for(i = 3 ; i*i< 10000 ; i+=2)
        if(a[i]==0)
        for(j = i*i ; j<10000 ; j+= 2*i)
          a[j] = 1;
    for(i = 3,j=1 ; i<10000 ; i+=2)
        if(a[i]==0)
    {
        save[j]=i;
        j++;
    }
}
void fac(int num)
{
    int N = sqrt(num);
    int i,j;
    for(i = 0 ; save[i] <= N ; i++)
    {
        int counter=0;
        while(num%save[i] == 0)
        {
            if(m[save[i]]==0) v.push_back(save[i]);
            m[save[i]]++;
            num = num/save[i];
        }
    }
    if(num>1) {
            if(m[num] == 0)
            v.push_back(num);
            m[num]++;
    }
}
int main()
{
  int i , j ,k,a;
  p();
//  for(i = 0 ; i<20 ; i++) cout << save[i] << ' ';
  for(i = 0 ; i<10 ; i++)
  {
      cin >> a;
      fac(a);
  }
  int s = v.size();
  ll ans = 1;
  for(i  =0 ; i <s ; i++)
  {
      ans *= (m[v[i]]+1);
  }
  cout << ans%10 << endl;
}
