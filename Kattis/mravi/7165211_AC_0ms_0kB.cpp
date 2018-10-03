#include <bits/stdc++.h>
using namespace std;
#define NN 1000
#define inf  1e9
int leaf[NN];
int vis[NN];
struct nnn{
   int aa , bb , cc;
   nnn(int a , int b , int c){
      aa = a;
      bb = b;
      cc = c;
 
   }
};
vector < nnn > adj[NN];
double dfs(int u){
   vis[u] = 1;
   double mmax = -inf;
   if(adj[u].size() == 0){
    return (double) (leaf[u]);
   }
   for(int i = 0 ; i< adj[u].size() ; i++){
        int va = adj[u][i].aa;
        int vb = adj[u][i].bb;
        int vc = adj[u][i].cc;
        if(!vis[va]){
            double b = dfs(va);
            if(vc == 1){
                b = sqrt(b);
                b = (b*100)/vb;
            }
            else{
                b = (b*100)/vb;
            }
//            cout << u << ' ' << va << ' ' << ' ' << b <<  ' ' << mmax << endl;
            if(b > mmax){
                mmax = b;
            }
        }
   }
//   cout << u << ' ' << mmax << endl;
   return mmax;
}
int main()
{
       int node ;
       cin >> node;
       for(int i = 0  ; i < node - 1 ; i++){
          int a , b , c , d;
          scanf("%d%d%d%d", &a , &b , &c , &d);
          adj[a].push_back(nnn(b,c,d));
       }
       for(int i = 1 ; i<= node ; i++){
          scanf("%d",&leaf[i]);
       }
       double ans = dfs(1);
       printf("%0.6lf\n" ,ans);
}