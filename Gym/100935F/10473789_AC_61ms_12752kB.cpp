#include <bits/stdc++.h>
using namespace std;


char s[1000005];
int mmax = 0;
int save;
struct node{
   int mark;
   node *child[26];
   node(){
      mark = 0;
      for(int i = 0 ; i< 26 ; i++){
          child[i] = NULL;
      }
   }
} *root;


void addTrie(string s){

   node *cur = root;
   int sz = s.size();
   for(int i = 0 ; i< sz ; i++){
         int temp = s[i]-'a';
         if(cur->child[temp] ==NULL){
             cur->child[temp] = new node();
         }

         cur = cur -> child[temp];
         cur -> mark++;
   }


}


void del(node *u){
    for(int i = 0 ; i< 26 ; i++){
         if(u->child[i])
             del(u->child[i]);
    }
    delete u;
}


void dfs(node *u, int counter){


//     cout << counter << ' ' << u -> mark << endl;
     if(u->mark > 2 && counter > mmax){
         mmax = counter;
         save = u->mark;
     }
     for(int i = 0 ; i<26 ; i++){
         if(u->child[i]){
             dfs(u->child[i],counter+1);
         }
     }
}
int main()
{
      int test , cs= 1 ;
      scanf("%d",&test);


      while(test--){
           root = new node();
           int n;
           mmax = 0;
           scanf("%d",&n);
           getchar();
           for(int i = 0 ; i< n ; i++){
                scanf("%s",s);
                for(int j = 0 ; s[j] ; j++) s[j] |= 32;
                string temp;
                temp = s;
                reverse(temp.begin(),temp.end());

                addTrie(temp);
           }

           dfs(root,0);
           del(root);
           printf("Case %d:\n%d %d\n",cs++ , mmax,  save);
      }
   return 0;
}
