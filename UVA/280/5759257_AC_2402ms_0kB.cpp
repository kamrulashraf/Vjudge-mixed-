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
map < int , bool > vis;
map < int , vector <int> > g;
vector <int> v;
void dfs(int u){
for(int i = 0 ; i< g[u].size() ; i++){
  int v = g[u][i];
  if(!vis[v]){
     vis[v] = 1;
     dfs(v);
  }
}

}

int main()
{
   int node ;
   while(cin >> node && node){
       int mother;
       while(cin >> mother && mother){
           int child;
           while(cin >> child && child){
             g[mother].push_back(child);
           }
       }
       int test;
       cin >> test;
       while(test--){
          vis.clear();
          int temp;
          cin >> temp;
          dfs(temp);
          for(int i = 1 ; i <= node ; i++){
              if(vis[i] == 0)
                v.push_back(i);
          }
          cout << v.size();
          for(int i =  0 ; i < v.size() ; i++)
               cout << ' ' << v[i];
          cout << "\n";
          v.clear();

       }
       g.clear();
   }

}

