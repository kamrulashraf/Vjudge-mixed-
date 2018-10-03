#include <bits/stdc++.h>
using namespace std;
#define N 2000005
int a[N];
int main()
{
   int n, s , t;
   cin >> n ;
   int sum = 0;
   for(int i = 0 ; i< n ; i++){
      cin >> a[i];
      sum += a[i];
   }

   cin >> s >> t;
   if(t < s) swap(t,s);
   s-- , t--;
   int diff = t-s;
  int res = 0, mmax = 1e9;
   for(int i = s,j = 0 ; j < diff ;j++, i++){
      int indx = (i%n);
      res += a[indx];

   }
//   cout << res << ' ' << diff << endl;
   mmax = min(mmax, res);
   mmax = min(mmax,sum-res);
   cout << mmax << endl;
}
