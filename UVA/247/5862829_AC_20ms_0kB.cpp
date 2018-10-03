#include <bits/stdc++.h>
using namespace std;
#define white   0
#define black   5
#define grey    1
int counter = 0;
map < string , vector < string > >  g;
map < string , int> vis , num  , low;
stack < string > st;
void dfs(string u){
        st.push(u);
        vis[u] = grey;
        num[u] = low[u] = counter++;
        for(int i = 0 ; i< g[u].size() ; i++){
            string v = g[u][i];
            if(vis[v] == white)
               dfs(v);
            if(vis[v] == grey)
               low[u] = min(low[v],low[u]);
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
//freopen("a.txt","w",stdout);
   int node , edge,cs = 0;
   while(cin >> node >> edge){
        set < string > s;
        set < string > :: iterator it;
        if(node == 0 && edge == 0) break;
        for(int i = 0 ; i< edge ; i++){
           string a  , b;
           cin >> a >> b;
           g[a].push_back(b);
           s.insert(a);
           s.insert(b);
        }
       if(cs) cout <<"\n";
       printf("Calling circles for data set %d:\n",++cs);
        for(it = s.begin() ; it != s.end() ; it++){
            if(!vis[*it]){
                dfs(*it);
            }
        }

        g.clear();
        vis.clear();
        low.clear();
        num.clear();
        s.clear();
   }
  return 0;
}
