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

bool mark[1000005];
std::vector<int> prime; 
std::vector<ll > ret;
void seive(int n){
	 for(int i = 2 ; i<= n ; i++){
	 	 if(mark[i] == 0)
	 	 for(int j = i+i ; j<= n ; j+= i){
	 	 	mark[j] = 1;
	 	 }
	 }

	 for(int i = 2 ; i<= n ; i++){
	 	 if(mark[i] == 0) prime.push_back(i);
	 }
}
int main()
{
	seive(1000000);
	for(int i = 0 ; i< prime.size() ; i++){
		 ll temp = prime[i];
         ll save = temp;
         temp *= save;
		 while(temp <= 1000000000000){

		 	 ret.push_back(temp);
		 	 temp *= save;
		 }

	}

	sort(ret.begin() , ret.end());
	// for(int i = 0 ; i< 20 ; i++){
	// 	 cout << ret[i] << endl;
	// }

	int test , cs = 1;
	sca(test);
	while(test--){
		 ll a , b;
		 scanf("%lld %lld",&a,&b);

		 int pos = upper_bound(ret.begin() , ret.end() , b)- ret.begin();
		 int save = upper_bound(ret.begin() , ret.end() , a-1) - ret.begin();
		 printf("%d\n",pos-save);
	}
}