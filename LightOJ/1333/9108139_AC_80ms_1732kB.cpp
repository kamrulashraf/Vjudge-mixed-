#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <cassert>
#define ll long long
using namespace std;

#define pii pair<int,int>
#define ff first
#define ss second
long long MOD = 1e9;
pii p[5005];



template < class T > inline T big(T b, T p, T N){
    if(!p) return 1;
    if(!(p&1)){
            T x = big(b,p/2,N);
            return (x * x)%N;
       }
    return (b * big(b,p-1,N))%N;
}


int main()
{
     // freopen("inputf.in","r" , stdin);
	 int test , cs = 1  , block , x ,y;
	 long long color, n , m;
	 scanf("%d",&test);
	 while(test--){
	 	 scanf("%lld%lld%lld%d",&n,&m,&color , &block);
	 	 for(int i = 0 ; i< block ; i++){
	 	 	 scanf("%d%d",&p[i].ff , &p[i].ss);
	 	 }
	 	 p[block].ff = 1e7;
	 	 p[block].ss = 1e7;
	 	 sort(p,p+block);
         long long counter = 0,firstRow = 0;
	 	 for(int i = 0 ; i< block ; i++){
	 	 	  x = p[i].ff;
	 	 	  y = p[i].ss;
	 	 	  int tx = x+1;
	 	 	  pii tt = make_pair(tx,y);
	 	 	  int pos = lower_bound(p,p+block,tt)-p;
	 	 	  if( (p[pos].ff != tx || p[pos].ss != y) && tx <= n){
                   counter++; // count the open cell next to  the block cell
	 	 	  }
	 	 	  if(x==1) firstRow++;
	 	 }
         long long remFirstRow = m - firstRow;
         long long ret = big(color , remFirstRow , MOD)%MOD; // count the frist row
         ret %= MOD;

         ret = (ret * (big(color, counter , MOD))%MOD)%MOD; // count next free cell of block cell
         if(n==1){
         	if(ret < 0)
         	    ret += MOD;
         	printf("Case %d: %lld\n",cs++ ,ret);
         }
         else{
         	long long temp = (n-1)*m;
         	temp -= (block - firstRow);
         	temp -= counter;
         	ret = (ret * (big(color-1,temp,MOD))%MOD)%MOD; // count rest of the cell
         	if(ret < 0) ret += MOD;
         	printf("Case %d: %lld\n",cs++  ,ret);
         }
	 }
	 return 0;

}
