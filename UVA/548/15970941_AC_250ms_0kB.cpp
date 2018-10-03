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

vector < int > call(string s){

	 stringstream str;
	 vector < int > ret;
	 str << s;
     int temp;
	 while(str >> temp){
	 	ret.pb(temp);
	 }
	 return ret;
}

map < int , int > mark , vis;
map < int , vector<int> > adj;
string s;
string s1;
int sz ;
int fun(int i){
	// cout << i << endl;
	if(i >= sz || i < 0) return 1;
	return vis[i];
}

void clr(){
	mark.clear();
	vis.clear();
	adj.clear();
}


int main()
{
	// read();
	// write();

	while(getline(cin, s)){

		clr();
        std::vector< int > v = call(s);
        sz = v.size();
        // for(auto x : v){
        // 	 cout << x << ' ';
        // } cout << endl;

        getline(cin , s1);
        std::vector< int > v1 = call(s1);

        // for(auto x : v) cout << x << ' ' ; cout << endl;

        // for(auto x : v1) cout << x << ' ' ; cout << endl;

       for(int i = 0 ; i < v.size() ; i++){
       		mark[v[i]] = i;
       }

       int mmin = inf, res = inf;


        int root = v1[v1.size()-1];
        int sum = root;
        stack < int > st;
        st.push(root);
        if(sz == 1) res = root;
        for(int i = v1.size()-1 ; i>= 0 ; i--){
        	  int temp = v1[i];
        	  vis[mark[temp]] = 1;
        	  if(root != temp){
        	  	 int tt = st.top();
        	  	 adj[tt].push_back(temp);
        	  	 st.push(temp);

        	  	 tt = st.top();

        	  	 sum += temp;

        	  	 int temp1 = mark[temp];
        	//  	 cout << tt << ' ' << temp1 << ' ' << fun(temp1-1) << ' ' << fun(temp1+1)  <<  ' ' << sum <<  endl;

        	  	 if(fun(temp1-1) && fun(temp1+1) && adj[tt].size() == 0){
        	  	 	if(sum <= mmin){
        	  	 		   if(mmin == sum){
        	  	 		   	  res = min(res,tt);
        	  	 		   }
        	  	 		   else
                           res = tt;
                           mmin = sum;
        	  	 	}
        	  	 }

        	  	 while(fun(temp1-1) && fun(temp1+1)){
        	  	 	 int save = st.top();
        	  	 	 st.pop();
                     if(st.size() == 0) break;
        	  	 	 temp1 = mark[st.top()];
        	  	 	 sum-= save;
        	  	 }

        	  }


        }
     //   cout << mmin << endl;
        printf("%d\n",res);
	}
}
