#include <bits/stdc++.h>
using namespace std;
#define N 100005
int color[N], vis[N];
set  < int > s;
map < int , set<int> > c, res;
map < int , vector < int > > adj;
int main()
{
    int   n , m ;
    cin >> n >> m;
    for(int i = 1 ; i<= n  ; i++){
        int temp ;
        cin >> color[i];
        s.insert(color[i]);
        c[color[i]].insert(i);
    }
    for(int i = 0 ; i < m ; i++){
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(auto x : s){
        for(auto u : c[x]){ // u = node
             // cout << u << '*' << endl;;
             for(auto v : adj[u]){
                  // cout << v << ' ';
                  if(color[v] != x){
                     res[x].insert(color[v]);
                  }
             }
             // cout << endl;

        }
    }
    // cout << endl;
    int mmax= 0;
    for(auto x : s){
        int temp = res[x].size();
        mmax = max(mmax,temp);
    }
    for(auto x : s){
        if(res[x].size() == mmax){
           cout << x << endl;
           break;
        }
    }
    return 0;
}
