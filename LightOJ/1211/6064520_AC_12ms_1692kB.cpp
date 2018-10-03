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
int a[101] , b[101] , c[101] , d[101] , e[101] , f[101];
int main()
{
   int test , cs = 1;
   cin >> test;
   while(test--){
        int n;
        cin >> n;
        for(int i =  0 ; i < n ; i++){
            cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i] >> f[i];
        }
        int temp = n-1;
        sort(a,a+n);
        sort(b,b+n);
        sort(c,c+n);
        sort(d,d+n);
        sort(e,e+n);
        sort(f,f+n);
        int x1 = a[temp] , y1 = b[temp] , z1 = c[temp] , x2 = d[0] , y2 = e[0] , z2 = f[0];
      //  so(x1 , y1 , z1, x2 , y2 , z2);
        long long ans;
        if((x2-x1) < 0 || (y2-y1) < 0 || (z2-z1) < 0){
           ans = 0;
        }
        else{
           ans = (x2-x1)*(y2-y1)*(z2-z1);
        }
        printf("Case %d: %lld\n",cs++ ,ans);
   }
}
