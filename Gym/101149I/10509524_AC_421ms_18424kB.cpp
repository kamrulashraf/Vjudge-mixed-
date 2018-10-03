#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n   , m;
   scanf("%d %d",&n,&m);
   map < int ,std::vector< int > > adj;
   for(int i = 0 ; i< m ; i++){
            int u , v;
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
   }

   int mmin = 1e9;
   std::vector< int > v1;
   for(int i = 1 ; i<= n ; i++){
      if(adj[i].size() < mmin){
//                cout << i << ' ' << adj[i].size() << endl;

          mmin = adj[i].size();
          v1.clear();
          v1.push_back(i);
          for(auto x : adj[i]){
              v1.push_back(x);
          }
      }
   }
   map < int ,int> mark;
   for(int i = 1 ; i<= n ; i++)
     mark[i] = 1;
   for(auto x : v1){
      mark[x] = 0;
   }
   for(int i = 1 ; i<= n ; i++){
       if(i>1) printf(" ");
       printf("%d",mark[i]);
   }
 }
