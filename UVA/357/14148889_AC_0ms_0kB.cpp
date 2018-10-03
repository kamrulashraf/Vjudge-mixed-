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
ull dp[30005];
int main()
{
	// freopen("in.txt","r" ,stdin);
	// freopen("out.txt" , "w" , stdout);
	int n;
	std::vector< int > v;
	v.push_back(1);
	v.push_back(5);
	v.push_back(10);
	v.push_back(25);
	v.push_back(50);
	dp[0] = 1;
	for(int i = 0 ; i< v.size() ; i++){
    	 	 for(int j = v[i] ; j<= 30000 ; j++){
                  int temp = j - v[i];
                  if(temp >= 0){
                  	 dp[j] += dp[temp];
                  }
    	 	 }
    }

//    for(int i = 0 ; i< 30000 ; i++){
//      cout <<  i << ' ' << dp[i] << endl;
//    }
    while(sca(n)==1){

    	 if(dp[n] > 1) printf("There are %llu ways to produce %d cents change.\n",dp[n] , n);
    	 else printf("There is only %llu way to produce %d cents change.\n",dp[n] , n);
    }
    return 0;
}
