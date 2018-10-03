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


struct node
{
	int arr[3];
	void init(){
		memset(arr,0,sizeof arr);
	}
	void rol(){
		int temp = arr[2];
		for(int i = 1 ; i>= 0 ; i--){
			arr[i+1] = arr[i];
		}
		arr[0] = temp;
	}
} tree[4*N];

int lazy[4*N];


void make(int node ,int b, int e){
	int m = (b+e)/2;
	int left = 2*node;
	int right = left+1;

	if(b == e){
		 tree[node].arr[0] = 1;
		 return;
	}
	make(left,b,m);
	make(right,m+1,e);
    rep(i,0,3) tree[node].arr[i] = tree[left].arr[i]+tree[right].arr[i];

}


void update(int node , int b,  int e , int l , int r){
	int m = (b+e)/2;
	int left = 2*node;
	int right = left+1;
	if(lazy[node]){
		for(int i = 0 ; i < lazy[node]%3 ; i++){
			tree[node].rol();
		}
		if(b!=e){
			lazy[left] += lazy[node];
			lazy[right] += lazy[node];
		}
		lazy[node] = 0;
	}
	if( b> r || e < l) return;
	if(b >= l && e <= r){
		tree[node].rol();
		if(b != e){
			lazy[left]++;
			lazy[right]++;
		}
		return;
	}

	update(left,b,m,l,r);
	update(right,m+1,e,l,r);

	rep(i,0,3)   tree[node].arr[i] = tree[left].arr[i]+tree[right].arr[i];
}


int query(int node , int b , int e , int l , int r){
   	int m = (b+e)/2;
	int left = 2*node;
	int right = left+1;
	if(lazy[node]){
		for(int i = 0 ; i < lazy[node]%3 ; i++){
			tree[node].rol();
		}
		if(b!=e){
			lazy[left] += lazy[node];
			lazy[right] += lazy[node];
		}
		lazy[node] = 0;
	}

	if(b > r || e < l) return 0;
	if(b >= l && e <= r){
        return tree[node].arr[0];
	}

	int L = query(left,b,m,l,r);
	int R = query(right,m+1,e,l,r);
	return L+R;


}

int main(){
	// READ();
	int test , cs = 1;
	scana(test);
	while(test--){
		printf("Case %d:\n",cs++);
		int n , q;
		rep(i,0,4*n){
		   tree[i].init();
		}
		MEMO(lazy);
		scanaa(n,q);

		make(1,1,n);
		while(q--){
			int f , x, y;
			scanaaa(f,x,y);
			x++ , y++;
			if(f){
               int res = query(1,1,n,x,y);
               printf("%d\n",res);
			}
			else{
				update(1,1,n,x,y);
			}
		}
	}
}
