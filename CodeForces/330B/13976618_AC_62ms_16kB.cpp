#include <bits/stdc++.h>
using namespace  std;

#define N 100005
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
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
int main()
{
	// freopen("in.txt","r" , stdin);
     int n , m;
     scaa(n,m);
     int mark[1005]={0};
     for(int i = 0 ; i< m ; i++){
     	int a , b;
     	scaa(a,b);
     	mark[a] = 1;
     	mark[b] = 1;
     }
     int res = 0;
     for(int i = 1 ; i<= n ; i++){
     	 if(mark[i] == 0){
     	   res = i;
     	   break;
         }
     }
     printf("%d\n",n-1);
     for(int i = 1 ; i<= n ; i++){
     	 if(i != res){
     	 	printf("%d %d\n",res, i);
     	 }
     }
}
