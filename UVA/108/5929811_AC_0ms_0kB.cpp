#include <bits/stdc++.h>
using namespace std;
#define inf 99999
#define rep(i , x , y)   for(int i   = x  ; i < y ; i++)
int main()
{
 //freopen("a.txt","w",stdout);
  int n, ha[105],a[105][105], mmax;
  while(cin >> n){
      int ans = -999999;
      memset(a,0,sizeof(a));
      rep(i,1,n+1)  rep(j,1,n+1){
         int temp;
         cin >> temp;
         a[i][j] += a[i-1][j] + temp;
      }
//       rep(i,1,n+1){
//         rep(j,1,n+1)
//            cout << a[i][j] << ' ';
//         cout << "\n";
//       }
       rep(i,1,n+1)  rep(j,i,n+1){
         //   cout << i << ' ' << "#" << j << endl;
            int sum = 0;
            mmax = -999999;
            for(int k = 1, l = 1 ; k<= n ; k++){
                ha[k] = a[j][k] - a[i-1][k];
                sum += ha[k];
               // cout << sum << ' ';
                mmax = max(sum,mmax);
                while(sum <= 0 && l <= k){
                   sum -= ha[l];
                   l++;
                }
            }
            //cout << "\n";
            ans = max(ans, mmax);
       }

       cout << ans << endl;

  }

}

