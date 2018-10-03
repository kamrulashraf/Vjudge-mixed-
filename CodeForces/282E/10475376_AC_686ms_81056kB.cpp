#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
ll a[N], dp[N] , bdp[N];
struct node{
   int mark;
   node *child[2];
   node(){
      mark = 0;
      for(int i = 0 ; i< 2 ; i++){
          child[i] = NULL;
      }
   }
} *root;



void addTrie(ll n){
    string s;
    for(int i = 0 ; i < 64 ; i++){
         s += (char) ((n&1));
         n /= 2;
    }

    reverse(s.begin(),s.end());

    node *cur = root;
    for(int i = 0 ; i< 64 ; i++){
        int temp = (int) s[i];
//        cout << temp;
        if(cur -> child[temp] == NULL)
             cur -> child[temp] = new node();
        cur = cur -> child[temp];
    }
//    cout << endl;
}



long long searchMax(ll n){
       string s;
    for(int i = 0 ; i < 64 ; i++){
         s += (char) n&1;
         n /= 2;
    }
     reverse(s.begin(),s.end());

    ll ret = 0;
    node *cur = root;
    for(int i = 0 ; i< 64 ; i++){
        int temp = (int) s[i];

        if(cur -> child[1-temp] != NULL){
            ret = ret*2+(1);
            cur = cur -> child[1-temp];
        }
        else{
           ret = ret*2+0;
           cur = cur -> child[temp];
        }
    }
    return ret;

}
void del(node *u){
    for(int i = 0 ; i< 2 ; i++){
         if(u->child[i])
             del(u->child[i]);
    }
    delete u;
}


int main()
{
    root = new node();

    int n ;
    scanf("%d",&n);

    for(int i = 1 ; i<= n ; i++){
         scanf("%I64d",&a[i]);
    }
    dp[0] = 0;
    for(int i = 1 ; i< n ; i++){
          dp[i] = dp[i-1]^a[i];
    }
    bdp[n+1] =  0;
    for(int i = n ; i>=1 ; i--)
         bdp[i] = bdp[i+1]^a[i];


    long long prev = 0;
    ll mmax = 0;
//    for(int i = n-1 ; i>= 1 ; i--){
//          prev ^= a[i+1];
////          cout << prev << ' ' << dp[i] << endl;
//          addTrie(prev);
//          ll ret =  searchMax(dp[i]);
////          cout << i << ' ' << ret << endl;
//          mmax = max(mmax,bdp[i+1]);
//          mmax = max(dp[i],mmax);
//          mmax = max(mmax,ret);
//    }

    for(int i = n ; i>= 0 ; i--){
          addTrie(prev);
          ll ret = searchMax(dp[i]);
          mmax = max(ret,mmax);
          prev ^= a[i];
    }

    cout << mmax << endl;
}
