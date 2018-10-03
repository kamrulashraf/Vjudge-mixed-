#include <bits/stdc++.h>
using namespace  std;

#define N 400005
#define inf 2e9
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

int a[N];
struct st
{
    int mmax , indx;
    st(){
        mmax = 0;
        indx = 0;
    }
} tree[4*N];
void make(int node , int b , int e){
     int left = node*2;
     int right = left+1;
     int m = (b+e)/2;

     if(b == e){
         tree[node].mmax = a[b];
         tree[node].indx = b;
         return;
     }
     make(left,  b , m);
     make(right, m+1, e);
     if(tree[left].mmax > tree[right].mmax){
         tree[node] = tree[left];
     }
     else{
        tree[node] = tree[right];
     }
     return;
}

void update(int node , int b ,int e , int pos  , int val){
    int left = node*2;
    int right = left+1;
    int m = (b+e)/2;

    if( b == pos && e == pos){
        tree[node].mmax = val;
        tree[node].indx = pos;
        return;
    }
    if( pos < b || pos > e){
         tree[node];
         return;
     }

    update(left , b , m , pos , val);
    update(right , m+1 , e ,  pos , val);

    if(tree[left].mmax > tree[right].mmax){
         tree[node] = tree[left];
    }
    else tree[node] = tree[right];




}

st query(int node , int b , int e , int l , int r){
    int left  = 2*node;
    int right = left + 1;
    int m = (b+e)/2;
    if( b > r || e < l){
        st temp;
        return temp;
    }
    if(b >= l && e <= r){
        return tree[node];
    }
    st L = query(left,b,m,l,r);
    st R = query(right,m+1,e,l,r);
    if(L.mmax > R.mmax)
        return L;
    else return R;
}


int main()
{
    int n  , q;
    sca(n);
    for(int i = 1 ; i<= n ; i++){
         sca(a[i]);
    }

    sca(q);
    make(1,1,n);

    while(q--){
         int l , r;
         char f;
         getchar();
         scanf("%c %d %d",&f , &l , &r);
//         cout << f << ' ' << l << ' ' << r << endl;
         if(f == 'U'){
             update(1,1,n,l,r);
         }
         else{
            st temp, temp1;
            ll res =0;
            int pos = 0;
            temp = query(1,1,n,l,r);
            res = temp.mmax;


            int mmax = 0;
            if(temp.indx < r){
                temp1 = query(1,1,n,temp.indx+1,r);
                mmax = max(mmax,temp1.mmax);
            }
            if(temp.indx>l){
               temp1 = query(1,1,n,l,temp.indx-1);
               mmax = max(mmax,temp1.mmax);
            }
            res += mmax ;
            printf("%lld\n",res);
         }
    }
    return 0;
}
