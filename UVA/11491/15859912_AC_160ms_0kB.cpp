#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace  std;

#define N 400005
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define write() freopen("out.txt", "w" , stdout)
#define read() freopen("in.txt" , "r", stdin)

#define SET(x) memset(x , -1 , sizeof x)
#define CLR(x) memset(x , 0 , sizeof x)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

string s;
int tree[10][N];

void update(int indx , int val , int k){
     indx++;
	 while(indx < N){
//	     cout << indx << endl;
	 	 tree[k][indx] += val;
	 	 indx += indx & -indx;
	 }
	 return;
}

int tot(int indx , int k){
    indx++;
	if(indx < 0) return 0;
	int ret = 0;
	while(indx ){
		 ret += tree[k][indx];
		 indx -= indx & -indx;
	}

	return ret;

}
int main()
{
    int n , k;
    while(scaa(n,k)){
        memset(tree,0,sizeof tree);
    	std::vector< int > v[10];
    	 if(n ==0  && k == 0) break;
    	 cin >> s;

    	 for(int i = 0 ; i< s.size() ; i++){
    	 	 update(i,1,s[i]-'0');
    	 }
//    	 cout << "gsd" << endl;
         string res;
    	 for(int i = 0 ; i < s.size() ; i++){
    	 	 int temp = s[i] - '0';
    	 	 bool f = 0;
    	 	 int u , l;
    	 	 l = i;
    	 	 u = i+k;
    	 	 for(int i = temp+1 ; i<= 9 ; i++){
    	 	 	 if(tot(u,i) - tot(l-1,i) >0 ){
    	 	 	 	f = 1;
    	 	 	 }
    	 	 }

//    	 	 couendl;

    	 	 if(f == 1 || k == n-i){
    	 	   k--;
    	 	   continue;
    	 	 }
    	 	 else res += s[i];

    	 }
    	 cout << res << endl;

    }
return 0;
}
