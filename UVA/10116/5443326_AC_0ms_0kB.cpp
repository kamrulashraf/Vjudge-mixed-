// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI            2.0*acos(0.0)
#define pi            pair <int,int>
#define rep(i,x,y)      for(int i = x ; i < y ; i++)
#define X(i)         x+fx[i]
#define Y(i)         y+fy[i]
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
int fx[] = {0,1,0,-1};
int fy[] = {1,0,-1,0};
int main()
{
  int r , c , y, x = 0;
  char ch[100][100];
  int h[260];
  h['E'] = 0;
  h['S'] = 1;
  h['W'] = 2;
  h['N'] = 3;
  while( cin >> r >> c >> y && r && c && y)
  {
      x = 0; y--;
      int vis[105][105] = {0},counter = 0, level[105][105] = {0},tx, ty,flag = 0;

      rep(i,0,r)
        rep(j,0,c)
           cin >> ch[i][j];

      int p = h[ch[x][y]];

      while(x >=0 && x < r && y >= 0 && y < c ){
            counter++;
            level[x][y] = counter;
            vis[x][y] = 1;
            p = h[ch[x][y]];
            tx = x ; ty = y;
            x = X(p);
            y = Y(p);
            if(vis[x][y] == 1){
                flag = 1;
                break;
            }
      }
      if(flag == 0)
            cout << counter << " step(s) to exit" << endl;
      else printf("%d step(s) before a loop of %d step(s)\n", level[x][y]-1 ,level[tx][ty]-(level[x][y]-1));
  }

}
