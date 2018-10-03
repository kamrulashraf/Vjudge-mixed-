#include <bits/stdc++.h>
using namespace std;
map < string , vector <string> > g;
map < string , int > vis;
#define grey                 1
#define black                2
bool cycle, flag;

vector < string > st;
void dfs(string u){
 vis[u] = grey;
 for(int i = 0 ; i< g[u].size() ; i++){
    string v = g[u][i];
    if(!vis[v]){
       dfs(v);
    }
    else if(vis[v] == grey){
       cycle = true;
    }
 }
 vis[u] = black;
// st.push_back(u);
}

int main()
{
  int test, cs = 1;
  cin >> test;
  while(test--){
        flag = 0;
        g.clear();
        st.clear();
        int edge;
        cin >> edge;
        set <string > s;
        set <string > :: iterator it;
        for(int i = 0 ; i< edge ; i++){
            string a , b;
            cin >> a >> b;
            s.insert(a);
            s.insert(b);
            g[a].push_back(b);
        }
        vis.clear();
        for(it = s.begin() ; it != s.end() ; it++){
            if(!vis[*it]){
               cycle = false;
               dfs(*it);
               if(cycle == true)
                 flag = 1;
            }
        }
        map < string,bool > mark;
    /*    reverse(st.begin() , st.end());
        for(int i =  0; i< st.size()-1 ; i++){
            mark[st[i]] = 1;
            if(mark[st[i+1]]){
                flag = 1;
                break;
            }
        } */
        if(flag == 0) printf("Case %d: Yes\n", cs++);
        else printf("Case %d: No\n", cs++);
  }

}
