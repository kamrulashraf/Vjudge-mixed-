// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI                   2.0*acos(0.0)   // acos(-1)
#define pi                   pair <int,int>
#define rep(i,x,y)           for(int i = x ; i < y ; i++)
#define fst(x)               v[x].first
#define sd(x)                v[x].second
#define X(i)                 x+fx[i]
#define Y(i)                 y+fy[i]
#define white    0
#define black    5
#define  grey    1
#define BOUNDRY(i,j)         ((i>=0 && i < r) && (j>= 0 && j< c))

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
map < int , int > vis,num,low;
map < int , vector <int> > g;
stack <int> st;
int counter = 0, ans;
void dfs(int u){
  vis[u] = grey;
  st.push(u);
  low[u] = num[u] = counter++;
  for(int i  = 0 ; i< g[u].size() ; i++){
      int v = g[u][i];
      if(!vis[v])
          dfs(v);
      if(vis[v] == grey) low[u] = min(low[u],low[v]);
  }
  if(low[u] == num[u]){
     ans++;
     while(1){
         int temp = st.top();
         vis[temp] = black;
         st.pop();
         if(temp == u) break;
     }
  }
}
int main()
{
  int node , edge;
  while(cin >> node >> edge){
     if(node == 0 && edge == 0) break;
     for(int i = 0 ; i< edge ; i++){
        int a, b , c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        if(c == 2)
        g[b].push_back(a);
     }
     counter = 0;
     ans = 0;
     bool flag = 0;
     for(int i = 1 ; i<= node ; i++){
        if(!vis[i]) dfs(i);
     }
     if(ans!= 1) cout << 0 << endl;
     else cout << 1 << endl;
     g.clear();
     vis.clear();
     num.clear();
     low.clear();
  }

}
