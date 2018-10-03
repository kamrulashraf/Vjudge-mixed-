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
#define WRITE                freopen("a.txt","w",stdout);
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
template < class T >
inline T cMax(T a , T b , T c){
    T temp = max(a,b);
    return max(temp,c);
}
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
int dp[51][51][51];
int lcs(string a , string b , string c){
     rep(i,1,a.size()+1) rep(j,1,b.size()+1) rep(k,1,c.size()+1){
         dp[i][j][k] = cMax(dp[i-1][j][k] , dp[i][j-1][k] , dp[i][j][k-1]);
         if(a[i-1] == b[j-1] && b[j-1] == c[k-1])
            dp[i][j][k] = 1+dp[i-1][j-1][k-1];
     }
 return dp[a.size()][b.size()][c.size()];
}
int main()
{
 //  WRITE;
   int test , cs = 1;
   cin >> test;
   while(test--){
        string a , b , c;
        cin >> a >> b >> c;
        memset(dp,0,sizeof(dp));
        printf("Case %d: %d\n", cs++ , lcs(a,b,c));
//        rep(i,1,a.size()+1){
//          rep(j,1,b.size()+1){
//              so(i,j);
//              rep(k,1,c.size()+1){
//                     cout << dp[i][j][k] << ' ';
//              }
//              puts("");
//           }
//        }
   }

}

