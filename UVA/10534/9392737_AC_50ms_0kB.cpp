#include <bits/stdc++.h>
using namespace std;
#define N 10005
#define inf 1e7
int a[N],sub[N], f[N] , p[N];
int n;
void init()
{
	 for(int i = 0 ; i< n ; i++){
	 	 sub[i] = inf;
	 }
	 sub[0] = -inf;
}
int main()
{
	// freopen("in.txt","r",stdin);
    while(scanf("%d",&n) == 1){
    	 for(int i = 0 ; i< n ; i++){
    	 	  scanf("%d",&a[i]);
    	 }

    	 init();

    	 for(int i = 0 ; i< n ; i++){
    	 	 int pos = lower_bound(sub,sub+n,a[i])-sub;
    	 	 f[i] = pos;
    	 	 sub[pos] = a[i];
    	 }

    	 init();
    	 for(int i = n-1; i>=0 ; i--){
    	 	 int pos = lower_bound(sub,sub+n,a[i])-sub;
    	 	 p[i] = pos;
    	 	 sub[pos] = a[i];
    	 }
         int mmax = 0;
    	 for(int i  = 0 ; i< n ; i++){
//    	 	 cout << i << ' ' << f[i] << ' ' << p[i] << endl;
             int temp = min(f[i],p[i]);
             if(temp == 1) mmax = max(mmax,1);
             else mmax = max(mmax,temp*2-1);
    	 }
    	 cout << mmax << endl;
    }
}
