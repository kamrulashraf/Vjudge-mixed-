#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
using namespace std;
#define pii pair < int , int>
#define vpp vector < pii >
#define ff first
#define ss second
#define N 550
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define ll long long
#define READ()  freopen("in.txt","r" , stdin)
#define sca(x) scanf("%d",&x)
#define scaa(x,y) scanf("%d%d",&x,&y)
#define scaaa(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define MEMO(arr)  memset(arr , 0 , sizeof arr)
#define MEM(arr)  memset(arr,-1,sizeof arr)
#define inf 1e9
#define write() freopen("out.txt", "w" , stdout)
#define read() freopen("in.txt" , "r", stdin)
typedef int T;
struct Edge
{
    int u , v;
    T flow , cap;
    Edge(int u , int v , T f , T c): u(u),v(v),flow(f),cap(c){}
};

struct maxFlow
{
    int s,t, dis[N],cur[N];
    bool vis[N];
    std::vector<Edge> edge;
    vector < int > adj[N];

    void addEdge(int u ,int v , int cap){
       edge.push_back(Edge(u,v,0,cap));
       edge.push_back(Edge(v,u,0,cap));
       int sz = edge.size();
       adj[u].push_back(sz-2);
       adj[v].push_back(sz-1);
    }

    void init(){
       for(int i = 0 ; i< N ; i++) adj[i].clear();
       edge.clear();
    }

    bool bfs(){
        memset(vis,0,sizeof vis);
        dis[s] = 0 , vis[s] = 1;
        queue < int > q;
        q.push(s);

        while(!q.empty()){
            int x = q.front();

            q.pop();
            for(int i = 0 ; i< adj[x].size() ; i++){
                Edge &e = edge[adj[x][i]];
//                cout << adj[x][i] << '@' <<  endl;
                if(!vis[e.v] && e.cap>e.flow){
                    vis[e.v] = 1;
                    dis[e.v] = dis[x]+1;
                    q.push(e.v);
                }
            }
        }
//        cout << vis[t] << endl;
        return vis[t];
    }



    T dfs(int x , T minF){
        if(x==t || minF==0) return minF;
        T ret = 0 , f = 0;
        for(int &i = cur[x] ; i< adj[x].size() ; i++){
            Edge &e = edge[adj[x][i]];
            if(dis[x]+1 == dis[e.v] && (f= dfs(e.v,min(minF,e.cap-e.flow)))>0){
               e.flow += f;
               edge[adj[x][i]^1].flow -= f;
               ret += f;
               minF -= f;
               if(minF <= 0) break;
            }
        }
        return ret;
    }

    T dinic(int s , int t){
        this-> s = s;
        this-> t = t;
        T ret = 0;

        while(bfs()){
            while(1){
               memset(cur,0,sizeof cur);
               T f = dfs(s,inf);

               if(f == 0) break;
               ret += f;
            }
        }
        return ret;
    }

};
int main()
{
    // read();
    int test , cs = 1;
    sca(test);
    while(test--){
         int p , s , c , m;
         scaaa(p,s,c);
         sca(m);

         maxFlow var;
         var.init();

         var.s = 0;
         var.t = 545;

         for(int i = 0 ; i< m ; i++){
             int a ,b;
             scaa(a,b);
             var.addEdge(a, p+b, 1);
         }

         for(int i = 1 ; i<= p ; i++){
             var.addEdge(0, i, 1);

//             cout << i << '#' <<  endl;
         }


         for(int i = p+1 ; i<= p+s ; i++){
             var.addEdge(i, 545, c);
//             cout << i << '*' <<  endl;
         }
         int res = var.dinic(0, 545);
         printf("%d\n",res);
    }
    return 0;
}
