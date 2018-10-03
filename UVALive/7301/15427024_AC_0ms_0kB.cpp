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

int a[N] , cul[N];
int main()
{
    int test  , cs = 1;
    sca(test);
    while(test--){
         ll sum = 0;
         memset(cul,0,sizeof cul);
         int n , m;
         scaa(n , m);
         for(int i = 0 ; i< n ; i++){
              sca(a[i+1]);

         }
         sort(a+1 , a+n+1);

         for(int i = 0 ; i< n  ; i++){
            cul[i+1] = cul[i]+a[i+1];
         }

         int pos = upper_bound(cul+1, cul+n+1,m) - cul-1;
         for(int i = 1 ; i<= pos ; i++){
            sum += cul[i];
         }


         printf("Case %d: %d %d %lld\n",cs++ , pos , cul[pos] , sum);


    }
    return 0;
}
