#include <bits/stdc++.h>
using namespace std;
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
int r , c ,query;
int dp[501][501];
bool vis[501][501];
char ch[501][501];
int counter;

void bfs(int x , int y){
vis[x][y] = 1;
queue < pair <int , int> > temp, q;
q.push(make_pair(x,y));
temp.push(make_pair(x,y));
if(ch[x][y] == 'C') counter++;
    while(!q.empty()){
        int ff = q.front().first;
        int ss = q.front().second;
        for(int i = 0 ; i<4 ; i++){
           int m = ff+fx[i];
           int n = ss+fy[i];
           if(!vis[m][n] && m>=0 && m < r && n >= 0  && n < c && ch[m][n] != '#'){
              if(ch[m][n] == 'C') counter++;
              vis[m][n] = 1;
              q.push(make_pair(m,n));
              temp.push(make_pair(m,n));
           }

        }
       q.pop();
    }

    while(!temp.empty()){
       int ff = temp.front().first;
       int ss = temp.front().second;
     //  cout << ff << ' ' << ss << ' ' << counter << endl;
       dp[ff][ss] = counter;
       temp.pop();

    }

   // cout << "************" << endl;
}
int main()
{
  int test , cs = 1;
  cin >> test;
  while(test--){
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
    cin >> r >> c >> query;
    for(int i = 0 ; i< r ; i++){
       for(int j = 0 ; j<c ; j++){
             cin >> ch[i][j];
       }
    }
    for(int i = 0 ; i< r ; i++){
      for(int j = 0 ; j< c ; j++){
         counter = 0;
         if(ch[i][j] == 'C' || ch[i][j] == '.'){
            if(vis[i][j] == 0){
               bfs(i,j);
            }
         }

      }
    }
    printf("Case %d:\n",cs++);
    for(int i = 0 ; i< query ; i++){
       int a , b;
       cin >> a >> b;
       cout << dp[a-1][b-1] << endl;
    }


  }
}
