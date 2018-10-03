// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define inf             100000
#define white                0
#define grey                 1
#define black                2
#define ll                   long long
#define ull                  unsigned long long
#define PI                   2.0*acos(0.0)   // acos(-1)
#define pi                   pair <int,int>
#define rep(i,x,y)           for(int i = x ; i < y ; i++)
#define fst(x)               v[x].first
#define sd(x)                v[x].second
#define X(i)                 x+fx[i]
#define Y(i)                 y+fy[i]
#define BOUNDRY(i,j)         ((i>=0 && i < r) && (j>= 0 && j< c))
//***********************************************

#define ashraf
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


//******************************************************
template < class T> inline T Set(T N, T pos){ return N = N | (1<< pos);}
template < class T> inline bool Check(T N , T pos){ return (bool) (N & (1<<pos));}
template < class T> inline T Reset(T N , T pos) { return N = N & ~(1 << pos); }
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
template < class T> T big(T b , T p , T mod){
    if(p == 0) return 1;
    if(!(p&1)){
        T x = big(b,p/2,mod);
        return (x*x)%mod;
    }
    else return (b*big(b,p-1,mod))%mod;
}
template <class T> inline T cmax(T a,T b, T c){T temp = max(a,b); return max(temp,c);}
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
int p[101] , c[101] , w[101], n;
int dp[101][10005];
int call(int i , int maxW){
   int p1 = 0,p2 = 0, p3;
   if(i == n) return 0;
   if(dp[i][maxW] != -1) return dp[i][maxW];
   if(maxW - w[i] >= 0){
      p1 = p[i]+call(i+1,maxW-w[i]);
   }
   if(maxW - w[i] >= 0){
      p2 = p[i]+call(i,maxW-w[i]);
   }
   p3 = call(i+1,maxW);
   return dp[i][maxW] = cmax(p1,p2,p3);
}
int main()
{
  int test , cs = 1;
  cin >> test;
  while(test--){
     int maxW;
     cin >> n >> maxW;
     int ans = 0;
     for(int i = 0 ; i< n ; i++){
        cin >> p[i] >> c[i] >> w[i];
        maxW -= c[i]*w[i];
     }
     printf("Case %d: ",cs++);
     if(maxW < 0){
        printf("Impossible\n");
        continue;
     }
     memset(dp,-1,sizeof(dp));
     ans += call(0,maxW);
     printf("%d\n",ans);
  }
}

