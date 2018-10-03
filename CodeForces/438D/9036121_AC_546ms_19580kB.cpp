#include <stdio.h>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


#define N 1000005
#define ll long long
int a[N];
struct seg
{
  ll sum;
  ll mmax;
} tree[N];

void makeTree(int node , int b, int e){
    int m=(b+e)/2 , left = node<<1;
    int right = left+1;
    if(b==e){
       tree[node].sum= a[b];
       tree[node].mmax=a[b];
       return;
    }
    makeTree(left,b,m);
    makeTree(right,m+1,e);
    tree[node].sum = tree[left].sum+tree[right].sum;
    tree[node].mmax = max(tree[left].mmax,tree[right].mmax);

}


void update1(int node , int b, int e , int indx , int val){
    int m=(b+e)/2 , left = node<<1;
    int right = left+1;
    if(b > indx|| e < indx) return;
    if(b==e){
       // cout << b << ' ' << e << '%' << endl;
       tree[node].sum= val;
       tree[node].mmax=val;
       return;
    }
    update1(left,b,m,indx,val);
    update1(right,m+1,e,indx,val);
    tree[node].sum = tree[left].sum+tree[right].sum;
    tree[node].mmax = max(tree[left].mmax,tree[right].mmax);

}

void update2(int node , int b, int e, int l , int r , int x){
    int m=(b+e)/2 , left = node<<1;
    int right = left+1;
    if(b > r || e < l) return;
    if(tree[node].mmax < x) return;
    if(b==e){
       tree[node].sum %= x;
       tree[node].mmax %= x;
       return;
    }
    update2(left,b,m,l,r,x);
    update2(right,m+1,e,l,r,x);
    tree[node].sum = tree[left].sum+tree[right].sum;
    tree[node].mmax = max(tree[left].mmax,tree[right].mmax);
}


ll query(int node, int b, int e , int l ,int r){
        int m=(b+e)/2 , left = node<<1;
    int right = left+1;
    if(b > r || e < l) return 0;
    if(b >= l && e <= r) return tree[node].sum;

    return query(left,b,m,l,r)+query(right,m+1,e,l,r);
}
int main()
{
    // freopen("inputf.in","r",stdin);
    int n , q;
    scanf("%d%d",&n,&q);
    for(int i = 1 ; i<= n ; i++)
       scanf("%d",&a[i]);
    makeTree(1,1,n);
    int l , r , mod , val;
    while(q--){

       // for(int i = 1 ; i<= n ; i++){
       //     cout << query(1,1,n,i,i) << ' ' ;
       // } cout << endl;

        int flag;
        scanf("%d",&flag);
        if(flag==1){
            scanf("%d%d",&l,&r);
            long long res = query(1,1,n,l,r);
            printf("%lld\n",res);
            continue;
        }
        if(flag == 2){
           scanf("%d%d%d",&l,&r,&mod);
           update2(1,1,n,l,r,mod);
           continue;
        }
        scanf("%d%d",&l,&val);
        update1(1,1,n,l,val);


    }
}
