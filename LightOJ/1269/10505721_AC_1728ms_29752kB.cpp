#include <bits/stdc++.h>
using namespace std;
#define N 1000005

int a[N];
struct  node
{
      int mark;
      node *child[2];
      node(){
         mark = 0;
         for(int i = 0 ; i< 2 ; i++)
              child[i] = NULL;
      }
} *root;


void addTrie(int n){
     string s;
     for(int i = 0 ; i< 32 ; i++){
         s += (char)((n&1));
         n/=2;
     }
     reverse(s.begin(),s.end());
     node *cur = root;
     for(int i = 0 ; i< 32 ; i++){
        if(cur->child[s[i]] == NULL)
             cur -> child[s[i]] = new node();
        cur = cur-> child[s[i]];
     }
}


int searchMax(int n){
      string s , res;
     for(int i = 0 ; i< 32 ; i++){
         s += (char) (n&1);
         n/=2;
     }
     reverse(s.begin(),s.end());

     node *cur = root;
     int res1 = 0;
     for(int i = 0 ; i<32 ; i++){
          int temp = 1-s[i];
          if(cur -> child[temp] != NULL){
             res1 = res1*2+1;
             cur = cur->child[temp];
          }
          else{
            cur = cur->child[1-temp];
            res1 *= 2;
          }
     }

    return res1;

}

int searchMin(int n){
      string s , res;
     for(int i = 0 ; i< 32 ; i++){
         s += (char) (n&1);
         n/=2;
     }
     reverse(s.begin(),s.end());

     node *cur = root;
     int res1 = 0;
     for(int i = 0 ; i<32 ; i++){
          int temp = s[i];
          if(cur -> child[temp] != NULL){
             res1 = res1*2;
             cur = cur->child[temp];
          }
          else{
            cur = cur->child[1-temp];
            res1 = res1*2+1;
          }
     }
    return res1;

}

 void del(node *cur){

     for(int i = 0 ; i< 2 ; i++){
        if(cur->child[i])
          del(cur->child[i]);
     }
     delete cur;
 }
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
               root = new node();
           int  n;
           scanf("%d",&n);



           int prev = 0;
           int mmax = 0;
           long long mmin = pow(2,32);
           for(int i = 0 ; i< n ; i++){
                scanf("%d",&a[i]);
                addTrie(prev);
                prev ^= a[i];
                mmax = max(mmax,searchMax(prev));
                mmin = min(mmin,(long long) searchMin(prev));
           }
           printf("Case %d: %d %d\n",cs++ , mmax, mmin);
           del(root);

    }
}
