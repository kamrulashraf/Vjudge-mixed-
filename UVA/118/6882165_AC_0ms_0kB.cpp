// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI            2.0*acos(0.0)
#define pi            pair <int,int>
#define rep(i,x,y)      for(int i = x ; i < y ; i++)
#define X(i)        x+fx[i]
#define Y(i)        y+fy[i]
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
int mod = 4;
int main()
{
    int x, y, r , c, hit[260];
    char ch;
    hit['N'] = 0;
    hit['E'] = 1;
    hit['S'] = 2;
    hit['W'] = 3;
    char cop[ ] = {'N', 'E', 'S' , 'W', '\0'};
    map < int , map < int ,int> > mark;
    cin >> r >> c;
       while(cin >> x >> y >> ch){
          int flag = 0;
          int dir = hit[ch];
          string s;
          cin >> s;
          for(int i = 0 ; i< s.size() ; i++){
               if(s[i] == 'F'){
                 if(x+fx[dir] <= r  && x+fx[dir] >= 0 && y+fy[dir] <= c && y+fy[dir] >= 0){
                  x += fx[dir];
                  y += fy[dir];
                }
                else{
                   if(mark[x][y] == 0){
                      mark[x][y] = 1;
                      flag = 1;
                      break;
                   }
                }
               }
               if(s[i] == 'R'){
                  dir = (dir+1)%mod;
               }
               if(s[i] == 'L'){
                  dir = (dir-1)%mod;
                  if(dir < 0) dir += mod;
               }
          }
          cout << x << ' ' << y  << ' ' <<  cop[dir] ;
          if(flag) cout << " LOST";
          cout<< "\n";
       }
return 0;
}
