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
int dp[105][105], n,width;
struct node{
   int a, b, c;
   node(int x, int y , int z){
     a = x;
     b = y;
     c = z;
   }
};
vector < node > ans;
bool comp(node x , node y){
   return x.c > y.c;
}

vector <ll> v;
int call(int i , int w){
    if(i >= n || w <= 0) return 0;
    int key = v[i]+width;

    int pos = upper_bound(v.begin() , v.end() , key) - v.begin();
    int p1 = 0, p2 = 0;
    if(dp[i][w] != -1) return dp[i][w];
    p1 = call(i+1 , w);
    if(w - 1 >= 0)
    p2 = pos - i + call(pos , w-1);
    so(i,w, max(p1,p2));
    return dp[i][w] = max(p1 , p2);
}
int main()
{
 // freopen("a.txt","w",stdout);
  int test , cs = 1;
  scanf("%d", &test);
  while(test--){
     int  w , k;
     scanf("%d%d%d", &n , &w , &k);
     rep(i,0,n){
        int a;
        ll b;
        scanf("%d%lld", &a , &b);
        v.push_back(b);
     }
     sort(v.begin() , v.end());
     width = w;
     memset(dp,-1,sizeof(dp));
     int res = call(0,k);
     printf("Case %d: %d\n", cs++ , res);
     v.clear();
  }
}


