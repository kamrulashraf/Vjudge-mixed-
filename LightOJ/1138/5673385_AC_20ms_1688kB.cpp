#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll numOfFive(ll mid){
ll sum = 0;
while(mid)
  sum += (mid/=5);
  return sum;
}
int main()
{
  ll test, num, temp, cse = 1;
  scanf("%lld", &test);
  while(test--){
   scanf("%lld", &num);
   ll b = 1 , e = 1000000000;
   while(b<= e){
    ll mid = (b+e)/2;
    temp = numOfFive(mid);
    if(temp < num)
       b = mid+1;
    else e = mid-1;
   }
    if(num == numOfFive(b))
        printf("Case %lld: %lld\n", cse++ , b);
    else printf("Case %lld: impossible\n", cse++);
  }

}
