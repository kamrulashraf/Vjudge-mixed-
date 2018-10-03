// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI            2.0*acos(0.0)   // acos(-1)
#define pi            pair <int,int>
#define rep(i,x,y)      for(int i = x ; i < y ; i++)
#define fst(x)        v[x].first
#define sd(x)         v[x].second
#define X(i)          x+fx[i]
#define Y(i)          y+fy[i]
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
map < int , int > vis;
map < char , vector < char > > g;

int dfs(int u){
vis[u] = 1;
for(int i = 0 ; i< g[u].size() ; i++){
   int v = g[u][i];
   if(!vis[v])
      dfs(v);
}

}
int main()
{
  int test, cs = 0;
  cin >> test;
  getchar();
  while(test--){
     string ch, s;
     cin >> ch;
     if(cs) cout << "\n";
     cs++;
     getchar();
     while(1){
        getline(cin , s);
        if(s.empty()) break;
        g[s[0]].push_back(s[1]);
        g[s[1]].push_back(s[0]);
     }
     int ans = 0;
     for(int i = 'A' ; i<= ch[0] ; i++){
        if(vis[i] == 0){
           dfs(i);
           ans++;
        }
     }
     cout << ans << endl;
     cs++;
     g.clear();
     vis.clear();

  }
 return 0;
}
