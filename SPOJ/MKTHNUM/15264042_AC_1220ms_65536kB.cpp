#include <bits/stdc++.h>
using namespace  std;

#define N 400005
#define inf 1e9+5
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define MP make_pair
#define PB push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define write() freopen("out.txt", "w" , stdout)
#define read() freopen("in.txt" , "r", stdin)


std::vector< int > tree[4*N];
int a[N];
void update(int node,int b,int e){
   int left = 2*node;
   int right = left+1;
   int m = (b+e)/2;
   if(b == e){
     tree[node].push_back(a[b]);
     return;
   }
   update(left,b,m);
   update(right,m+1,e);
   int len1 = tree[left].size();
   int len2 = tree[right].size();
   tree[node].resize(len1+len2); // **must care about it
   merge(tree[left].begin() , tree[left].end() , tree[right].begin(), tree[right].end() , tree[node].begin());
   return;
}

int  query(int node,int b,int e, int i , int j, int key){
//    cout << node << ' ' << b << ' ' << e << ' ' <<  i << ' ' << j << ' ' << key << endl;
    int m = (b+e)/2;
    int left = 2*node;
    int right = left+1;
    if( b > j || e < i) return 0;
    if( b >= i && e <= j){
       int pos = upper_bound(tree[node].begin() , tree[node].end() , key) - tree[node].begin();
//       for(int i = 0 ; i < tree[node].size() ; i++){
//          cout << tree[node][i] << ' ';
//       }cout << endl;
//
//       cout << key << ' ' << pos << endl;
       return pos;
    }
    int p1 = query(left,b,m,i,j,key);
    int p2 = query(right,m+1,e,i,j,key);
    return p1+p2;
}


int main()
{
    int n , q;
    scaa(n,q);
    for(int i = 1 ; i<= n ; i++){
        sca(a[i]);
    }
    update(1,1,n);
    // cout << query(1,1,n,1,n,4) << endl;
   while(q--){
        int l ,r , k;
        scaaa(l,r,k);

        int b = -inf;
        int e = inf;
        while(b <= e){
            int m = (b+e)/2;
            int pos = query(1,1,n,l,r,m);
//            cout << b << ' ' << m << ' ' << e << ' ' << pos << endl;
            if(pos < k){
                b = m+1;
            }
            else e = m-1;
        }
        printf("%d\n",b);
   }
    return 0;
}
