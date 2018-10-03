#include <bits/stdc++.h>
using namespace std;
#define ll         long long
#define  ull       unsigned long long
#define inf        (ll)  1e7
#define grey       1
#define black      2
#define white      0
#define  rep(i,x,y)   for(int i = x ; i< y ; i++)
int dp[505][505];
vector <int > prime;
template < class T > inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T > inline T lcm(T a, T b) {return a/gcd(a,b) * b;}
/*********************************************/


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
int a[501][501], b[501][501];
int call(int r , int c){
    int p1 = 0 , p2 = 0;
    if(r < 0 || c < 0) return 0;
    if(dp[r][c] != -1) return dp[r][c];
    p1 = a[r][c]+call(r-1,c);
    p2 = b[r][c] + call(r,c-1);
    return dp[r][c] = max(p1,p2);
}

void clr(){
 memset(a,0,sizeof(a));
 memset(b,0,sizeof(b));
 memset(dp,-1,sizeof(dp));

}
int main()
{
   int r , c;
   while(scanf("%d%d", &r , &c) == 2){
        if(!r && !c) break;
        r++ ; c++;
        clr();
        rep(i , 1 , r) rep(j , 1 , c){
           int temp;
           scanf("%d", &temp);
           a[i][j] = a[i][j-1]+temp;
        }
        rep(i , 1 , r) rep(j , 1 , c){
           int temp;
           scanf("%d", &temp);
           b[i][j] = b[i-1][j]+temp;
        }
        r--; c--;
        cout << call(r,c) << endl;
   }
}
