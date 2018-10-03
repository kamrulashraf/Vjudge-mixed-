#include <bits/stdc++.h>
#define BOUNDRY(i,j)  ((i>=0 && i < r) && (j>= 0 && j< c))
using namespace std;
int r,c;
char ch[15][15];
bool vis[15][15];
int level[15][15];
string s;
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
map < char , vector < pair < int,int> > > g;
int bfs(int x , int y , char temp){
    vis[x][y] = 1;
    queue < pair <int,int> > q;
    q.push(make_pair(x,y));
    while(!q.empty()){
       int ff = q.front().first;
       int ss = q.front().second;
       for(int i = 0 ; i < 4 ; i++){
             int m = ff+fx[i];
             int n = ss+fy[i];
             if(!vis[m][n] && BOUNDRY(m,n) && (ch[m][n] =='.' || ch[m][n] <= temp && ch[m][n] >= 'A')){
                vis[m][n] = 1;
                q.push(make_pair(m,n));
                level[m][n] = level[ff][ss]+1;
                if(ch[m][n]==temp){
                    while(!q.empty()) q.pop();
                    return level[m][n];
                }
             }
       }
     q.pop();
    }
 return -1;
}


int main()
{
    int test , cs = 1, sx , sy,n,p,q;
    cin >> test;
    while(test--){
         s.clear();
         int mmax = 0;
         memset(vis,0,sizeof(vis));
         memset(level,0,sizeof(level));
         g.clear();
         cin >> n;
         r = n ; c = n;
         for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< n ; j++){
               cin >> ch[i][j];
               if(isalpha(ch[i][j])){
                  s.push_back(ch[i][j]);
                  g[ch[i][j]].push_back(make_pair(i,j));
               }
            }
         }
         sort(s.begin() , s.end());
         int flag = 0, temp = 0;
         for(int i = 0 ; i< s.size()-1 ; i++){
             sx = g[s[i]][0].first;
             sy = g[s[i]][0].second;
             memset(vis,0,sizeof(vis));
             temp = bfs(sx,sy, s[i+1]);
             if(temp == -1){
                flag = 1;
                break;
             }
         }
         if(flag == 1){
             printf("Case %d: Impossible\n",cs++);
         }
         else printf("Case %d: %d\n",cs++ , temp);

    }


}

