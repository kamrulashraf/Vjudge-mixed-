#include <bits/stdc++.h>
using namespace std;
#define NN 1000
int match[NN] , vis[NN];
std::vector< int > adj[NN];
double arrx[NN] , arry[NN], holex[NN] , holey[NN];
double distance(double a , double b , double c , double d){
      return (double) ( (a-c)*(a-c)+ (b-d)*(b-d) );
}

int bipartite(int u){
    if(vis[u]) return 0;
    vis[u] = 1;
    for(int i = 0 ; i< adj[u].size() ; i++){
        int v = adj[u][i];
        if(match[v] == -1 || bipartite(match[v])){
            match[v] = u;
            return 1;
        }
    }
    return 0;
}
int main()
{
   int n , m  , time , v;
   while(cin >> n >> m >> time >> v){
           time *= time;
       v *= v;
       for(int i = 0 ; i< n  ; i++){
         cin >> arrx[i] >> arry[i];
       }

       for(int i = 0 ; i< m ; i++){
          cin >> holex[i] >> holey[i];
       }

       for(int i = 0 ; i< n ; i++){
          for(int j = 0 ; j < m ; j++){
              double dist = distance(arrx[i] , arry[i] , holex[j] , holey[j]);
              double tt = dist/ v;
              // cout << i << ' ' << j << ' ' << tt << endl;
              if(tt - time < .0000001){
                 adj[i].push_back(j);
                 // cout << i << ' ' <<  j << ' ' << tt <<  endl;
              }
          }
       }

       memset(match , -1 , sizeof match);
       int res = 0;
       for(int i = 0 ; i< n ; i++){
         memset(vis,0,sizeof vis);
         res += bipartite(i);
       }
       cout << n - res << endl;
       for(int i = 0 ; i< n ; i++)
            adj[i].clear();
   }
return 0;
}