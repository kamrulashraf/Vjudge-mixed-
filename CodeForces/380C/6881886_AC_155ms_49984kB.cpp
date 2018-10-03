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
#define NN 1000005
int tree[4*NN],close[4*NN],open[4*NN];
    char s[NN];
void makeTree(int node, int b,int e){
   int l=2*node;
   int r=l+1;
   int m=(b+e)/2;
   if(b==e){
  //  cout << node << ' ' << s[e] << ' ' << e << endl;
    if(s[e] == '(') open[node]++;
    if(s[b] == ')') close[node]++;
    return;
   }
   makeTree(l,b,m);
   makeTree(r,m+1,e);
   int save = min(open[l],close[r]);
//   cout << node << ' ' << open[l] << ' ' << close[r] << endl;
   tree[node] = tree[l]+tree[r] + save;
   open[node] = open[l]-save+open[r];
   close[node] =  close[r]-save+close[l];
}
struct snode{
  int a, b , c;
  snode(int x , int y , int z){
    a = x;
    b = y;
    c = z;
  }
};
snode query(int node,int b,int e,int i,int j){
   int l=2*node;
   int r=l+1;
   int m=(b+e)/2;
  // cout <<b << ' ' << ' ' << e << endl;
   if(b > j || e < i) return snode(0,0,0);
   if(b >= i && e <= j){
      //  cout << b << '*' << e << ' ' << tree[node] << ' ' << open[node] << ' ' << close[node] <<  endl;
        return snode(open[node],tree[node],close[node]);
   }
   snode p1 = query(l,b,m,i,j);
   snode p2 =query(r,m+1,e,i,j);
   int save = min(p1.a,p2.c);
  // cout << b << '#' << e << ' ' << p1.a-save +p2.a << ' ' << save+p1.b+p2.b <<  ' ' << p1.c-save+p2.c << ' ' << save << endl;
   return snode(p1.a-save+p2.a, p1.b+save+p2.b , p1.c-save+p2.c);
}
int main()
{
    scanf("%s", &s[1]);
    int len = 0;
    while(s[++len]);
    makeTree(1,1,len-1);
//    for(int i = 1 ; i<(len-1)*2 ; i++){
//       cout << i << ' ' << open[i] << ' ' << tree[i] << ' ' << close[i] <<  endl;
//    }
    int q;
    cin >> q;
    for(int i = 0 ; i< q ; i++){
      int x , y;
      scanf("%d%d",&x , &y);
      snode save = query(1,1,len-1,x,y);
      int res = save.b;
      printf("%d\n",2*res);
    }
}