#include <bits/stdc++.h>
using namespace std;
int fx[ ] = {-1,-1,0,0,1,1};
int fy[ ] = {-1,0,-1,1,0,1};
int n, flag;
char ch[250][250];
bool vis[250][250];
void dfs(int x, int y, char color){
//cout << x << ' ' << y << endl;
if(color == 'w' && y == n-1) flag = 1;
if(color == 'b' && x == n-1) flag = 1;
for(int i = 0 ; i< 6 ; i++){
   vis[x][y] = 1;
   int p = x+fx[i];
   int q = y+fy[i];
   if(ch[p][q] == color && vis[p][q] == 0 && p>=0 && p < n && q >= 0 && q < n)
      dfs(p,q,color);

}

}
int main()
{
  int cs = 1;
  while(cin >> n && n){
     memset(vis,0 , sizeof(vis));
     bool black = 0 , white = 0;
     for(int i = 0 ; i< n ; i++)
        for(int j = 0 ; j< n ; j++)
            cin >> ch[i][j];

     for(int i  = 0 ; i< n ; i++){
        if(ch[i][0] == 'w'){
           flag = 0;
           dfs(i,0, 'w');
           if(flag == 1) white = 1;
        }

     }

     for(int i  = 0 ; i< n ; i++){
        if(ch[0][i] == 'b'){
           flag = 0;
           dfs(0,i, 'b');
           if(flag == 1) black = 1;
        }

     }
     cout << cs++ << ' ';
     if(black) cout << "B" << endl;
     else cout << "W" << endl;

  }

}
