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
map < int , vector <int> > g;
map < int , int > vis , ans;

void dfs(int u){
vis[u] = 1;
ans[u]++;
for(int i = 0 ; i< g[u].size() ; i++){
    int v = g[u][i];
    if(!vis[v])
      dfs(v);
}

}
int main()
{
  int test , cs = 1;
  int man , node , edge, nman[1005];
  cin >> test;
  while(test--){
      cin >> man >> node >> edge;
      for(int i = 0 ; i< man ; i++){
          cin >> nman[i];
      }
      for(int i = 0 ; i< edge ; i++){
          int a , b;
          cin >> a >>b;
          g[a].push_back(b);
      }
      for(int i = 0 ; i < man ; i++){
          vis.clear();
          dfs(nman[i]);
      }
      int counter = 0;
      for(int i = 1 ; i <= node ; i++){
        if(ans[i] == man) counter++;
      }

      printf("Case %d: %d\n", cs++ ,counter);
      g.clear();
      ans.clear();

  }

}
