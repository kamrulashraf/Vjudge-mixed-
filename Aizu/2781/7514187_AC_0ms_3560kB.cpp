// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>

//  http://ideone.com/kxcEk8
using namespace std;
#define NN 205
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
double grad(double n){ return (PI*n)/180; }
double agrad(double n){ return (180*n)/PI; }
template < class T> inline T gcd(T a, T b) {
  while (a > 0 && b > 0)
    a > b ? a%=b : b%=a;
  return a + b;
}
template <class T > inline T  modInv(T n, T m) {
      T x, y, gcd;
      extEuclid(n, m, x, y, gcd);
      if (gcd == 1) return x % m;
      return 0;
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

int fx[] = {0,1,0,-1};
int fy[] = {1,0,-1,0};
    int r , c;
string ch[NN];
int vis[NN][NN];
int level[NN][NN];
void dfs(int m , int n){
     vis[m][n] = 1;
     queue < pii > q;
     q.push(make_pair(m,n));
     while(!q.empty()){
         int x = q.front().ff;
         int y = q.front().ss;
         q.pop();
         for(int i = 0 ; i< 4 ; i++){
             int X = fx[i]+x;
             int Y = fy[i]+y;
             if(  BOUNDRY(X,Y) && !vis[X][Y] &&  ch[X][Y] != '#'){
                  level[X][Y] = 1+level[x][y];
                  q.push(make_pair(X,Y));
                  vis[X][Y] = 1;
             }
        }

     }
}
int main()
{
//    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c;
    int savex , savey, psavex , psavey;
    for(int i = 0 ; i< r ; i++){
        cin >> ch[i];
        for(int j = 0 ; j< ch[i].size() ; j++){
             if(ch[i][j] == '%'){
                savex = i;
                savey = j;
             }
             if(ch[i][j] == '@'){
               psavex = i;
               psavey = j;
             }
        }
    }
    memset(vis,0,sizeof vis);
    memset(level,0,sizeof level);
    dfs(savex,savey);
    bool flag = 0;
    for(int i = 0 ; i< r ; i++){
        for(int j = 0 ; j< ch[i].size() ; j++){
             if(ch[i][j] == '$'){
                if(level[i][j] <= level[psavex][psavey]){
                    flag = 1;
                }
             }
//             cout << level[i][j] << ' ';
        }
//        cout << endl;
    }

    if(flag == 1) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
