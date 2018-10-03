#include <bits/stdc++.h>
using namespace std;
#define PI    acos(-1)
vector < int > prime;
bool a[100000003];
inline void seive(long long num){
memset(a,0,sizeof(a));
for(int i = 3 ; i*i <= num ; i+= 2)
  if(!a[i])
     for(int j = i*i ; j<= num ; j+= 2*i)
       a[j] = 1;
prime.push_back(2);
for(int i = 3 ; i<= num ; i+= 2)
    if(!a[i])
       prime.push_back(i);
}
int main()
{
  seive(100000001);
  int num;
  while(cin >> num && num){
      int temp = lower_bound(prime.begin() , prime.end() , num) - prime.begin();
      if(prime[temp] != num) temp--;
      float ans = temp+1;
      float ap = ( ans -  num / log(num) ) /ans * 100.0;
      printf("%.1f\n",abs(ap));

  }


}
