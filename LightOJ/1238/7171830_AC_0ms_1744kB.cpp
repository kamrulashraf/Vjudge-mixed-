// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>

//  http://ideone.com/kxcEk8
using namespace std;
#define NN 100
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
char ch[NN][NN];
bool vis[NN][NN];
int level[NN][NN];
int r , c;
void bfs(int x , int y){
    queue < pii > q;
    q.push({x,y});
    vis[x][y] = 1;
    while(!q.empty()){
        x = q.front().ff;
        y = q.front().ss;
        for(int i = 0 ; i< 4 ; i++){
            int xx = x+fx[i];
            int yy = y+fy[i];
            if(!vis[xx][yy] && BOUNDRY(xx,yy) && ch[xx][yy] != '#' && ch[xx][yy] != 'm'){
                vis[xx][yy] = 1;
                level[xx][yy] = level[x][y]+1;
                q.push({xx,yy});
            }
        }
        q.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int test, cs = 1;
    cin >> test;
    while(test--){
        cin >> r >> c;
        int ax , ay ,bx , cx , cy , by , savex , savey;
        for(int i = 0 ; i< r ; i++){
            for(int j = 0 ; j<c ; j++){
                cin >> ch[i][j];
                if(ch[i][j] == 'h'){
                    savex = i;
                    savey = j;
                }
                if(ch[i][j] == 'a'){
                    ax = i;
                    ay = j;
                }
                if(ch[i][j] == 'b'){
                    bx = i;
                    by = j;
                }
                if(ch[i][j] == 'c'){
                    cx = i;
                    cy = j;
                }
            }
        }
        memset(vis,0,sizeof(vis));
        memset(level,0,sizeof level);
        bfs(savex,savey);
        int p1 = max(level[ax][ay], level[bx][by]);
        p1 = max(p1, level[cx][cy]);
        printf("Case %d: %d\n",cs++ , p1 );
    }
}
