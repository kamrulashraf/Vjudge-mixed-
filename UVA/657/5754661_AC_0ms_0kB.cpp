#include <bits/stdc++.h>
using namespace std;
#define X(i)  ff+fx[i]
#define Y(i)  ss+fy[i]
int fx[] = {0,1,0,-1};
int fy[] = {1,0,-1,0};
int counter = 0, flag = 1;
char ch[55][55];
bool vis[55][55];
bool color[55][55];
  int r , c, cs = 1;
void call(int x , int y);
int bfs(int x , int y){
   queue < pair <int , int > > q;
   vis[x][y] = 1;
   q.push(make_pair(x,y));
   while(!q.empty()){
      int ff = q.front().first;
      int ss = q.front().second;
      if(ch[ff][ss] == 'X'){
       //   cout << ff << ' ' << ss << ' ' <<  color[ff][ss] <<  endl;
          if(color[ff][ss] == 0) counter++;
          call(ff,ss);
      }
      for(int i = 0 ; i< 4 ; i++){
           if(vis[X(i)][Y(i)] == 0 && (ch[X(i)][Y(i)]  == 'X' || ch[X(i)][Y(i)] == '*') && X(i) >= 0 && X(i) < r && Y(i) >= 0 && Y(i) < c){
               vis[X(i)][Y(i)] = 1;
            //   cout << X(i) << ' ' << Y(i) << endl;
               q.push(make_pair(X(i),Y(i)));
           }
      }
      q.pop();
   }
 return counter;
}
void call(int x , int y){
color[x][y] = 1;
for(int i = 0 ; i< 4 ; i++){
    int p = x+fx[i];
    int q = y+fy[i];
    if(color[p][q] == 0 && (ch[p][q]  == 'X') && p >= 0 && p < r && q >= 0 && q < c){
     //   cout << x << ' ' << y << ' ' << fx[i] << ' ' <<  fy[i] <<  endl;
        color[p][q] = 1;
        call(p,q);
    }
}


}
int main()
{
//  freopen("a.txt" , "w" , stdout);
  vector <int> v;
  while(cin >> c >> r && r && c){
     memset(vis,0,sizeof(vis));
     memset(ch ,0,sizeof(ch));
     memset(color,0,sizeof(color));
     for(int i = 0 ; i < r ; i++){
       for(int j = 0 ; j < c ; j++)
          cin >> ch[i][j];

     }

     for(int i = 0 ; i< r ; i++){
       for(int j = 0 ; j< c ; j++){
            if((ch[i][j] == '*' || ch[i][j] == 'X' ) && vis[i][j] == 0){
                counter = 0;
                v.push_back(bfs(i , j));
            }

       }
     }
     sort(v.begin() , v.end());
     printf("Throw %d\n", cs++);
     for(int i = 0 ; i< v.size() ; i++){
        if(i) printf(" ");
        cout << v[i];
     }
     v.clear();
     cout << "\n\n";
  }
return 0;
}
