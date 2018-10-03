#include <bits/stdc++.h>
using namespace std;
int main()
{
 //  freopen("a.txt","w",stdout);
   int n;
   while(cin >> n && n){
      int a[10005] = {0};
      for(int i = 0 ; i< n ; i++){
         cin >> a[i];
      }
      int sum = 0;
      int mmax = -99999999;
      for(int i = 0, j = 0 ; i< n ; i++){
         sum += a[i];
         mmax = max(mmax, sum);
      //   cout << sum << ' ' << mmax << endl;
         while(sum <= 0 && j <= i){
            sum -= a[j];
            j++;
         }
      }

      if(mmax <= 0) cout << "Losing streak." << endl;
      else cout << "The maximum winning streak is " << mmax << "." << endl;
   }

}
