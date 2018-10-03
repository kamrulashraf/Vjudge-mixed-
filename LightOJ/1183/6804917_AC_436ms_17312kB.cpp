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
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};

long long tree[1000005], lazy[1000005];
long long update(int node ,int b,int e,int i,int j,int val){
    int left = 2*node;
    int right= left+ 1;
    if(lazy[node] != -1){
        tree[node] = (e-b+1)*lazy[node];
        if(b!=e)
            lazy[left]=lazy[node],
            lazy[right] = lazy[node];
        lazy[node]=-1;
    }
    if( b > j || e < i) return tree[node];
    if( b >= i && e <= j){
  //      cout << b << ' ' << e << ' ' << val << endl;
        lazy[left]=val;
        lazy[right]=val;
        return tree[node]=(e-b+1)*val;
    }
    int m=(b+e)/2;
    return tree[node] = update(left,b,m,i,j,val)+update(right,m+1,e,i,j,val);
}

long long  query(int node,int b,int e,int i,int j){
    int left = 2*node;
    int right= left+ 1;
    if(lazy[node] != -1){
        tree[node] = (e-b+1)*lazy[node];
        if(b!= e)
            lazy[left]=lazy[node],
            lazy[right] = lazy[node];
        lazy[node]= -1;
    }
    if( b > j || e < i) return 0;
    if(b >= i && e <= j) return tree[node];
    int m=(b+e)/2;
    return query(left,b,m,i,j)+query(right,m+1,e,i,j);
}
int main()
{
    int test, cs = 1;
    scanf("%d",&test);
    while(test--){
      memset(tree,0,sizeof(tree));
      memset(lazy,-1,sizeof(lazy));
      int n , q;
      scanf("%d%d",&n,&q);
      printf("Case %d:\n",cs++);
      for(int i = 0 ; i< q ; i++){
     //   cout << "&&&&&&&&&&&&&&&&&" << endl;
        int t , p , q, val;
        scanf("%d",&t);
        if(t==1){
            scanf("%d%d%d", &p,&q,&val);
            p++ , q++;
            update(1,1,n,p,q,val);
        } else{
          scanf("%d%d",&p,&q);
          p++ , q++;
          long long temp = query(1,1,n,p,q);
          long long hor = (q-p+1);
          long  long g = gcd(temp,hor);
      //    cout << temp << ' ' << hor << ' ' << temp%hor << endl;
          if(temp%hor == 0)
            printf("%lld\n",temp/hor);
          else
          printf("%lld/%lld\n",temp/g,hor/g);
        }
      }
    }
   return 0;
}
