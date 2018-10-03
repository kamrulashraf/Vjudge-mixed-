#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
 
using namespace  std;
#define N 100005
 
int tree[4*N][4], lazy[4*N];
int temp[4];
void rottate(int node , int cnt){
     cnt = cnt%3;
     for(int i = 0 ; i< 3 ; i++){
         temp[(i+cnt)%3] = tree[node][i];
     }
     for(int i = 0 ; i< 3 ; i++){
        tree[node][i] = temp[i];
     }
 
}
void makeTree(int node , int b, int e){
      int left = node*2;
      int right = left+1;
      int m = (b+e)/2;
      if(b==e){
        tree[node][0] = 1;
        tree[node][1] = 0;
        tree[node][2] = 0;
        return;
      }
      makeTree(left,b,m);
      makeTree(right,m+1,e);
      tree[node][0] = tree[left][0]+tree[right][0];
      tree[node][1] = tree[left][1]+tree[right][1];
      tree[node][2] = tree[left][2]+tree[right][2];
}
 
 
void update(int node , int b ,int e ,int l , int r, int pass){
      int left = node*2;
      int right = left+1;
      int m = (b+e)/2;
     
      if(lazy[node]){
              rottate(node,lazy[node]);
 
              if(b!=e){
                  lazy[left] += lazy[node];
                  lazy[right] += lazy[node];
              }
              lazy[node] = 0;
      }
      if(b > r ||e < l) return;
      if( b >= l && e <= r){
        rottate(node,1);
        if(b!=e){
            lazy[left]++;
            lazy[right]++;
        }
        return;
      }
 
      update(left , b , m , l , r,pass );
      update(right , m+1 , e, l , r,pass);
      tree[node][0] = tree[left][0]+tree[right][0];
      tree[node][1] = tree[left][1]+tree[right][1];
      tree[node][2] = tree[left][2]+tree[right][2];
}
 
int query(int node , int b, int e, int l , int r){
      int left = node*2;
      int right = left+1;
      int m = (b+e)/2;
 
      if(b > r ||e < l) return 0;
      if(lazy[node]){
              rottate(node,lazy[node]);
              if(b!=e){
                  lazy[left] += lazy[node];
                  lazy[right] += lazy[node];
              }
              lazy[node] = 0;
      }
      if( b >= l && e <= r){
          return tree[node][0];
      }
      return query(left, b, m , l , r) + query(right, m+1,e, l , r);
 
 
}
int  main()
{
    // freopen("inputf.in","r" , stdin);
    int test , cs = 1, n , flag, l , r,q;
    scanf("%d",&test);
    while(test--){
            memset(lazy,0,sizeof lazy);
            printf("Case %d:\n",cs++);
            scanf("%d%d",&n,&q);
            makeTree(1,1,n);
            while(q--){
                scanf("%d",&flag);
                if(flag == 0){
                     scanf("%d%d",&l,&r);
                     l++ , r++;
                     update(1,1,n,l,r,q);
                }
                else{
                     scanf("%d%d",&l,&r);
                     l++ , r++;
                     int res = query(1,1,n,l,r);
                     printf("%d\n",res);
                }
            }
    }
}