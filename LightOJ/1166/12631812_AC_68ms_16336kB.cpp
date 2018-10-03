#include <bits/stdc++.h>
using namespace  std;

#define N 3000000
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

bool vis[N];
int a[N];
int dfs(int u , int par){
	if(u != par){
		return 1+dfs(a[u],par);
		swap(a[u],a[a[u]]);
	}
	else return 0;
}
int main()
{
	int test , cs   = 1;
	sca(test);


	while(test--){
         memset(vis,0,sizeof vis);
		 int n;
		 sca(n);

		 for(int i = 1 ; i<= n ; i++){
		 	 sca(a[i]);
		 }
		 int res = 0;

		 for(int i = 1 ; i<= n ; i++){
             if(vis[i] == 0){
                 int temp = i;
//                 cout << i << '#' << temp << '$';
                while(a[temp] != i){
//                     cout << temp << ' ';
                     vis[temp] = 1;
                     temp = a[temp];
                     vis[temp] = 1;
                     res++;
                }
//                cout << endl;
             }
		 }

		 printf("Case %d: %d\n",cs++ ,res);
	}
}
