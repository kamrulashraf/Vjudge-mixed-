#include <bits/stdc++.h>
using namespace std;
 map < int , vector < int > > g1;
 bool vis[205];
 int parent[205];
 double cost[205][205], level[205];
void dfs(int n){
  vis[n]=1;
  for(int i = 0 ; i< g1[n].size() ; i++){
     int v = g1[n][i];
     if(!vis[v]){
      level[v] = max(cost[n][v],level[n]);
      dfs(v);
     }
  }

}
class data{
  public:
  int a, b;
  float c;
  data(int a, int b , float c){
    this -> a = a;
    this -> b = b;
    this -> c = c;
  }

};
class comp{
public :
   bool operator()(const data& x, const data& y){
      if(x.c > y.c) return true;
      else return false;

   }

};
class DSU{
 int parent[200], rank[200],sz = 200;
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
vector < pair < int ,int> > g;
int main()
{
    int n,cs = 1;
    while(scanf("%d", &n) == 1 && n){
       memset(parent,-1,sizeof(parent));
       for(int i = 0 ; i< n ; i++){
          int a, b;
          cin >> a >> b;
          g.push_back(make_pair(a,b));
       }
       priority_queue < data , vector < data > , comp> q;
       for(int i = 0 ; i< n ; i++){
          for(int j = i+1 ; j< n ; j++){
                int a = g[i].first;
                int b = g[i].second;
                int c = g[j].first;
                int d = g[j].second;
                float temp = sqrt((a-c)*(a-c)+ (b-d)*(b-d));
                q.push(data(i,j,temp));
          }
       }

          DSU temp;
          g.clear();
          double sum = 0;
          while(!q.empty()){
             int a = q.top().a;
             int b = q.top().b;
             float c = q.top().c;
             if(temp.makeUnion(a,b)){
                 cost[a][b] = c;
                 cost[b][a] = c;
                // cout << a << ' ' << b << ' ' << c << endl;
                 g1[a].push_back(b);
                 g1[b].push_back(a);
             }
             q.pop();
          }
          level[0] = 0;
          dfs(0);
          printf("Scenario #%d\n",cs++);
          printf("Frog Distance = %.3lf\n\n", level[1]);
          g1.clear();
          memset(vis,0,sizeof(vis));
          memset(cost, 0.0,sizeof(cost));
          g.clear();

    }

}

