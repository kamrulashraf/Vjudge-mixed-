#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
using namespace std;
#define ff first
#define ss second
#define N 3000005;
struct  node
{
     int mark;
     node *child[10];
     node(){
         mark = 0;
         rep(i,0,10) child[i] = NULL;

     }
} *root;


void addTrie(string s){
     node *cur = root;

     for(int i = 0 ; i< s.size() ; i++){
         int temp = s[i]-'0';
         if(cur -> child[temp] == NULL){
             cur -> child[temp] = new node();
         }
         cur = cur -> child[temp];
         cur -> mark += 1;
     }
}

int mmax = 0,sz;
int dfs(node *u,int counter){
     if(u -> mark == sz) mmax = max(mmax,counter);
     for(int i = 0 ; i< 10 ; i++){
         if(u-> child[i]){
             dfs(u->child[i],counter+1);
         }
     }
}
int main()
{
           ios_base::sync_with_stdio(0); cin.tie(0);

   int n;
   cin >> n;
   root = new node();
   sz = n;
   while(n -- ){
      string s;
      cin >> s;
      addTrie(s);
   }

   int res = dfs(root,0);
   cout << mmax << endl;

}
