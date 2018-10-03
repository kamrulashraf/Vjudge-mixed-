#include <bits/stdc++.h>
using namespace  std;

#define N 1005
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
int cul[N] ,dp[N][N][2];
struct nd{
   int p , q , r , s;
   nd(int a , int b, int c, int d){
    p = a;
    q = b;
    r = c;
    s = d;
   }
};
bool cmp(nd a , nd b){
    return a.p < b.p;
}

vector < nd > v;


int call(int indx, int prev, int flag){
    int temp1 = inf , temp2 = inf;
    if(indx == n){
       if(flag) return 0;
       return inf;
    }
    if(prev >= 0)
    if(dp[indx][prev][flag] != -1) return dp[indx][prev][flag];
    int a = v[indx].p;
    int b = v[indx].q;
    int c = v[indx].r;
    int d = v[indx].s;
//    cout << indx << ' ' << b << ' ' << c << ' ' << cul[indx+1] << ' ' << cul[prev] << ' ' << indx << ' ' << prev <<  endl;
    temp1 = b + c*(cul[indx+1]-cul[prev+1])+ call(indx+1,indx,flag|1);
    if(indx < n-1)
    temp2 = call(indx+1,prev,flag);
    return dp[indx][prev][flag] = min(temp1,temp2);
}


int main()
{
	int test , cs = 1;
	sca(test);
//    freopen("in.txt" , "r" , stdin);
//    freopen("out.txt" , "w" ,stdout);
	while(test--){
		sca(n);
//		if(!n) break;
		v.clear();
		F(i,n){
			 int a , b , c,d;
			 scaaa(a,b,c);
			 sca(d);
			 v.push_back(nd(a,b,c,d));
		}
		sort(v.begin(),v.end(),cmp);
        memset(cul,0,sizeof cul);
		cul[1] = v[0].s;
		for(int i = 2 ; i <= n ; i++){
			 cul[i] = cul[i-1] + v[i-1].s;
		}
//		F(i,n+1){
//		   cout << i << ' ' << cul[i] << endl;
//		}

//		F(indx,n){
//		   int a = v[indx].p;
//            int b = v[indx].q;
//            int c = v[indx].r;
//            int d = v[indx].s;
//            cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
//		}
        memset(dp,-1,sizeof dp);
		int res = call(0 ,  -1 , 0);
		printf("Case %d: %d\n",cs++ , res);
//        printf("%d\n",res);
	}
}
