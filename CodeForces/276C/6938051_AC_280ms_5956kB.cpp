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
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
template < class T> T big(T b , T p , T mod){
    if(p == 0) return 1;
    if(!(p&1)){
        T x = big(b,p/2,mod);
        return (x*x)%mod;
    }
    else return (b*big(b,p-1,mod))%mod;
}

template < class T> T POW(T b , T p){
    if(p == 0) return 1;
    if(!(p&1)){
        T x = POW(b,p/2);
        return (x*x);
    }
    else return (b*POW(b,p-1));
}
#define NN 200005
ll n , q, cul[NN], tree[NN];
int a[NN];
void update(int indx, int val){
    while(indx <= n){
        tree[indx] += val;
        indx += indx & -indx;
    }
}
long long query(int indx){
    ll sum = 0;
    while(indx){
        sum += tree[indx];
        indx -= indx & -indx;
    }
    return sum;
}
int main()
{
   cin >> n >> q;
   rep(i,1,n+1) scanf("%d",&a[i]);
   while(q--){
    int x , y;
    scanf("%d%d",&x,&y);
    update(x,1);
    update(y+1,-1);
   }
   cul[0] = 0;
   for(int i = 1 ; i<= n ; i++)
      cul[i] = query(i);

   sort(a+1,a+n+1);
   sort(cul+1,cul+n+1);
   ll res = 0;
   for(int i = 1 ; i<= n ; i++){
      res += a[i]*cul[i];
    //cout << i << ' ' << a[i] << ' ' << cul[i] << ' ' << endl;
   }
   cout << res << endl;
}
