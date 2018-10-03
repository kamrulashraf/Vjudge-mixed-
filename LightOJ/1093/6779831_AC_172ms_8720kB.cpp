
// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define inf                  1e9
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
void take(int &a){ scanf("%d",&a);}
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
#define D  300005
ll mmax[D], mmin[D], a[D];
int n;
void makeTree(int node , int b ,int e){
   if(b == e){
      if(b >= n){
          mmax[node] = 0;
          mmin[node] = inf;
          return;
      }
      mmax[node] = a[b];
      mmin[node] = a[b];
      return;
   }
   int l = node<<1;
   int r = l+1;
   int m = (b+e)>>1;
   makeTree(l , b , m);
   makeTree(r , m+1, e);
   mmax[node] = max(mmax[l] , mmax[r]);
   mmin[node] = min(mmin[l] , mmin[r]);
  // so(node , mmax[node] , mmin[node]);
}
void query(int node , int b ,int e ,int i , int j, ll &ma , ll &mb){
    if( b > j || e < i){
       ma = -1;
       mb = inf;
       return;
    }
    if( b >= i && e <= j){
       ma = mmax[node];
       mb = mmin[node];
  //    so(node, i, j , b , '*', e , ma,mb);
       return;
    }
    int l = node << 1;
    int r = l+1;
    int mid = (b+e)>>1;
    ll x , y , m , n;
    query(l , b , mid , i , j , x , y );
    query(r , mid+1 , e , i , j , m , n);
    ma = max(x,m);
    mb = min(y,n);
   // so(node , b , e , ma,mb);
}
int main()
{
   int test,cs = 1;
   take(test);
   while(test--){
      int k;
      memset(mmax,0,sizeof(mmax));
      rep(i,0,D) mmin[i] = inf;
      scanf("%d%d",&n,&k);
      rep(i,0,n) scanf("%lld",&a[i]);
      long long smax , smin;
      makeTree(1,0,n);
      long long ans = 0;
      for(int i = 0 ; i+k < n ; i++){
          int t = i+k-1;
          query(1,0,n,i,t,smax,smin);
          ans = max(ans,smax-smin);
      }
      printf("Case %d: %lld\n",cs++ , ans);
   }
}