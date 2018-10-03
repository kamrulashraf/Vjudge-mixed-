#include <bits/stdc++.h>
using namespace std;
#define inf  1000000
#define grey       1
#define black      2
#define white      0
#define  rep(i,x,y)   for(int i = x ; i< y ; i++)
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
int a[105][105], dp[105][105];
void clr(){
  memset(dp,0,sizeof(dp));
}
int fx[ ] = {-1,-1,-1};
int fy[ ] = {-1,0,1};
int maxF(int x , int y){
  int mmax = -inf;
  for(int i = 0 ; i<3 ; i++){
      mmax = max(mmax,a[x][y] + dp[x + fx[i]][y+fy[i]]);
  }
  return mmax;
}
int main()
{
   int test, cs = 1;
   cin >> test;
   while(test--){
      int r , c;
      clr();
      cin >> r >> c;
      for(int i = 1 ; i<= r ; i++){
         for(int j = 1 ; j<= c ; j++){
            cin >> a[i][j];
         }
      }
      int mmax = -inf;
      for(int i = 1 ; i<= r ; i++)
         for(int j = 0 ; j<= c ; j++){
            dp[i][j] = maxF(i,j);
            mmax = max(dp[i][j], mmax);
         }

      cout << mmax << endl;

   }

}
