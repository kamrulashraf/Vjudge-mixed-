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
int fx[] = {0,1,0,-1};
int fy[] = {1,0,-1,0};
int vis[100][100] , r , c,counter;
char ch[105][105];

int dfs(int x , int y){
 vis[x][y] = 1;
 if(ch[x][y] == 'G') counter++;
 int flag = 0;
 rep(i,0,4){
   if(ch[X(i)][Y(i)] == 'T'){
    flag = 1;
    break;
   }
 }
 if(flag == 0){
     rep(i,0,4){
       int p = X(i);
       int q = Y(i);
       if(vis[p][q] == 0 && p >= 0 && q >= 0 && p < r && q < c && ch[p][q] != '#' ){
        dfs(p,q);
       }
     }
 }
  return counter;
}
int main()
{
   int x , y;
   while(cin >> c >> r){
    memset(vis,0,sizeof(vis));
    rep(i,0,r)
      rep(j,0,c){
        cin >> ch[i][j];
        if(ch[i][j] == 'P'){
            x = i;
            y = j;
        }
      }
    counter = 0;
    cout << dfs(x,y) << endl
    ;
   }
return 0;
}

