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


int tree[4*N];
int lazy[4*N];


int update(int node ,int b , int e , int l  , int r){
     int left = 2*node;
     int right = left+1;
     int m = (b+e)/2;
     if(lazy[node]){
         if(lazy[node]&1)
            tree[node] = (e-b+1)-tree[node];
         if(b!=e){
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
         }
         lazy[node] = 0;
     }
     if(e < l || b > r) return tree[node];
     if(b >= l && e <= r){
        if(b != e){
            lazy[left] += 1;
            lazy[right] += 1;
        }
        return tree[node] = (e-b+1) - tree[node];
     }
     int L = update(left , b , m , l , r);
     int R = update(right , m+1 , e , l , r);
     return tree[node] = L + R;

}


int query(int node , int b, int e , int l , int r){
     int left = 2*node;
     int right = left+1;
     int m = (b+e)/2;
     if(lazy[node]){
        if(lazy[node]&1)
            tree[node] = (e-b+1) - tree[node];
        if(b != e){
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
        }
        lazy[node] = 0;
     }

     if(b > r || e < l) return 0;

     if(b >= l && e<= r) return tree[node];

     int L = query(left, b, m , l , r);
     int R = query(right, m+ 1  ,e , l , r);
     return L + R;
}

int main()
{
    int n , q;
    scaa(n,q);

    while(q--){
         int f , l , r;
         scaaa(f,l,r);
         if(f == 0){
            update(1,1,n,l,r);

         }
         else{
           int res = query(1,1,n,l,r);
           printf("%d\n",res);
         }

//         for(int i = 1 ; i<= n ; i++){
//             cout << query(1,1,n,i,i) << ' ' ;
//         } cout << endl;
    }
    return 0;
}
