#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define ff first
#define ss second
#define N 100000
int a[N];
int res[N];
int tree[N];
int n;
struct node
{
	int a , b ,c , d;
	node(int x, int y ,int z , int w){
		a = x;b=y;c=z;d=w;
	}
};

bool cmp(pii a, pii b){
	 return a.ff > b.ff;
}
bool cmp1(node x , node y){
   return x.c > y.c;
}


void update(int indx){
   while(indx <= n+2){
       tree[indx] += 1;
       indx += indx & -indx;
   }
}

int sum(int indx){
   int ret = 0;
   while(indx){
      ret += tree[indx];
      indx -= indx & -indx;
   }
   return ret;
}

int main()
{
    // freopen("inputf.in", "r" , stdin);
    std::vector< pii > v;
    scanf("%d",&n);
    for(int i= 1 ; i <= n ; i++){
    	  scanf("%d",&a[i]);
    	  v.push_back({a[i],i});
    }
    sort(v.begin() , v.end(),cmp);
    int q;
    scanf("%d",&q);
    std::vector< node > v1;
    for(int i = 0 ; i< q ; i++){
    	  int l , r , x;
    	  scanf("%d%d%d",&l,&r,&x);
    	  v1.push_back(node(l,r,x,i));
    }
    sort(v1.begin(),v1.end(),cmp1);
    int cur = 0;
    for(int i = 0 ; i< v1.size() ; i++){
    	   int value = v1[i].c;
           while(v[cur].ff > value && cur < v.size()){
                 update(v[cur].ss);
//           	     cout << v[cur].ff << ' ';
           	     cur++;
           }
           res[v1[i].d]=sum(v1[i].b)-(v1[i].a-1 ? sum(v1[i].a-1) : 0);
    }

    for(int i = 0 ; i< q ; i++){
       printf("%d\n", res[i]);
    }

}
