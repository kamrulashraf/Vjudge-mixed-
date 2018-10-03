#include <bits/stdc++.h>
using namespace std;
#define ll         long long
#define  ull       unsigned long long
#define inf        (ll)  1e7
#define grey       1
#define black      2
#define white      0
#define  rep(i,x,y)   for(int i = x ; i< y ; i++)
int dp[105][105];
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
int n;
int lcs(int a[ ] , int b[ ], int n){
 int dp[25][25] = {0};
 for(int i = 1 ; i<= n ; i++){
     for(int j = 1 ; j <= n ; j++){
        dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        if(a[i] == b[j])
           dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
     }
 }
return dp[n][n];
}

int main()
{
   int actualPosition[25], mark[25];
   cin >> n;
   int a[25], cs = 0;
      rep(i,0,n){
            cin >> a[i];
            mark[a[i]] = i+1;
      }
//      rep(i,0,n+1) cout << mark[i] << ' ';
//      puts("");
      while(cin >> a[0]){
          actualPosition[a[0]] =1;
          rep(i,1,n){
            cin >> a[i];
            actualPosition[a[i]] = i+1;
          }
//      rep(i,0,n) cout << actualPosition[i] << ' ';
//      puts("");
       cout << lcs(actualPosition, mark , n) << endl;
     }

}
