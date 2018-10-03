#include <bits/stdc++.h>
using namespace std;
#define NN 1000
map < string , int > hit;
int vis[NN] , match[NN] ;
map < int , std::vector<int > > adj;

int bipartite(int u){
    if(vis[u] == 1) return 0;
    vis[u] = 1;
    for(int i = 0 ; i< adj[u].size() ; i++){
        int v = adj[u][i];
        if(match[v] == -1 || bipartite(match[v])){
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int test, cs = 1;


    string s = "XXL,XL,L,M,S,XS";
    string temp;
    int  counter = -1;
    for(int i = 0 ; i<s.size() ; i++){
        if(s[i] == ','){
            counter++;
            hit[temp] = counter;
            temp.clear();
        }
        else temp += s[i];
    }
    hit[temp] = counter+1;




    scanf("%d",&test);
    while(test--){
         int n , m;
         string a , b;
         scanf("%d%d",&n,&m);
         for(int i = 0 ; i< m ; i++){
            cin >>  a >> b;
            int aa = hit[a];
            int bb = hit[b];
            for(int j = 1 ; j<= n/6 ; j++){
                adj[i].push_back(j + aa*(n/6));
                adj[i].push_back(j+bb*(n/6));
            }
         }
         int res = 0;
         memset(match,-1,sizeof match);

         for(int i=0;i<m;i++){
            memset(vis,0,sizeof vis);
            res += bipartite(i);
         }
         if(res >= m) printf("YES\n");
         else printf("NO\n");
         adj.clear();
    }
}