#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
using namespace std;
#define pii pair < int , int>
#define vpp vector < pii >
#define ff first
#define ss second
#define N 3000005
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define ll long long
#define READ()  freopen("in.txt","r" , stdin);
#define sca(x) scanf("%d",&x);
#define scaa(x,y) scanf("%d%d",&x,&y);
#define scaaa(x,y,z) scanf("%d%d%d",&x,&y,&z);


const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};


int a[N];
struct st
{
   int sum,mmax, prefix, suffix;
   st(){
    sum= 0,mmax=-2e9, prefix=-2e9, suffix=-2e9;
   }

} tree[N];

int myMax(int a , int b , int c){
   return max(a,max(b,c));
}
void makeTree(int node , int b ,int e){

    if(b == e){
       tree[node].sum = a[b];
       tree[node].prefix = a[b];
       tree[node].suffix = a[b];
       tree[node].mmax = a[b];
       // cout << node << ' ' << b << ' ' << e <<  ' ' << tree[node].mmax << endl;
       return ;
    }

    int left = node<<1LL;
    int right = left+1;
    int m = (b+e)/2;

    makeTree(left,b,m);
    makeTree(right,m+1,e);

    tree[node].sum = tree[left].sum+tree[right].sum;
    tree[node].prefix = max(tree[left].prefix  ,tree[left].sum+tree[right].prefix);
    tree[node].suffix = max(tree[left].suffix+tree[right].sum , tree[right].suffix);
    tree[node].mmax = myMax(tree[left].mmax , tree[right].mmax , tree[left].suffix+tree[right].prefix);
    // cout << node << ' ' << b << ' ' << e <<  ' ' << tree[node].mmax << ' ' << tree[node].prefix<< ' ' << tree[node].suffix << endl;
}


void update(int node , int b, int e , int pos, int val){
    int left = node*2;
    int right = left+1;
    int m = (b+e)/2;
    if( b > pos || e < pos){
        return;
    }
    if(b == pos && e == pos){
        tree[node].sum = val;
       tree[node].prefix = val;
       tree[node].suffix = val;
       tree[node].mmax = val;
       return;
    }
    update(left , b , m , pos , val);
    update(right, m+1 , e , pos , val);

    tree[node].sum = tree[left].sum+tree[right].sum;
    tree[node].prefix = max(tree[left].prefix  ,tree[left].sum+tree[right].prefix);
    tree[node].suffix = max(tree[left].suffix+tree[right].sum , tree[right].suffix);
    tree[node].mmax = myMax(tree[left].mmax , tree[right].mmax , tree[left].suffix+tree[right].prefix);
    return;
}

st query(int node , int b , int e , int l , int r){
    st ret;
//     cout << b <<  ' ' << e << ' ' << node << endl;
    if(b > r || e < l) return ret;
    if( b >= l && e <= r){
       return tree[node];
    }

    int left = node<<1LL;
    int right = left+1;
    int m = (b+e)/2;

    st temp1 = query(left,b,m,l,r);
    st temp2  = query(right,m+1,e,l,r);

    ret.sum = temp1.sum + temp2.sum;
    ret.prefix = max(temp1.prefix,temp1.sum+temp2.prefix);
    ret.suffix = max(temp1.suffix+temp2.sum , temp2.suffix);
    ret.mmax = myMax(temp1.mmax ,temp2.mmax , temp1.suffix+temp2.prefix);
    tree[node].mmax = myMax(tree[left].mmax , tree[right].mmax , tree[left].suffix+tree[right].prefix);

    return ret;

}


int main()
{

//     READ();

   int n , q;
   sca(n);

   for(int i = 1 ; i<= n ; i++){
      sca(a[i]);
   }
   makeTree(1,1,n);
   sca(q);
   while(q--){
        int f , l , r;
        scaaa(f,l,r);
        if(f == 0){
             update(1,1,n,l,r);
        }
        else{
            st temp = query(1,1,n,l,r);
            int res = temp.mmax;
            printf("%d\n", res);
        }
   }
   return 0;
}
