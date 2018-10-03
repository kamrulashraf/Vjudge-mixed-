#include <bits/stdc++.h>
using namespace std;

int a[1005];
int dp[105][105];
int vis[105][105];
int n , m;
 string s,res;

 bool check(int in){
    for(int i = in ; i< res.size() ; i++){
        if(res[i] == '@')
           return false;
    }
    return true;
 }

 bool check1(int in){
    for(int i = in ; i< s.size() ; i++){
        if(s[i] == '@')
           return false;
    }
    return true;
 }

int main()
{

 
  cin >> s;
  bool flag = 0;
  if(s[s.size()-1] == '@' || check1(0) == 1){
     printf("No solution\n");
     return 0;
  }
  // cout << "bal" << endl;
  for(int i = 0 ; i< s.size() ; i++){
      if(flag == 0 && s[i] == '@'){
          printf("No solution\n");
          return 0;
      }
      if(isalpha(s[i])){
         res += s[i];
         flag = 1;
      }
      if(s[i] == '@' && flag == 1){
         res += s[i];
         if(isalpha(s[i+1]))
          res += s[i+1];
         else{
          printf("No solution\n");
          return 0;
         }
         i++;
         flag = 0;
         res += ',';
      }
  }
  for(int i = 0 ; i< res.size() ; i++){
      if(res[i] == ',' && check(i)) continue;
      else cout << res[i];
  } cout << endl;

}
