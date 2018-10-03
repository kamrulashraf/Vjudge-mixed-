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
int flag, mark[3];
bool vis[250], color[250];
map < int, vector <int> > g;
void dfs(int u){
    vis[u]= 1;
    mark[color[u]]++;
    for(int i = 0 ; i< g[u].size() ; i++){
       int v  =g[u][i];
       if(!vis[v]){
           color[v] = 1-color[u];
           dfs(v);
       }
       else{
         if(color[v] != 1 - color[u]){
            flag = 1;
         }
       }
    }
return;
}
int main()
{
 // freopen("a.txt", "w" , stdout);
  int test;
  cin >> test;
  while(test--){
     memset(vis,0,sizeof(vis));
     memset(color,0,sizeof(color));
     int node , edge;
     cin >> node >> edge;
     for(int i = 0 ; i< edge ; i++){
       int a , b;
       cin >> a >> b;
       g[a].push_back(b);
       g[b].push_back(a);

     }
     int black = 0;
     for(int i = 0 ; i< node ; i++){
        if(!vis[i]){
           flag = 0;
           memset(mark,0,sizeof(mark));
           dfs(i);
           if(flag == 1) break;
           black += min(mark[0],mark[1]);
           if(min(mark[0],mark[1])==0)
              black++;
        }
     }
     if(flag == 1) cout << -1 << endl;
     else cout << black << endl;
     g.clear();
  }

}
