
#include <bits/stdc++.h>
using namespace  std;

#define N 260
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
#define write() freopen("out.txt", "w" , stdout)
#define read() freopen("in.txt" , "r", stdin)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

const int MAX=10100;
int que[MAX];
template <class T>
struct Edge {
   int to, next;
   T cap, flow;
   Edge(int to, int next, T cap) {
      this->to = to;
      this->next = next;
      this->cap = cap;
      this->flow = 0;
   }
};
template <class T>
struct Dinic {
   T INF;
   const int nodes;
   int source, sink, lvl[MAX], nodeEnd[MAX], last[MAX];
   vector < Edge <T> > edgeList;

   Dinic(int n) : nodes(n), INF(numeric_limits<T>::max() / 4) { fill(nodeEnd, nodeEnd+n, -1); }
   void addEdge(int u, int v, T cap = 1) {
      edgeList.push_back(Edge<T> (v, nodeEnd[u], cap));
      nodeEnd[u] = (int)edgeList.size()-1;
      edgeList.push_back(Edge<T> (u, nodeEnd[v], 0));
      nodeEnd[v] = (int)edgeList.size()-1;
   }

   // bfs
   bool createLevel() {
      memset(lvl, -1, nodes * sizeof(int));
      int qs = 0, qt = 0;
      que[qs] = source, lvl[source] = 0;

      while(qs <= qt) {
         int nd = que[qs++], ch;
         for(int i = nodeEnd[nd]; i != -1; i = edgeList[i].next)
            if(lvl[ch = edgeList[i].to] == -1 && edgeList[i].cap > edgeList[i].flow)
               lvl[ch] = lvl[nd] + 1, que[++qt] = ch;
      }

      return lvl[sink] != -1;
   }

   // dfs
   T blockingFlow(int nd, T flow) {
      if(nd == sink) return flow;
      int ch;
      T pflow = flow;

      for(int &i = last[nd]; i != -1; i = edgeList[i].next) if(lvl[ch = edgeList[i].to] == lvl[nd]+1) {
         T pushed = blockingFlow(ch, min(pflow, edgeList[i].cap - edgeList[i].flow));
         pflow -= pushed;
         edgeList[i].flow += pushed;
         edgeList[i ^ 1].flow -= pushed;
         if(!pflow) break;
      }

      return flow - pflow;
   }

   T maxFlow(int src, int snk) {
      //REP(i, edgeList.size()) edgeList[i].flow = 0;
      source = src, sink = snk;
      T tot = 0;

      while(createLevel()) {
         memcpy(last, nodeEnd, nodes * sizeof(int));
         tot += blockingFlow(source, INF);
      }

      return tot;
   }
};

struct node
{
     int  h , a , f;
     node(int  x , int y , int z){
        h = x , a = y ; f = z;
     }
};

int main()
{
     int test,  cs = 1;
     sca(test);
     while(test--){
           int n , m;
           scaa(n , m);

           std::vector< node > fem , male;



           for(int i = 0 ; i< n ; i++){
              int a , b , c;
              scaaa(a,b,c);
              fem.push_back(node(a,b,c));
           }

           for(int i = 0 ; i< m ; i++){
              int a , b , c;
              scaaa(a,b,c);
              male.push_back(node(a,b,c));
           }


           Dinic< int > var(500);
           for(int i = 0 ; i< n ; i++){

               for(int j = 0 ; j < m ; j++){
                    if(abs(fem[i].h - male[j].h) <= 12 &&abs(fem[i].a - male[j].a) <= 5  && (fem[i].f^male[j].f) == 0){
                        var.addEdge(i, j+n);
//                        cout  << i << ' ' <<  j << endl;
                    }
               }
           }

           for(int i = 0 ; i < n ; i++){
              var.addEdge(202, i);
           }

           for(int i = 0 ; i< m ; i++)
             var.addEdge(i+n , 203);
           int res = var.maxFlow(202, 203);

           printf("Case %d: %d\n",cs++ , res);
     }
     return 0;
}
