#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define rep(i,x,y)  for(int i = x ; i< y ;i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
using namespace std;
#define pii pair < int , int>
#define vpp vector < pii >
#define ff first
#define ss second
#define N 200005
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define ll long long
#define READ()  freopen("in.txt","r" , stdin)
#define scana(x) scanf("%d",&x)
#define scanaa(x,y) scanf("%d%d",&x,&y)
#define scanaaa(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define MEMO(arr)  memset(arr , 0 , sizeof arr)
#define MEM(arr)  memset(arr,-1,sizeof arr)
#define inf 1e9
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};


ll tree[4*N] , lazy[4*N];




void update(int node , int b , int e , int l , int r  , int val){
	 int m = (b+e)/2;
	 int left = 2*node;
	 int right = left+1;
    // cout << node << ' ' << b << ' ' << e << ' ' << l << ' '<< r << endl;
	 if(lazy[node]){
	 	tree[node] += (e-b+1)*lazy[node];
	 	if(b!=e){
	 		 lazy[left]+=lazy[node];
	 		 lazy[right]+=lazy[node];
	 	}
	 	lazy[node]=0;
	 }
	 if(b > r || e < l) return;
	 if(b >= l && e <= r){
	 	tree[node] += (e-b+1)*val;
	 	lazy[left] += val;
	 	lazy[right] += val;
	 	return;
	 }
	 update(left,b,m,l,r,val);
	 update(right,m+1,e,l,r,val);
	 tree[node] = tree[left]+tree[right];

}


ll query(int node ,int b,  int e , int l , int r){
	 int m = (b+e)/2;
	 int left = 2*node;
	 int right = left+1;
	 if(lazy[node]){
	 	tree[node] += (e-b+1)*lazy[node];
	 	if(b!=e){
	 		lazy[left] += lazy[node];
	 		lazy[right] += lazy[node];
	 	}
	 	lazy[node] = 0;
	 }
	 if(b > r || e < l){
	 	return 0;
	 }
	 if(b >= l && e <= r){
	 	return tree[node];
	 }
	 ll L  = query(left,b,m,l,r);
	 ll R = query(right,m+1,e,l,r);
	 tree[node] = tree[left] + tree[right];
	 return L + R;
}
int main()
{
	//READ();

       int test , cs = 1;
       scana(test);
       while(test--){
         MEMO(tree);
         MEMO(lazy);
       	 int n , q;
   	     printf("Case %d:\n",cs++);
       	 scanaa(n,q);
       	 while(q--){
       	 	 int f;
       	 	 scana(f);
       	 	 if(f == 0){
       	 	 	 int x , y , z;
       	 	 	 scanaaa(x,y,z);
       	 	 	 x++ , y++;
       	 	 	 update(1,1,n,x,y,z);
       	 	 }
       	 	 else{
                int x , y;
                scanaa(x,y);
                x++ , y++;
                ll res = query(1,1,n,x,y);
                printf("%lld\n",res);
       	 	 }
       	 }

       }

}
