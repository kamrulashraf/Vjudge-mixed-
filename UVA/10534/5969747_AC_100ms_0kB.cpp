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
int a[10005] ,save[10005], save1[10005], mmax[10005] , mmax1[10005];
void lis(int n){
    int sub[10005], len = 0;
    rep(i,0,n+1) sub[i] = inf;
    sub[0] = -inf;
    for(int i = 0 ; i< n ; i++){
       int pos = lower_bound(sub,sub+len+1 , a[i]) - sub;
       sub[pos] = a[i];
       len = max(len , pos);
       save[i] = len;
       mmax[i] = sub[len];
    }

}

void revLis(int n){
    int sub[10005], len = 0;
    rep(i,0,n+1) sub[i] = inf;
    sub[0] = -inf;
    for(int i = n-1 ; i >= 0 ; i--){
       int pos = lower_bound(sub,sub+n , a[i]) - sub;
       sub[pos] = a[i];
       len = max(len , pos);
       save1[i] = len;
       mmax1[i] = sub[len];
    }

}
int main()
{
  // freopen("a.txt","w",stdout);
   int n;
   while(cin >> n){
      rep(i,0,n) cin >> a[i];
      lis(n);
      revLis(n);
//      rep(i,0,n) cout << save[i] << ' ';
//      cout << "\n";
//            rep(i,0,n) cout << mmax[i] << ' ';
//      cout << "\n";
//      rep(i,0,n) cout << save1[i] << ' ';
//      cout << "\n";
//      rep(i,0,n) cout << mmax1[i] << ' ';
//      cout << "\n";
      int ans = 0;
      for(int i = 0 ; i < n-1  ; i++){
           if(mmax[i] > mmax1[i+1] && save[i] > save1[i+1]){
          //    cout << i << '#' << mmax[i] << ' ' << mmax1[i+1] << ' ' << save[i] << ' ' << save1[i+1] << endl;
              int temp = 2*save1[i+1]+1;
              if(temp&1)
              ans = max(ans, 2*save1[i+1]+1);
           }
      }
      if(!ans) ans++;
      cout << ans << endl;
   }

}
