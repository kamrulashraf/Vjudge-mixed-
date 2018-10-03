#include <bits/stdc++.h>
using namespace std;
int ans = 0;
struct node
{
  int mark;
 // char ch;
  node *child[10];
  node(){
    for(int i = 0 ; i< 10 ; i++){
      child[i] = NULL;
      mark = 0;
    }
  }
} *root;

void insertTrie(string s){
    node *cur = root;
    for(int i = 0 ; i< s.size() ; i++){
        int temp = s[i]-'0';
        if(cur -> child[temp] == NULL){
           cur -> child[temp] = new node();
     //      cur -> child[temp] -> ch = x;
        }
        cur = cur -> child[temp];
    }
    cur -> mark++;
}

void del(node *u){
  for(int i = 0 ; i < 10 ; i++){
     if( u -> child[i]){
       del( u -> child[i]);
     }
  }
  delete u;
}

void dfs(node *u, int counter){
  bool flag = 0;
  for(int i = 0 ; i< 10 ; i++){
      if(u -> child[i]){
        flag = 1;
        dfs(u -> child[i], counter+ u -> mark);
      }
  }
  if(flag == 0 && (u -> mark + counter) != 1)
     ans = 1;
}
int main()
{
   int test, cs = 1 ;
   cin >> test;
   while(test--){
      root = new node();
      int n;
      cin >> n;
      for(int i = 0 ; i< n ; i++){
         string s;
         cin >> s;
         insertTrie(s);
      }
      ans = 0;
      dfs(root,0);
      printf("Case %d: ",cs++);
      if(ans == 0) puts("YES");
      else puts("NO");
      del(root);

   }
}
