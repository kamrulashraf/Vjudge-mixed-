#include <bits/stdc++.h>
using namespace std;
int arr[105], d[105];

map < int , vector < int > > adj;
int vis[1005];

void dfs(int u, int component){
    vis[u] = component;
    for(auto v : adj[u]){
        if(vis[v]==0){
           dfs(v,component);
        }
    }
}
int main()
{

   int n;
   cin >> n;
   for(int i = 1 ; i<= n ; i++){
       cin >> arr[i];
   }
   for(int i = 1 ; i<= n ; i++){
       cin >> d[i];
       int tempa = i+d[i];
       if(tempa <= n && tempa >= 1){
          // cout << i << ' ' << tempa << endl;
          adj[i].push_back(tempa);
          adj[tempa].push_back(i);
       }
       tempa = i-d[i];
       if(tempa <= n && tempa >= 1){
          adj[i].push_back(tempa);
                    // cout << i << ' ' << tempa << endl;

          adj[tempa].push_back(i);
       }
   }
   int component = 0;
   for(int i = 1 ; i<= n ; i++){
       if(!vis[i]){
          component++;
          dfs(i,component);
       }
   }

   for(int i = 1 ; i<= n ; i++){
       if(vis[i] != vis[arr[i]]){
          cout << "NO" << endl;
          return 0;
       }
   }
   cout << "YES" << endl;

}
