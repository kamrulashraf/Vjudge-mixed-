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


ll tree[4*N] , lazy[4*N], counter;
map < int , int > mark;

void update(int node , int b , int e , int l , int r , int val){
	int m = (b+e)/2;
	int left = 2*node;
	int right = left+1;
	if(lazy[node]){
		tree[node] = lazy[node];
		if(b!=e){
			lazy[left] = lazy[node];
			lazy[right] = lazy[node];
		}
		lazy[node] = 0;
	}
	if( b> r || e < l) return;
	if(b >= l && e<= r){
		tree[node] = val;
		if(b != e){
			lazy[left] = val;
			lazy[right] = val;
		}
		return;
	}
	update(left,b,m,l,r,val);
	update(right,m+1,e,l,r,val);


}

void make(int node,  int b , int e){
	int m = (b+e)/2;
	int left = 2*node;
	int right = left+1;
//	cout << b << ' ' <<  e << ' ' << node << endl;
	if(lazy[node]){
		tree[node] = lazy[node];
		if(b!=e){
			lazy[left] = lazy[node];
			lazy[right] = lazy[node];
		}
		lazy[node] = 0;
	}
	if(b == e){
		if( tree[node] && mark[tree[node]] == 0){
			counter++;
		}
		mark[tree[node]] = 1;
		return;
	}
	make(left,b,m);
	make(right,m+1,e);
}
int main()
{
	 int test, cs = 1;
	 scana(test);
	 while(test--){
	 	int n;
	 	MEMO(tree);
	 	MEMO(lazy);
	 	scana(n);
	 	int nn = 2*n;
	 	F(i,n){
	 		int a ,b;
	 		scanaa(a,b);
	 		update(1,1,200000,a,b,i+1);
	 	}
        counter = 0;
	 	mark.clear();
	 	make(1,1,200000);
	 	printf("Case %d: %lld\n",cs++ ,counter);

	 }
}
