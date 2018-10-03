#include <bits/stdc++.h>
using namespace std;
#define NN 10000007
#define ll long long
ll n, tree[NN], a[NN],  res, mmax;
void update(ll indx , ll val){
	while(indx <= mmax){
		tree[indx] += val;
		indx += indx & -indx;
	}
}
ll query(ll indx){
	ll sum = 0;
	while(indx){
       sum += tree[indx];
       indx -= indx & -indx;
	}
	return sum;
}
void clr(){
 memset(tree,0,sizeof(tree));
 mmax = 0;
 res = 0;
}
int main()
{
	int test, cs = 1, t;
	scanf("%d", &test);
	while(test--){
	      clr();
          scanf("%lld",&n);
          for(int i = 0 ; i < n ; i++){
             scanf("%lld",&a[i]);
             mmax = max(a[i], mmax);
          }
          for(int i = 0 ; i< n ; i++){
               res += query(mmax) - query(a[i]);
               update(a[i],1);
          }
          printf("%lld\n",res);

	}
}
