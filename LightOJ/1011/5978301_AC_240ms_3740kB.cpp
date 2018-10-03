#include <bits/stdc++.h>
using namespace std;
#define ll         long long
#define  ull       unsigned long long
#define inf        (ll)  1e7
#define grey       1
#define black      2
#define white      0
#define  rep(i,x,y)   for(int i = x ; i< y ; i++)
template < class T> inline T Set(T N, T pos){ return N = N | (1<< pos);}
template < class T> inline bool Check(T N , T pos){ return (bool) (N & (1<<pos));}
template < class T> inline T Reset(T N , T pos) { return N = N & ~(1 << pos); }
template < class T > inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T > inline T lcm(T a, T b) {return a/gcd(a,b) * b;}
/*********************************************/


#define ashra
#ifdef ashraf
     #define so(args...) {cerr<<"so: "; dbg,args; cerr<<endl;}
#else
    #define so(args...)  // Just strip off all debug tokens
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

int popCount(int mark){
   int counter = 0;
   while(mark){
     if(mark&1) counter++;
     mark = mark >> 1;
   }
   return counter;
}
long long a[25][25], n;
long long dp[ 1 << 16 + 2];
long long call(int mask, int r){
     long long mmax = 0;
     if(dp[mask] != -1) return dp[mask];
     if(r == n) return 0;
     for(int i = 0 ; i< n ; i++){
        if(Check(mask,i) == 0){
           so(mark,r,i);
        //   so(popCount(mark));
           int temp = Set(mask,i);
           dp[temp] = call(temp,r+1);
           mmax = max(a[r][i]+dp[temp] , mmax);
        }
     }
    return mmax;
}
int main()
{
//  freopen("a.txt","w",stdout);
  int test,cs = 1;
  cin >> test;
  while(test--){
     cin >> n ;
     memset(dp,-1,sizeof(dp));
     rep(i,0,n) rep(j,0,n)  cin >> a[i][j];
     ll ans = call(0,0);
     printf("Case %d: %lld\n",cs++ ,ans);
  }

}
