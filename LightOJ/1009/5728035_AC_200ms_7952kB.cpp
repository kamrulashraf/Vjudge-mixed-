#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define MEM(x) memset(x,0,sizeof(x))
vector <int> g[N],v;
int hit[N], vis[N],counter[5],a[N],b[N], color[N],cse = 1;
 
 
int bfs(int s)
{
    memset(counter ,0 , sizeof(counter));
    queue <int> q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty())
    {
        int u = q.front();
      //  cout << u << ' ' << color[u] << endl;
        counter[color[u]]++;
        q.pop();
        for(int i = 0 ; i< g[u].size() ; i++){
            int v = g[u][i];
            if(vis[v] == 0){
                vis[v] = 1;
                q.push(v);
                color[v] = 1-color[u];
            }
        }
    }
    return max(counter[0],counter[1]);
}
int main()
{
    int test , node ;
    cin >> test;
    while(test--){
        cin >> node ;
        for(int i = 0 ; i < node ; i++){
            scanf("%d %d", &a[i], &b[i]);
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
            if(hit[a[i]] == 0){
                    v.push_back(a[i]);
                    hit[a[i]] = 1;
            }
            if(hit[b[i]] == 0){
                    v.push_back(b[i]);
                    hit[b[i]] = 1;
            }
        }
        int ans = 0;
        for(int i = 0 ; i<v.size() ; i++)
        {
            if(vis[v[i]] == 0){
              ans += bfs(v[i]);
            }
        }
     //   for(int i = 0 ; i< v.size() ; i++) cout << i << ' ' <<  color[v[i]] << endl;
       // cout << max(counter[0], counter[1]) << endl;
        printf("Case %d: %d\n", cse++ ,ans);
        MEM(hit);
        MEM(vis);
        MEM(color);
        MEM(counter);
        v.clear();
        for(int i = 0 ; i< node ; i++){
                g[a[i]].clear();
                g[b[i]].clear();
        }
 
    }
}