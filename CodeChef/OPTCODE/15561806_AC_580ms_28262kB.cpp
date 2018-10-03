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
#define mp make_pair
#define pb push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define write() freopen("out.txt", "w" , stdout)
#define read() freopen("in.txt" , "r", stdin)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

int a[N] , b[N];

bool cmp(int a , int b){
  return a > b;
}
int main()
{
    int test , n;
    sca(test);
    while(test--){
         sca(n);
         map < int , int > mark , mm;
         vector < int > v;
         for(int i = 0 ; i< n ; i++){
             int x , y;
             scaa(x, y);
             if(mm[x] == 0){
                 mm[x] = 1;
                 v.pb(x);
             }
             mark[x] = max(mark[x] , y);
         }
         if(v.size() < 3){
            printf("%d\n",0);
            continue;
         }
         ll res = 0;
         ll temp = v.size()-2;

         vector < int > aa;
         for(int i = 0; i < v.size() ; i++){
             // cout << v[i] << ' ' << mark[v[i]] << endl;
             aa.push_back(mark[v[i]]);
         }
         sort(aa.begin() , aa.end() , cmp);

         for(int i = 0 ; i< 3 ; i++){
            res += aa[i];
         }

         printf("%lld\n",res);


    }
    return  0;
}
