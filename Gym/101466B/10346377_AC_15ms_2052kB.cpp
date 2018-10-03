#include <bits/stdc++.h>
using namespace std;

bool comp(int a , int b){
   return a>b;
}
int main()
{
  int a[50], n;
  scanf("%d",&n);
  for(int i = 0 ; i< n ; i++){
     scanf("%d",&a[i]);
  }

  long long ans = 1, prev = 1;
  sort(a,a+n,comp);

  for(int i = 0 ; i< n ; i++){
       ans += prev*a[i];
       prev *= a[i];
  }
  printf("%lld\n",ans);
  return 0;
}
