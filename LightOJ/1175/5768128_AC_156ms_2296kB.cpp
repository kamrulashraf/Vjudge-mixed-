#include <bits/stdc++.h>
using namespace std;
#define BOUNDRY(i,j)         ((i>=0 && i < r) && (j>= 0 && j< c))

int r , c, counter;
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
char ch[205][205];
bool vis[210][210];
bool ppp[210][210];
int level[210][210];
int level1[210][210];
queue < pair <int,int> > v;

void bfs(){

  while(!v.empty()){
     int ff = v.front().first;
     int ss = v.front().second;
     v.pop();
     for(int i = 0 ; i<4 ; i++){
         int m = ff+fx[i];
         int n = ss+fy[i];
         if(!ppp[m][n] && BOUNDRY(m,n) && ch[m][n] != '#'){
              ppp[m][n] = 1;
              level[m][n] = level[ff][ss]+1;
              v.push(make_pair(m,n));

         }
     }
  }
}

int bfs(int x , int y){
   vis[x][y] = 1;
   queue < pair <int,int> > q;
   q.push(make_pair(x,y));
   while(!q.empty()){
     int ff = q.front().first;
     int ss = q.front().second;
     q.pop();
     for(int i = 0 ; i< 4 ; i++){
         int m = ff+fx[i];
         int n = ss+fy[i];
         if(m>= r || m < 0 || n < 0 || n >= c)
            return level1[ff][ss]+1;
         if(!vis[m][n] && BOUNDRY(m,n) && ch[m][n]!= '#' && ((level1[ff][ss]+1)< level[m][n] || ppp[m][n] == 0)){
             vis[m][n] = 1;
          //   cout << m << ' ' << n << endl;
             level1[m][n] = level1[ff][ss]+1;
             q.push(make_pair(m,n));
         }
     }
   }
  return -1;
}
int main()
{
 int test , cs = 1,jx,jy;
 scanf("%d", &test);
 while(test--){
      cin >> r >> c;
      for(int i = 0 ; i< r ; i++){
         for(int j = 0 ; j < c ; j++){
            cin >> ch[i][j];
            if(ch[i][j] == 'J'){
               jx = i;
               jy = j;
            }
            if(ch[i][j]=='F'){
               ppp[i][j] = 1;
               v.push(make_pair(i,j));
            }
         }
      }
     // cout << v.size() << endl;
      counter = 1;
      bfs();
      int temp= bfs(jx,jy);

      if(temp == -1) printf("Case %d: IMPOSSIBLE\n",cs++);
      else printf("Case %d: %d\n",cs++ , temp);
      memset(vis,0,sizeof(vis));
      memset(ppp,0,sizeof(ppp));
      memset(level,0,sizeof(level));
      memset(level1,0,sizeof(level1));
 }
return 0;
}
