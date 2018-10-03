#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
using namespace std;
#define pii pair < int , int>
#define vpp vector < pii >
#define ff first
#define ss second
#define N 105
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

const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

int a[N];
map < int , int > vis;
map < int ,vector < int > > adj;

void dfs(int u){
  vis[u] = 1;
  for(auto x : adj[u]){
      if(!vis[x]) dfs(x);
  }
}
int main()
{

       int test , cs = 1, n , k;
       scana(test);
       while(test--){
          scanaa(n,k);
          rep(i,0,n){
             scana(a[i]);
          }

          sort(a,a+n);
          for(int i = 0 ; i< n - 1; i++){

              int j = i+1;
              if(a[i]+k >= a[j]){
                 adj[i].push_back(j);
                 adj[j].PB(i);
              }
          }

          int counter = 0;
          vis.clear();
          for(int i = 0 ; i< n ; i++){
              if(vis[i] == 0){
                 dfs(i);
                 counter++;
              }
          }
          printf("Case #%d: %d\n",cs++ , counter);
          adj.clear();
       }
}
