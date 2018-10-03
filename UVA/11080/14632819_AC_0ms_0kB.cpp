#include <bits/stdc++.h>
using namespace  std;

#define N 250
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
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
int flag = 0;
int mark[3];
map < int , vector < int > > adj;
int vis[N], color[N];


void dfs(int u){
  vis[u]= 1;
  mark[color[u]]++;
  for(int i = 0 ; i< adj[u].size() ; i++){
     int v = adj[u][i];
     if(vis[v] == 0){
       color[v] = 1-color[u];
       dfs(v);
     }
     else{
        if(color[v] != 1-color[u]){
           flag = 1;
           return;
        }
     }
  }
}
int main()
{
  int test , cs = 1;
  sca(test);
  while(test--){
     int  n , m , a , b;
     memset(vis,0,sizeof vis);
     memset(color,0,sizeof color);
     adj.clear();
     scaa(n,m);
     F(i,m){ 
        scaa(a,b);
        adj[a].push_back(b);
        adj[b].push_back(a);
     }

     flag = 0;

     int cnt = 0;
     for(int i =  0 ; i< n ; i++){
         memset(mark , 0 , sizeof mark);
         if(vis[i] == 0){
            dfs(i);
            if(flag == 1){
               break;
             }
             int mmin = min(mark[0] , mark[1]);
             // cout << i << ' ' << mmin << ' ' << mark[0] << ' ' << mark[1] << endl;
             if(mmin == 0) cnt++;
             cnt += mmin;
             }

     }
     if(flag == 1){
       printf("-1\n");
     }
     else{
       printf("%d\n",cnt);
     }
  }
}