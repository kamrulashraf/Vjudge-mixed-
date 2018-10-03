#include <bits/stdc++.h>
using namespace std;
int r , c , counter;
char ch[270][270];
bool vis[270][270];
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};

int dfs(int x , int y){
   if(ch[x][y] == 'W') counter++;
 //  cout << x << ' ' << y << ' ' << ch[x][y] << endl;
   vis[x][y] = 1;
   for(int i = 0 ; i< 8 ; i++){
     int p = x+fx[i];
     int q = y+fy[i];
     if(vis[p][q] == 0 && ch[p][q] == 'W' && p > 0 && p <= r && q >= 0 && q <= c){
         dfs(p,q);
     }

   }
return counter;
}
int main()
{
 // freopen("a.txt", "w" , stdout);
  int test, ar[50], cs = 0;
  cin >> test;
  getchar();
  getchar();
  while(test--){
    r = 0  ; c = 0;
    if(cs) cout << "\n";
    cs++;
    memset(vis,0,sizeof(vis));
    string s;
    while(1){
      getline(cin,s);
      if(s.empty()) break;
      if(s[0] == 'L' || s[0] == 'W'){
          r++;
          c = s.size() ;
          for(int i = 0 ; i< s.size() ; i++)
             ch[r][i+1] = s[i];
      }
      else{
         stringstream ss(s);
         int k = 0;
         while(ss >> ar[k]) k++;
         counter = 0;
         memset(vis,0,sizeof(vis));
         cout<< dfs(ar[0],ar[1]) << endl;
      }

    }
  }
}