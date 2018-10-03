// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>

//  http://ideone.com/kxcEk8
using namespace std;
#define inf                  1e7
#define white                0
#define grey                 1
#define black                2
#define ll                   long long
#define ull                  unsigned long long
#define PI                   2.0*acos(0.0)   // acos(-1)
#define pii                  pair <int,int>
#define pll                  pair <ll,ll>
#define rep(i,x,y)           for(int i = x ; i < y ; i++)
#define ff                   first
#define ss                   second
#define X(i)                 x+fx[i]
#define Y(i)                 y+fy[i]
#define BOUNDRY(i,j)         ((i>=0 && i < r) && (j>= 0 && j< c))
#define WRITE                freopen("a.txt","w",stdout);
//***********************************************
#define MOD
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
inline void take(int &x) {scanf("%d",&x);}
inline void take(int &x ,int &y)  {scanf("%d %d",&x, &y);}
template < class T> inline T Set(T N, T pos){ return N = N | (1<< pos);}
template < class T> inline bool Check(T N , T pos){ return (bool) (N & (1<<pos));}
template < class T> inline T Reset(T N , T pos) { return N = N & ~(1 << pos); }
template < class T> inline T gcd(T a, T b) {
  while (a > 0 && b > 0)
    a > b ? a%=b : b%=a;
  return a + b;
}
int n;

vector < pii > v;
int dp[100005];
int call(int i,int mmax){
    if(i>=n) return 0;
    int ret = mmax, ret1 = mmax;
    if(dp[i] != -1) return dp[i];
    pii key = {v[i].ss,inf};
    int pos = upper_bound(v.begin(),v.end(),key) - v.begin();
    ret = 1+call(pos,mmax+1);
    ret1 = call(i+1,mmax);
    return dp[i] = max(ret,ret1);
}
int main()
{
    scanf("%d",&n);
   for(int i = 0 ; i< n ; i++){
      int a ,b;
      scanf("%d%d",&a,&b);
      v.push_back({a,b});
   }
   sort(v.begin(),v.end());
   // for(int i = 0 ; i< v.size() ; i++){
   //    cout << v[i].ff << ' ' << v[i].ss << endl;
   // }
   memset(dp,-1,sizeof dp);
   int res = call(0,0);
   cout << res << endl;
   return 0;
}
