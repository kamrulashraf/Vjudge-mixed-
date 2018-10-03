#include <bits/stdc++.h>
using namespace std;
map < int , vector <int> > g;
map <int , int> ans,vis;
int bfs(int s , int level){
  int mmax = -1;
  queue < pair <int,int> > q;
  q.push(make_pair(s,level));
  vis[s] = 1;
  while(!q.empty()){
     int ff = q.front().first;
     int ss = q.front().second;
     ans[ss]++;
 //    cout << ff << '=' << ss << endl;
     mmax = max(mmax, ss);
     for(int i = 0 ; i< g[ff].size() ; i++){
        int vff = g[ff][i];
        int vss = ss+1;
        if(!vis[vff]){
          vis[vff] = 1;
          q.push(make_pair(vff,vss));
        }

     }
     q.pop();
  }
 return mmax;
}
int main()
{
  int test, node;
  cin >> node;
  for(int i = 0 ; i < node ; i++){
      int num;
      cin >> num;
      for(int j = 0 ; j< num ; j++){
         int var;
         cin >> var;
         g[i].push_back(var);
      }

  }
  cin >> test;
    for(int i = 0 ; i< test ; i++){
          int s;
          cin >> s;
          int temp = bfs(s,0);
          int mmax = -1, save = -1;
          for(int j = 1 ; j<= temp ; j++){
         //    cout << j << ' ' << ans[j] << endl;
             if(ans[j] > mmax){
                mmax = ans[j];
                save = j;
             }
          }
          if(save == -1) cout << 0 << endl;
          else
          cout << mmax << ' ' << save << endl;
          ans.clear();
          vis.clear();
    }

  g.clear();

}
