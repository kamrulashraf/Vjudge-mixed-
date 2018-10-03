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
map < string , vector < string > > g;
vector < string > slist;
map < string, int > vis, num , low, hit;
stack < string > st;
int counter,ans;


void dfs(string u){
   vis[u] = grey;
   num[u] = low[u] = counter++;
   st.push(u);
   for(int i = 0 ; i< g[u].size() ; i++){
      string v = g[u][i];
      if(vis[v] == white){
         dfs(v);
         low[u] = min(low[u],low[v]);
      }
      if(vis[v] == grey){
         low[u] = min(low[u],low[v]);
      }
   }
   if(low[u] == num[u]){
      ans++;
      while(1){
        string temp = st.top();
        st.pop();
        vis[temp] = black;
        if(temp == u){
           break;
        }
      }
   }
}
int main()
{
   int  node , edge ;
   while(cin >> node >> edge){
      set < string > s;
      getchar();
      set < string > :: iterator it;
      if(node == 0 && edge  == 0) break;
      for(int i = 0 ; i< node ; i++){
          string str;
          getline(cin , str);
          s.insert(str);

      }
      for(int i = 0 ; i< edge ; i++){
         string a , b;
         getline(cin , a);
         getline(cin , b);
         g[a].push_back(b);
      }
      ans = 0;
      for(it = s.begin() ; it != s.end() ; it++){
         counter = 0;
         if(!vis[*it]) dfs(*it);
      }

      cout << ans << endl;
      vis.clear();
      s.clear();
      g.clear();
      num.clear();
      low.clear();
   }

}

