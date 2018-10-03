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

int a[N];
int main()
{
    // freopen("in.txt","r" ,stdin);
    // freopen("out.txt","w" ,stdout);
	int n ;
	int cnt = 0;
	while(sca(n)){
	    if(cnt) printf("\n");
	    cnt++;
	    if(n == 0)break;
	    while(1){
            sca(a[0]);
            if(a[0] == 0){
                break;
            }
            for(int i = 1 ; i<n ; i++){
                sca(a[i]);
            }
            std::vector< int > v;
            stack < int > st;
            int cur = 0;
            for(int i = 1 ; i<= n ; i++){
                st.push(i);
                int temp = st.top();
                while(!st.empty() && temp == a[cur]){
                    cur++;
                    v.push_back(temp);
                    st.pop();
                    if(st.empty()) break;
                    temp = st.top();
                }
            }
            bool flag = 0;
            while(!st.empty()){
               v.PB(st.top());
               st.pop();
            }
            for(int i = 0 ; i< n ; i++){
    //		    cout << v[i] << ' ' << a[i] <<  endl;
                if(v[i] != a[i]) flag = 1;
            }
            if(flag) printf("No\n");
            else printf("Yes\n");
         }
	}
}
