#include <bits/stdc++.h>
using namespace std;
#define inf 1e7
int d, vis[210], level[210];
map < int , vector < pair<int,int> > > g;

class data{
public :
int a , b , c;
data(int a, int b ,  int c){
 this -> a = a;
 this -> b = b;
 this -> c = c;
}
};


class comp{
  public :
     bool operator()(const data& x ,const data& y){
       if(x.c < y.c) return true;
       else return false;
     }

};

class DSU{
 int parent[105], rank[105],sz = 105;
 public:
       DSU(){
            memset(rank,0,sizeof(rank));
            for(int i = 0 ; i< sz ; i++)
               parent[i] = i;
       }
    bool makeUnion(int a , int b){
       int parA = dsuFind(a);
       int parB = dsuFind(b);
       if(parA ==  parB) return 0;
       else{
           if(rank[parA] >= rank[parB]) swap(parA,parB);
           parent[parA] = parB;  // rank of parB is greater than parA
           if(rank[parA] == rank[parB]) rank[parB]++;   // increasing rank of parB( with whom connect anoter child)
           return 1;
       }
    }
    int dsuFind(int a){
        if(parent[a] == a) return a;
        return parent[a] = dsuFind(parent[a]);

    }

};

void dfs(int u){
 vis[u] = 1;
 for(int i = 0 ; i< g[u].size() ; i++){
    int v = g[u][i].first;
    int cost = g[u][i].second;
    if(!vis[v]){
       level[v] = min(level[u],cost);
       dfs(v);
    }

 }

}
int main()
{
  int node , edge, counter,cs = 1;
  map < string , int > hit;
  while(cin >> node >> edge && node && edge){
         hit.clear();
         counter = 0;
         g.clear();
         priority_queue < data , vector < data > , comp > q;
         for(int i = 0 ; i< edge ; i++){
             string a , b;
             int c;
             cin >> a >> b >> c;
             if(hit[a] == 0){
               counter++;
               hit[a] = counter;
             }
             if(hit[b] == 0){
               counter++;
               hit[b] = counter;
             }
             int m = hit[a];
             int n = hit[b];
             q.push(data(m,n,c));
         }
         DSU temp;
         while(!q.empty()){
            int x = q.top().a;
            int y = q.top().b;
            int z = q.top().c;
            q.pop();
            if(temp.makeUnion(x,y)){
               g[x].push_back(make_pair(y,z));
               g[y].push_back(make_pair(x,z));
            }

         }
         string a  , b;
         cin >> a >> b;
         int s = hit[a];
         d = hit[b];
         level[s] = inf;
         dfs(s);
         printf("Scenario #%d\n",cs++);
         printf("%d tons\n\n",level[d]);
         memset(level,0,sizeof(level));
         memset(vis,0,sizeof(vis));

  }

}

