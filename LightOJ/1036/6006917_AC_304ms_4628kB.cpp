// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
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
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
int a[501][501] ,  b[501][501];
int dp[501][501];
int call(int r , int  c)
{
    if(r == 0 || c == 0) return 0;
    int p1 = 0;
    int p2 = 0;
    if(dp[r][c] != -1) return dp[r][c];
    p1 = a[r][c]+call(r-1,c);
    p2 = b[r][c]+call(r, c-1);
    return dp[r][c] = max(p1,p2);
}
int main()
{
  int test , cs = 1;
  scanf("%d", &test);
  while(test--){
     int r , c;
     scanf("%d%d", &r , &c);
     rep(i,1,r+1) rep(j , 1 , c+1){
        int temp;
        scanf("%d", &temp);
        a[i][j] = a[i][j-1]+temp;
     }

     rep(i,1,r+1) rep(j , 1 , c+1){
        int temp;
        scanf("%d", &temp);
        b[i][j] = b[i-1][j]+temp;
     }
     memset(dp,-1,sizeof(dp));
     int ans = call(r,c);
     printf("Case %d: %d\n", cs++ ,ans);
  }


return 0;
}
