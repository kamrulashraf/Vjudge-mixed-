#include <bits/stdc++.h>
using namespace std;
 
#define NN 105
#define ll long long
#define inf 1e9
int s , t , f;
map < int , std::vector<int > > adjList;
int  parent[NN] ;
int resGraph[NN][NN];
    void argument(int v , int mmin){
       if(v == s){
         f = mmin;
         return;
       } else if(parent[v] != -1){
          argument(parent[v], min(mmin , resGraph[parent[v]][v]));
          resGraph[parent[v]][v] -= f;
          resGraph[v][parent[v]] += f;
       }
 
    }
    int edmondKarps(){
        int maxFlow = 0;
        while(1){
            f = 0;
            bool vis[NN];
            stack < int > q;
            q.push(s);
            memset(vis,0,sizeof vis);
            memset(parent , - 1 , sizeof(parent));
            while(!q.empty()){
               int u = q.top();
               q.pop();
               if(u == t) break;
               for(int i = 0 ; i< adjList[u].size() ; i++){
                  int v = adjList[u][i];
                  if(resGraph[u][v] > 0 && !vis[v]){
                      vis[v] = 1;
                      q.push(v);
                      parent[v] = u;
                  }
               }
            }
            argument(t , inf);
            if(f == 0) break; // can not sent more flow in this graph
            maxFlow += f;
        }
      return maxFlow;
    }
 
int main()
{

   // freopen("in.txt","r" ,stdin);
 
   int node , edge, cs = 1;
   int test;
   while(scanf("%d",&node)==1){
       if(node == 0) break;
       scanf("%d%d%d" ,&s , &t , &edge);
       memset(resGraph,0,sizeof resGraph);
       for(int i = 0 ; i< edge ; i++){
            int  a , b , c;
             scanf("%d%d%d",&a,&b,&c);
            resGraph[a][b] += c;
            resGraph[b][a] += c;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
       }
       int res  = edmondKarps();
       printf("Network %d\nThe bandwidth is %d.\n",cs++ ,res );
       printf("\n");
       adjList.clear();
 
   }
 
 
 
}