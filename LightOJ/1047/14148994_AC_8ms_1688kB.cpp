#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI            2.0*acos(0.0)   // acos(-1)
#define pi            pair <int,int>
#define rep(i,x,y)      for(int i = x ; i < y ; i++)
#define fst(x)        v[x].first
#define sd(x)         v[x].second
#define X(i)          x+fx[i]
#define Y(i)          y+fy[i]
#define INF 9999999
template < class T> inline T Set(T N, T pos){ return N = N | (1<< pos);}
template < class T> inline bool Check(T N , T pos){ return (bool) (N & (1<<pos));}
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
template < class T> inline T big(T b, T p, T N){
   if(!p) return 1;
   if(!(p&1)){
    T x = big(b,p/2,N);
    return (x%N * x%N)%N;
   }
   return (b%N * big(b,p-1,N)%N)%N;
}
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
int a[25][5], dp[25][5], n;
 
int call(int x , int y){
 if(x+1 == n) return a[x][y];
 if(dp[x][y] != INF) return dp[x][y];
 rep(i,0,3){
   if(i!= y){
    //   cout << x << ' ' <<i<< endl;
       dp[x][y] = min(dp[x][y] , a[x][y]+call(x+1,i));
   }
 }
 return dp[x][y];
 
}
 
int main()
{
   int test,cse = 1 ;
   cin >> test;
   while(test--){
    cin >> n;
    rep(i,0,n){
      rep(j,0,3){
         cin >> a[i][j];
         dp[i][j] = INF;
      }
    }
    int mmin = INF;
    rep(i,0,3){
       mmin = min(mmin,call(0,i));
    }
    printf("Case %d: %d\n", cse++ , mmin);
   }
  return 0;
}
 