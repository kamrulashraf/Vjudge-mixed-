// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define PI            2.0*acos(0.0)
#define pi            pair <int,int>
#define rep(i,x,y)      for(int i = x ; i < y ; i++)
#define fst(x)        v[x].first
#define sd(x)         v[x].second
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
int dp[205][105];
int main()
{
   int test,n,cse = 1;
   cin >> test ;
   while(test--){
     cin >> n;
     memset(dp,0,sizeof(dp));
     int mmax = 0;
     rep(i,1,2*n)
     {
         if(i<=n)
         rep(j,1,i+1){
            cin >> dp[i][j];
            dp[i][j] = max(dp[i][j]+dp[i-1][j-1], dp[i][j] + dp[i-1][j]);
            mmax = max(mmax,dp[i][j]);
         }
         else
          rep(j,1,n-(i%n)+1){
              cin >> dp[i][j];
              dp[i][j] = max(dp[i][j]+dp[i-1][j], dp[i][j] + dp[i-1][j+1]);
              mmax = max(mmax,dp[i][j]);
          }
     }
    printf("Case %d: %d\n",cse++,mmax);
   }
}
