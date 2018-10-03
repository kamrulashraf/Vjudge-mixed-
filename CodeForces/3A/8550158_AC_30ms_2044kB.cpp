#include <bits/stdc++.h>
using namespace std;
#define pii pair < int , int >
#define ff first
#define ss second

int fx[] = {0,0,1,-1,-1,-1,1,1};
int fy[] = {1,-1,0,0,-1,1,1,-1};
int vis[10][10];
pair < int , int > par[10][10];
int level[10][10];
int sx , sy , tx , ty;
string str[] = {"L" , "R", "U" , "D" ,"RD" , "LD" , "LU" , "RU"};
void bfs(int x , int y){
     queue < pii > q;
     q.push({x,y});
     vis[x][y] = 1;
     while(!q.empty()){
          int xx = q.front().ff;
          int yy = q.front().ss;
          q.pop();
          for(int i = 0 ; i< 8 ; i++){
              int nx = xx+fx[i];
              int ny = yy+fy[i];

              if(vis[nx][ny] == 0 && (nx>=0 && nx < 8 && ny >= 0 && ny < 8)){
                  q.push({nx,ny});
                  vis[nx][ny] = 1;
                  par[nx][ny] = {xx,yy};
                  level[nx][ny] = level[xx][yy]+1;
              }
          }
     }
}


void print(int x, int y){
   int tempx , tempy;
   tempx = par[x][y].ff;
   tempy = par[x][y].ss;
//   cout << x << ' ' << y << endl;
   if(x==sx && y == sy) return;
   if(x < 0 || x >= 8 || y < 0 && y>= 8) return;
   int save ;
   for(int i = 0 ; i< 8 ; i++){
      int nx = x+fx[i];
      int ny = y+fy[i];
      if(nx==tempx && ny==tempy){
         save = i;
         print(nx,ny);
         break;
      }
   }
   cout << str[save] << endl;
}
int main()
{
    string a  , b;
    cin >> a >> b;
     sx = 8-(a[1]-48);
     sy = a[0]-97;
     tx = 8-(b[1]-48);
     ty = b[0]-97;
    bfs(sx,sy);
    cout << level[tx][ty] << endl;
    print(tx,ty);
    return 0;

}
