#include <bits/stdc++.h>
using namespace std;
long long mmax = 0;
int hit[100] = {0};
struct node{
	int mark;
	node *child[4];
    node(){
      for(int i = 0 ; i< 4 ; i++){
        child[i] = NULL;
        mark = 0;
      }
    }
} *root;
void insertTrie(string s){
   node *cur = root;
   for(int i = 0 ; i < s.size() ; i++){
   	  int temp = hit[s[i]];
   	  if(cur -> child[temp] == NULL)
   	  	 cur -> child[temp] = new node();
   	  cur = cur -> child[temp];
   	  cur -> mark++;
   }
}

void dfs(node *u , long long level){
    mmax = max(level* u-> mark , mmax);
    for(int i = 0 ; i< 4 ; i++){
    	if(u -> child[i])
    		dfs(u -> child[i], level+1);
    }
    delete u;
}
int main()
{
   int test , cs = 1;
   cin >> test;
    hit['A'] = 0;
    hit['T'] = 1;
    hit['G'] = 2;
    hit['C'] = 3;
   while(test--){
   	    root = new node();
        int n;
        cin >> n;
        for(int i = 0 ; i< n ; i++){
        	string s;
        	cin >> s;
        	insertTrie(s);
        }
        mmax = 0;
        dfs(root , 0);
        printf("Case %d: %lld\n",cs++ , mmax);
   }
}
