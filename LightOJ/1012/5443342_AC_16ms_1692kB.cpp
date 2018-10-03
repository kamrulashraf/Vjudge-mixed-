#include <bits/stdc++.h>
using namespace std;
#define PI               2.0*acos(0.0)
#define pi               pair <int,int>
#define rep(x,y)         for(int z = x ; z < y ; z++)
#define fst(x)           v[x].first
#define sd(x)            v[x].second
#define X(i)             x+fx[i]
#define Y(i)             y+fy[i]
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
int fx[] = {0,0,1,-1};
int fy[] = {1,-1,0,0};
int counter, vis[25][25],r,c;
int  dfs(int x, int y){
    vis[x][y] = 1;
    for(int i=0; i<4;i++){
        if(!vis[X(i)][Y(i)] && X(i)<r && Y(i)<c  &&  X(i)>=0  && Y(i)>=0){
            counter++;
            dfs(X(i), Y(i));
        }
    }
    return counter;
}
int main()
{
   int test,x,y, caseno = 1;
   string s;
   cin >> test;
   while(test--){
       memset(vis,0,sizeof(vis));
       cin >> c >> r;;
       for(int i=0; i<r;i++){
        cin >> s;
        for(int j=0; j<c; j++){
            if(s[j] == '#') vis[i][j] = 1;
            if(s[j] == '@'){
                x = i;
                y = j;
            }
        }
       }
      counter = 1;
      printf("Case %d: %d\n",caseno++ , dfs(x,y));
   }
 return 0;
}
