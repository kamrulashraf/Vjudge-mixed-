#include <bits/stdc++.h>
using namespace std;
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
int r , c;
 int test , cs = 1, hx , hy;
char ch[30][30];
bool vis[30][30];
int level[30][30];
vector < pair <int,int> > v;
int bfs(int x,  int y){
   queue < pair < int,int> > q;
   vis[x][y] = 1;
   q.push(make_pair(x,y));
   while(!q.empty()){
     int ff = q.front().first;
     int ss = q.front().second;
     for(int i = 0 ; i< 4 ; i++){
        int m = ff+fx[i];
        int n = ss+fy[i];
        if(!vis[m][n] && m >= 0 && ch[m][n] != '#' && ch[m][n] != 'm' && m < r && n >= 0 && n < c){
           vis[m][n]=1;
           level[m][n] = level[ff][ss]+1;
           if(m == hx && n == hy) return level[m][n];
           q.push(make_pair(m,n));
        }
     }
     q.pop();
   }
}
int main()
{
  cin >> test;
  while(test--){
       cin >> r >> c;
       for(int i = 0 ; i< r ; i++){
          for(int j = 0 ; j< c ; j++){
             cin >> ch[i][j];
             if(ch[i][j] == 'h'){
               hx = i;
               hy = j;
             }
             if(ch[i][j] == 'a' || ch[i][j] == 'b' || ch[i][j] == 'c')
               v.push_back(make_pair(i,j));
          }
       }
       int temp = -1;
       for(int i = 0 ; i< v.size() ; i++){
         memset(vis,0,sizeof(vis));
         memset(level,0,sizeof(level));
         temp = max(temp,bfs(v[i].first , v[i].second));
       }
       v.clear();
       printf("Case %d: %d\n",cs++ , temp);
  }

}

