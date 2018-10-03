#include <bits/stdc++.h>
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
#define MP make_pair
#define PB push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define write() freopen("out.txt", "w" , stdout)
#define read() freopen("in.txt" , "r", stdin)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};


int main()
{
    int test , cs = 1;
    sca(test);
    while(test--){
         int n;
         sca(n);
         vector < pii > v;
         for(int i = 0 ; i< n ; i++){
              int l , r;
              scaa(l,r);
              v.push_back(MP(l,0));
              v.push_back(MP(r,1));
         }
         sort(v.begin() , v.end());
         int counter = 0;
         int mmax = 0;
         for(int i = 0 ; i< v.size() ; i++){
             if(v[i].ss == 0) counter++;
             if(v[i].ss == 1) counter--;
             mmax = max(counter,mmax);
         }
         printf("%d\n",mmax);

    }
    return 0;
}
