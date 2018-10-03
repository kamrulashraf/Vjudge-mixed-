#include <bits/stdc++.h>
using namespace  std;

#define N 500005
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
int n;

struct node
{
	int a ,b , c;
	node(int _a , int _b , int _c){
		a = _a;
		b = _b;
		c = _c;
	}
};


bool cmp(node x , node y){
	 return x.a < y.a;
}
vector < node > v;
int temp[N];
int dp[N];

int call(int indx){
   if(indx == n) return 0;
   if(dp[indx] != -1) return dp[indx];
   int temp1 = 0;
   int temp2 = 0;
   int fst = v[indx].a;
   int snd = v[indx].b;
   int cost = v[indx].c;


   int pos = upper_bound(temp,temp+n,snd)-temp;
//   cout << indx << ' ' << pos << endl;
   temp1 = cost+call(pos);
   temp2 = call(indx+1);
   return dp[indx] = max(temp1,temp2);

}
int main()
{
//    freopen("in.txt", "r" ,stdin);
	int test , cs = 1;
	sca(test);

	while(test--){
        v.clear();
        memset(temp,0,sizeof temp);
        memset(dp,-1,sizeof dp);
		sca(n);
		int a , b,c;
		F(i,n){
			 scaaa(a,b,c);
             b += a-1;
             v.push_back(node(a,b,c));
		}
		sort(v.begin() , v.end(),cmp);


		for(int i = 0 ; i< v.size() ; i++){
		      temp[i] = v[i].a;
//		      cout << v[i].a << ' ' << v[i].b << endl;
		}

		int res = call(0);
		printf("Case %d: %d\n",cs++ , res);

	}
}
