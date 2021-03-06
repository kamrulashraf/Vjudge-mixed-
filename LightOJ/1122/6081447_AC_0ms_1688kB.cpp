// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define inf                  1e7
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
#define WRITE                freopen("a.txt","w",stdout);
//***********************************************
#define MOD
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
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
int main()
{
   int test , cs = 1;
   scanf("%d", &test);
   while(test--){
      int dp[20][20] = {0}, a[20];
      int n , k;
      scanf("%d%d",&n , &k);
      rep(i,0,n){
         scanf("%d",&a[i]);
         dp[0][a[i]] = 1;
      }
      int ans = 0, ss = 0;
      for(int i = 1 ; i<k ; i++){
          ss = 0;
          for(int j = 0 ; j< n ; j++){
               int sum = 0;
               for(int k = 0 ; k <n ; k++){
                  if(abs(a[k] - a[j]) <= 2){
                     so(a[j], a[k], dp[i-1][a[k]];);
                     sum += dp[i-1][a[k]];
                  }
               }
               dp[i][a[j]] = sum;
               so(sum);
               ss += sum;
          }
      }
      printf("Case %d: %d\n",cs++ ,max(n,ss));
   }
}
