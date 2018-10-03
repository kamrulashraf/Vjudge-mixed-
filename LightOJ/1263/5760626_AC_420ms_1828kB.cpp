#include <bits/stdc++.h>
using namespace std;
map < int , vector <int> > g;
vector <int> v;
bool vis[1005];
long long sum;
int counter, a[1005];
int dfs(int num){
    counter++;
    sum += a[num];
    vis[num] = 1;
    for(int i = 0 ; i< g[num].size() ; i++){
        int v = g[num][i];
        if(!vis[v]){
           dfs(v);
        }
    }
 if(sum%counter == 0)
  return sum/counter;
 else return -1;
}
int main()
{
  int test , cs  =1;
  scanf("%d", &test);
  while(test--){
     int node , edge;
     scanf("%d%d",&node , &edge);
     for(int i = 1 ; i<= node ; i++){
        scanf("%d", &a[i]);
     }
     for(int i = 0 ; i< edge ; i++){
        int a , b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
     }
     for(int i = 1 ; i<= node ; i++){
        if(vis[i]==0){
           counter = 0 ; sum = 0;
           v.push_back(dfs(i));
        }
     }
     int flag = 0, temp;
     if(v.size()) temp = v[0];
     for(int i = 0 ; i< v.size() ; i++){
           if(temp != v[i] || v[i] == -1){
             flag = 1;
             break;
           }
     }
     if(flag) printf("Case %d: No\n",cs++);
     else printf("Case %d: Yes\n",cs++);
     g.clear();
     memset(vis,0,sizeof(vis));
     v.clear();
  }

}
