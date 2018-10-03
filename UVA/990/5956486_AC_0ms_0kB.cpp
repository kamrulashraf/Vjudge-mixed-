#include <bits/stdc++.h>
using namespace std;
int n, dp[31][1001], cost[31], weight[31];
bool mark[31][1001];
int call(int i , int w){
  if(i >= n) return 0;
  if(dp[i][w] != -1) return dp[i][w];
  int p1 = 0, p2 = 0;
  p1 = call(i+1,w);
  if(w-cost[i] >= 0)
  p2 = weight[i] + call(i+1, w-cost[i]);
  if(p2 >= p1)
    mark[i][w] = 1;

  return dp[i][w] = max(p1 , p2);
}
int main()
{
 // freopen("a.txt","w",stdout);
  int maxW ,  c , cs = 0;
  while(cin >> maxW >> c){
     cin >> n;
     if(cs) cout << "\n";
     cs++;
     for(int i = 0 ; i< n ; i++){
        cin >> cost[i]  >> weight[i];
        cost[i] = (3*c*cost[i]);
     }
     memset(dp,-1,sizeof(dp));
     memset(mark,0,sizeof(mark));
     cout << call(0,maxW) << endl;
     vector < int > ans;
     for(int i = 0 ; i< n ; i++){
         if(mark[i][maxW] == 1){
             if(maxW - cost[i] >= 0){
                ans.push_back(i);
             }
             maxW -= cost[i];
         }
         if(maxW < 0) break;
     }
     cout << ans.size() << endl;
     for(int i = 0 ; i< ans.size() ; i++){
        int temp = ans[i];
        cout << cost[temp]/(3*c) << ' ' << weight[temp] << endl;
     }
  }

}

