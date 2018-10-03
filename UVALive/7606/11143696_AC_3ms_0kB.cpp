#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
using namespace std;
#define pii pair < int , int>
#define vpp vector < pii >
#define ff first
#define ss second
#define N 3000005
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define ll long long
#define READ()  freopen("in.txt","r" , stdin);
#define scana(x) scanf("%d",&x);
#define scanaa(x,y) scanf("%d%d",&x,&y);
#define scanaaa(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define MEMO(arr)  memset(arr , 0 , sizeof arr);
#define MEM(arr)  memset(arr,-1,sizeof arr);
#define BOU(x,y)  (x >= 0 && x < n && y >= 0 && y < m)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
bool flag;
int fx[] = {0,0,1};
int fy[] = {1,-1,0};
int vis[1001][1001];
char ch[1001][1001];
int n , m;
void dfs(int x , int y){
     // cout << x << ' ' << y << endl;
	  vis[x][y] = 1;
	  if(x == n-1){
	  	 flag = 1;
	  	 return;
	  }
      for(int i = 0 ; i< 3 ; i++){
      	  int p = fx[i]+x;
      	  int q = fy[i]+y;
      	 // cout << x << ' '<<  y << ' ' << p << ' ' << q << ' ' << BOU(p,q) << endl;
      	  if(BOU(p,q) && vis[p][q] == 0 && ch[p][q] == '0'){
      	  	 dfs(p,q);
      	  }
      }
}
int main()
{
//       READ();

       ios_base::sync_with_stdio(0); cin.tie(0);

       while(cin >> n >> m){

               F(i,n)
                  F(j,m)
                    cin >> ch[i][j];
               bool f = 0;
               MEMO(vis);
               for(int i = 0 ; i < m ; i++){
                  flag = 0;
                  if(ch[0][i] == '0')
                    dfs(0,i);
                  if(flag){
                    cout << "YES" << endl;
                    f = 1;
                    break;
                  }
               }
               if(!f) cout << "NO" << endl;
       }

}
