#include <bits/stdc++.h>
using namespace std;
char s[1000005];
char pattern[175][75];
int res[175];
class ahoCorasik{
    public:
	struct node
	{
	   int mark ;
	   char val;
	   node *child[26];
	   node *fail;
	   node(){
	   	  mark = 0;
	   	  for(int i = 0 ; i< 26 ; i++)
	   	  	  child[i] = NULL;
	   }
	} *root;

	ahoCorasik(){
		root = new node();
	}
    void addTrie(char s[], int indx){
    	node *cur = root;
    	for(int i = 0 ; s[i] ; i++){
    		int c = s[i]-'a';
    		if(cur -> child[c] == NULL){
    			 cur -> child[c] = new node();
    		}
    		cur = cur -> child[c];
    		cur -> val = s[i];
    	}
    	cur -> mark = indx;
    }

    void calFail(){
    	root -> fail = NULL;
    	queue < node* > q;
    	q.push(root);
    	while(!q.empty()){
    		node *u = q.front();
    		q.pop();
    		for(int i = 0 ; i< 26 ; i++){
    			  node *v;
    			  v = u -> child[i];
    			  if(v==NULL) continue;
    			  q.push(v);
    			  node *p = u -> fail;
    			  while(p != NULL && p->child[i]==NULL){
    			  	   p = p-> fail;
    			  }
    			  if(p==NULL)
    			  	u -> child[i] -> fail = root;
    			  else u-> child[i]-> fail = p->child[i];

    		}
    	}
    }

    void del(node *u){
    	for(int i = 0 ; i<26 ; i++){
    		 if(u->child[i])
    		 	del(u->child[i]);
    	}
    	delete u;
    }

    void clear(){
        del(root);
        root = new node();
    }


    int searchFunction(char s[]){
    	node *cur = root;
    	int counter = 0;
    	for(int i = 0 ; s[i] ; i++){
    		  int c = s[i]-'a';
    		  while(cur->child[c]==NULL && cur != root){
    		  	  cur = cur -> fail; // if not exit goto fail state where sucessfull
              }
    		  if(cur-> child[c]==NULL)
    		  	 cur = root;
    		  else cur = cur-> child[c];

    		  node *temp = cur;
    		  while(temp != root){
                  if(temp-> mark){
                    // cout << s[i] << ' ' << i  << ' ' << temp-> mark << endl;
                  	res[temp->mark]++;
                  	counter++;
                  }

                  temp = temp-> fail;
    		  }
    	}
    	return counter;
    }


};

ahoCorasik var;
int main()
{
    int n;
    while(scanf("%d",&n) && n){
        memset(res,0,sizeof res);
        getchar();
        
        for(int i=0;i<n;i++){
            scanf("%s",pattern[i]);
            var.addTrie(pattern[i], i+1);
        }
        scanf("%s",s);

        var.calFail();
        var.searchFunction(s);
        int mmax = 0;
        for(int i = 1 ; i<= n ; i++){
        	mmax = max(mmax,res[i]);
        }
        printf("%d\n",mmax);
        for(int i=0;i<n;i++){
        	if(res[i+1]==mmax){
        		printf("%s\n",pattern[i]);
        	}
        }
        var.clear();
    }
}
