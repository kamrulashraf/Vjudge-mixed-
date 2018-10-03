#include <bits/stdc++.h>
using namespace std;

int a[1005];
int dp[105][105];
int vis[105][105];
int n , m;
int call(int in , int rem){
     if(in >= n || rem == 0) return 0;
     if(vis[in][rem] != -1) return dp[in][rem];
     int p1 = 0 , p2 = 0;
     p1 = a[in] + call(in+1,rem-1); 
     p2 = call(in+1,rem);
     vis[in][rem] = 1;
     return dp[in][rem] =  max(p1,p2);
}
int main()
{
    
  string s;
  cin >> s;
  for(int i = 0 ; i< s.size() ; i++){
      if(s[i] == '.') cout << 0;
      if(s[i] == '-'){
          i++;
          if(s[i] == '.') cout << 1 ;
          else cout << 2;
      }
  }
  cout << endl;

}