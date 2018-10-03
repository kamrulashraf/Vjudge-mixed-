#include <bits/stdc++.h>
using namespace std;
map < int , vector <int> > g;
map <int, int> vis, hit;
int bfs(int s , int ttl){
  int counter = 1;
  queue < pair <int, int>  > q;
  q.push( make_pair(s,0));
  vis[s] = 1;
  while(!q.empty()){
     int ff = q.front().first;
     int ss = q.front().second;
     for(int i = 0 ; i< g[ff].size() ; i++){
        int vff = g[ff][i];
        int vss = ss+1;
        if(!vis[vff] && vss <= ttl){
        //   cout << vff << ' ' << vss << ' ' << ttl << endl;
           vis[vff] = 1;
           counter++;
           q.push(make_pair(vff,vss));
        }

     }
     q.pop();
  }
return counter;

}
int main()
{
  // freopen("a.txt", "w", stdout);
   int test, cs = 1;
   while(cin >> test && test){
       vector <int> node;
       for(int i = 0 ; i< test ; i++){
          int a, b;
          cin >> a >> b;
          if(hit[a] == 0)
             node.push_back(a);
          hit[a] = 1;
          if(hit[b] == 0)
             node.push_back(b);
          hit[b] = 1;
          g[a].push_back(b);
          g[b].push_back(a);

       }
       int a, b;
       while(cin >> a >> b){
          if(a==0 && b==0) break;
          bfs(a,b);
          int counter = 0;
          for(int i = 0 ; i< node.size() ; i++){
             if(vis[node[i]] == 0)
               counter++;
          }
          vis.clear();
          printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cs++ , counter , a , b);
       }
      vis.clear();
      g.clear();
      hit.clear();
      node.clear();
   }


}
