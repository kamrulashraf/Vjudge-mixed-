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
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
template < class T> inline T big(T b, T p, T N){
   if(!p) return 1;
   if(!(p&1)){
    T x = big(b,p/2);
    return (x%N * x%N)%N;
   }
   return (b%N * big(b,p-1)%N)%N;
}
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
int r , c, vis[105][105];
char ch[105][105];
int dfs(int x , int y){
 vis[x][y] = 1;
 rep(i,0,8){
   if(vis[X(i)][Y(i)] == 0 && ch[X(i)][Y(i)] == '@' && X(i)>= 0 && X(i) < r &&  Y(i) >= 0 && Y(i) < c){
    dfs(X(i),Y(i));
   }
 }
}
int main()
{
   while(cin >> r >> c && r && c){
    int counter = 0;
    memset(vis,0,sizeof(vis));
    rep(i,0,r)
      rep(j,0,c)
         cin >> ch[i][j];
    rep(i,0,r){
      rep(j,0,c){
        if(vis[i][j] == 0 && ch[i][j] == '@'){
            counter++;
            dfs(i,j);
        }
      }
    }
    cout << counter << endl;
   }
}
