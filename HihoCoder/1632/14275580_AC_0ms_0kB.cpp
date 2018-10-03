#include <bits/stdc++.h>
using namespace  std;

#define N 100005
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define MP make_pair
#define PB push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define OUTBOUNDARY(x,y) (x < 0 || x >=n || y <0 || y >= n )
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

int fx[] = {0,1,1,-1};
int fy[] = {1,-1,0,1};

int dx[] = {1,1,0,-1};
int dy[] = {0,-1,1,1};
int px[] = {0,1,0,-1};
int py[] = {1,0,-1,0};
int main()
{
   int n;
   while(~(sca(n))){
       string s[101];
       std::vector< pii > v;
       for(int i = 0 ; i< n ; i++) cin >> s[i];
       int x = 0 , y = 0 , cur = 0;
       v.push_back(MP(x,y));

       for(int i =  0 ; i< n*n ; i++){

            if(cur == 0 || cur == 2){
              x += fx[cur];
              y += fy[cur];
              if(OUTBOUNDARY(x,y)){
//                 cout << x << '#' << y << endl;
                 x -= fx[cur];
                 y -= fy[cur];
                 x += dx[cur];
                 y += dy[cur];
              }


              v.push_back(MP(x,y));
//              cout << x << ' ' << y << ' ' << cur << ' ' << fx[cur] << ' ' << fy[cur] << endl;
//              cout << i << '#' << endl;
              cur++;
              cur%=4;
            }
            else{
//                cout << x << '#' << endl;
                while(!OUTBOUNDARY(x,y) && v.size() < n*n){

                    x += fx[cur];
                    y += fy[cur];
                    if(!OUTBOUNDARY(x,y)){
//                        cout << x << ' ' << y << endl;
                        v.push_back(MP(x,y));
                    }
                    else{
                        x -= fx[cur];
                        y -= fy[cur];
                        break;
                    }
                }
                cur++;
                cur %= 4;
            }

       }


//       for(int i = 0 ; i< n*n ; i++){
//          cout << s[v[i].ff][v[i].ss] << endl;
//       }

       x = 0 , y = 0, cur = 0;
       int cnt = 0;
       char res[105][105];
       bool vis[105][105] = {0};


       for(int i = n ; i > 0 ; i--){

            if(i == n){
                for(int j = 0 ; j< i ; j++){
                    res[x][y] = s[v[cnt].ff][v[cnt].ss];

                    cnt++;
                    x += px[cur];
                    y += py[cur];
                }
                x -= px[cur];
                y -= py[cur];
                cur++;
                cur %= 4;
            }
            else{
//               cout <<  x << ' ' << y << endl;
               for(int k = 0 ; k< 2 ; k++){
                  for(int j = 0 ; j< i ; j++){

//
                    x += px[cur];
                    y += py[cur];
                    if(!OUTBOUNDARY(x,y)){

                     res[x][y] = s[v[cnt].ff][v[cnt].ss];
                     cnt++;
                    }
                  }
//                  x -= px[cur];
//                  y -= py[cur];
                  cur++;
                  cur %= 4;
               }
            }
       }

//       cout << res[0][3] << endl;
       for(int i = 0 ; i< n ; i++){
           for(int j = 0 ; j< n ; j++){
              cout << res[i][j];
           }
           cout << endl;
       }
   }
}
