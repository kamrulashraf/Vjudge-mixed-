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
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
int kfx[] = {2,2,-2,-2,1,1,-1,-1};
int kfy[] = {1,-1,1,-1,2,-2,2,-2};
void make_equal(string &a , string &b){
    if(a.size() == b.size()) return;
    if(a.size() < b.size()){
            swap(a,b);
    }
    string temp;
    for(int i = 0 ; i< a.size() - b.size() ; i++){
        temp += '0';
    }
    temp += b;
    b =temp;
}
int a[1001][1001], vis[1001][1001];
int main()
{
   int test,cs = 1;
    int r , c;
    while(cin >> r >> c){
         if(c == 0 && r == 0) break;
         memset(vis,0,sizeof(vis));
         int qk , kk , pk;
         cin >> qk;
         vector <pi> queen , pawn , knight;
         rep(i,0,qk){
            int t1 , t2;
            cin >> t1 >> t2;
            t1--;t2--;
            vis[t1][t2] = 5;
            queen.push_back(make_pair(t1,t2));
         }
         cin >> kk;
         rep(i,0,kk){
            int t1 , t2;
            cin >> t1 >> t2;
            t1--;t2--;
            vis[t1][t2] = 5;
            knight.push_back(make_pair(t1,t2));
         }
         cin >> pk;
         rep(i,0,pk){
            int t1 , t2;
            cin >> t1 >> t2;
            t1--;t2--;
            vis[t1][t2] = 5;
            pawn.push_back(make_pair(t1,t2));
         }
         for(int i = 0 ; i< queen.size() ; i++){
             int x = queen[i].first;
             int y = queen[i].second;
             int tx = x, ty = y;
             for(int j = 0 ; j< 8 ; j++){
                x = tx; y = ty;
                while(BOUNDRY(x+fx[j],y+fy[j])){
                    if(vis[x+fx[j]][y+fy[j]] == 5) break;
                    vis[x+fx[j]][y+fy[j]] = 1;
                    x += fx[j];
                    y += fy[j];
                }
             }
         }
         for(int i = 0 ; i< knight.size() ; i++){
             int x = knight[i].first;
             int y = knight[i].second;
             for(int j = 0 ; j< 8 ; j++){
                if(BOUNDRY(x+kfx[j],y+kfy[j])){
                    if(vis[x+kfx[j]][y+kfy[j]] != 5)
                      vis[x+kfx[j]][y+kfy[j]] = 2;
                }
             }
         }
         int counter =0;
         rep(i,0,r){
           rep(j,0,c){
            //  cout << vis[i][j] << ' ';
              if(vis[i][j] == 0) counter++;
           }
        //   puts("");
         }
       //  cout << counter << endl;
         printf("Board %d has %d safe squares.\n",cs++ ,counter);
    }
}
