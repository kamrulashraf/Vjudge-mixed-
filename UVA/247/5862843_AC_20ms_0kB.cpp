#include <bits/stdc++.h>
using namespace std;
#define white   0
#define black   5
#define grey    1
map < string , vector < string > > g;
vector < string > slist;
map < string, int > vis, num , low, hit;
stack < string > st;
int counter;
void dfs(string u){
   vis[u] = grey;
   num[u] = low[u] = counter++;
   st.push(u);
   for(int i = 0 ; i< g[u].size() ; i++){
      string v = g[u][i];
      if(vis[v] == white){
         dfs(v);
         low[u] = min(low[u],low[v]);
      }
      if(vis[v] == grey){
         low[u] = min(low[u],low[v]);
      }
   }
   int space =0;
   if(low[u] == num[u]){
      while(1){
        string temp = st.top();
        st.pop();
        vis[temp] = black;
        if(space) printf(", ");
        cout << temp;
        if(temp == u){
           cout <<"\n";
           break;
        }
        space++;
      }
   }
}
int main()
{
 //  freopen("a.txt","w",stdout);
   int node , edge,cs = 0;
   while(cin >> node >> edge){
      if(!node && !edge) break;
      vis.clear();
      hit.clear();
      g.clear();
      low.clear();
      num.clear();
      slist.clear();
      while(!st.empty()) st.pop();
      string a , b;
      for(int i = 0 ; i< edge ; i++){
          cin >> a >> b;
          if(hit[a] == 0)
             slist.push_back(a);
          if(hit[b] == 0)
            slist.push_back(b);
          hit[a] = 1;
          hit[b] = 1;
          g[a].push_back(b);
      }
       counter = 0;
       if(cs) cout <<"\n";
       printf("Calling circles for data set %d:\n",++cs);
       for(int i = 0 ; i< slist.size() ; i++){
       //   counter = 0;
          if(!vis[slist[i]])
             dfs(slist[i]);
       }
    }
}


