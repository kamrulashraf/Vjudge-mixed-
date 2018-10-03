#include <bits/stdc++.h>
using namespace  std;

#define N 2002
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
int a[N];
int main()
{
	int test , cs = 1;
	sca(test);
	while(test--){
		 int n ;
		 sca(n);
		 for(int i = 0 ; i< n ; i++){
		 	 sca(a[i]);
		 }

		 sort(a,a+n);
		 ll res = 0;
		 for(int i = 0 ; i < n ; i++){
		 	 for(int j = i+1 ; j< n ; j++){
		 	 	 int temp = a[i] + a[j];
		 	 	 int pos = lower_bound(a,a+n,temp)-a;
		 	 	 res += pos-j-1;
		 	 }
		 }
		 printf("Case %d: %lld\n",cs++ ,res);
	}
}
