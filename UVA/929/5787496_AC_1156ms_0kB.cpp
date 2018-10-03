#include <bits/stdc++.h>
using namespace std;
#define inf 1e7;
#define BOUNDRY(i,j)         ((i>=0 && i < r) && (j>= 0 && j< c))
int r , c, dis[1000][1000];
int a[1000][1000];
bool done[1000][1000];
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
struct node{

int a , b , c;
node(int x, int y , int z){
   a = x;
   b = y;
   c = z;
}
};
struct comp{
     bool operator()(const node& x, const node& y){
        return ( x.a < y.a);
     }

};
void clr(void){
     for(int i = 0 ; i< r ; i++){
       for(int j = 0 ; j< c ; j++){
           dis[i][j] = inf;
       }
     }
}
void dijx(int x , int y){
  dis[x][y] = a[x][y];
  priority_queue <  node, vector < node> , comp  > q;
  q.push(node(-0,x,y));
  while(!q.empty()){
       int ff = q.top().b;
       int ss = q.top().c;
       int temp = q.top().a;
       q.pop();
       if(done[ff][ss] == 0){
           for(int i = 0 ; i< 4 ; i++){
              int m = ff+fx[i];
              int n = ss+fy[i];
              if(BOUNDRY(m,n) && dis[ff][ss] + a[m][n] < dis[m][n] ){
              //   cout << ff << ' ' << ss << ' ' << m << ' ' << n << ' ' << dis[m][n] << ' ' << temp << endl;
                 dis[m][n] = dis[ff][ss] + a[m][n] ;
                 q.push(node(-dis[m][n],m,n));
               //  cout << q.top().a << ' ' << dis[m][n] << endl;
              }

           }
        }

        done[ff][ss] = 1;

  }
}
int main()
{
 // freopen("a.txt", "w" , stdout);
  int test;
  cin >> test;
  while(test--){
    cin >> r >> c;
    for(int i = 0 ; i< r ; i++){
       for(int j = 0 ; j< c ; j++){
          cin >> a[i][j];
       }
    }
    clr();
    memset(done, 0 , sizeof(done));
    dijx(0,0);
 /*   for(int i = 0 ; i< r ; i++){
       for(int j = 0 ; j< c ; j++){
         cout << dis[i][j] << ' ';
       }
       cout << "\n";
    }  */

    cout << dis[r-1][c-1] << endl;
  }
}
