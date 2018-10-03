// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>

//  http://ideone.com/kxcEk8
using namespace std;
#define inf                  1e13
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
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
#define NN 400005
long long arr[NN];
map < long long , long long > hit;
int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
     int n , k;
     scanf("%d%d", &n , &k);
     long long ans = 0;
     for(int i = 0 ; i< n ; i++) scanf("%lld",&arr[i]);
     for(int last = 0, prev = 0 ; last < n ; last++){
          hit[arr[last]]++;
          while(hit[arr[last]] == k && prev <= last){
              if(hit[arr[last]] == k)
                 ans += n - last;
//              cout << last << ' ' <<  n-last+1 << endl;
              hit[arr[prev]]--;
              prev++;
          }
     }
     printf("%lld\n", ans);

}