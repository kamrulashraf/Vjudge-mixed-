#include <bits/stdc++.h>
using namespace std;
map < string , vector < string > > g;
map < string ,int > indeg, vis;
vector < string > ans;
int main()
{
   int node ,edge, cs = 1;
   while(cin >> node){
     string s[105];
     for(int i = 0 ; i< node ; i++){
        cin >> s[i];
     }

     cin >> edge;
     for(int i = 0 ; i< edge ; i++){
        string a , b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
     }
     int counter = 0;
     while(counter < node){
            for(int i = 0 ; i< node ; i++){
              if(indeg[s[i]] == 0 && vis[s[i]] == 0){
                 vis[s[i]] = 1;
                 counter++;
                 ans.push_back(s[i]);
                 for(int j = 0 ; j< g[s[i]].size() ; j++){
                    string v = g[s[i]][j];
                    indeg[v]--;
                 }
                 break;
              }

            }
     }

     printf("Case #%d: Dilbert should drink beverages in this order:",cs++);
     for(int i  = 0 ; i< ans.size() ; i++){
        cout << ' ' << ans[i];
     }
     cout << ".\n\n";
     ans.clear();
     g.clear();
     vis.clear();
     indeg.clear();
   }
}
