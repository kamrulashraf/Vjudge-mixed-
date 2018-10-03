// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI            2.0*acos(0.0)   // acos(-1)
#define pi            pair <int,int>
#define rep(i,x,y)      for(int i = x ; i < y ; i++)
#define ff(x)        v[x].first
#define ss(x)         v[x].second
#define X(i)          x+fx[i]
#define Y(i)          y+fy[i]
template < class T> inline T Set(T N, T pos){ return N = N | (1<< pos);}
template < class T> inline bool Check(T N , T pos){ return (bool) (N & (1<<pos));}
template < class T> inline T Reset(T N , T pos) { return N = N & ~(1 << pos); }
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
template < class T> inline T big(T b, T p, T M){
   if(!p) return 1;
   if(!(p&1)){
    T x = big(b,p/2,M);
    return (x%M * x%M)%M;
   }
   return (b%M * big(b,p-1,M)%M)%M;
}
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
int dp[101][25000];
int main()
{
  int  n, test, a[200];
  cin >>  test;
  while(test--){
    int sum = 0;
    memset(dp,0,sizeof(dp));
    scanf("%d", &n);

    rep(i,1,n+1){
      scanf("%d", &a[i]);
      sum += a[i];
    }

    int mmax = sum/2;
    for(int i = 1; i <= n ; i++){
        for(int j = 0 ; j<= mmax ; j++){
            if(a[i] <= j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]]+a[i]);
            }
            else
            dp[i][j] = dp[i-1][j];
        }
    }

  //  cout << sum-2*dp[n][mmax] << endl;
    printf("%d\n", sum - 2*dp[n][mmax]);
  }
}

