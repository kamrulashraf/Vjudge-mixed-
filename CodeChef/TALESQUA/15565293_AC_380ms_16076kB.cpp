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

int main()
{
     int test , cs = 1;
     sca(test);
     while(test--){
         double  a  , k;

         cin >> a >> k;

         double temp = a/2.0;
         
         double cor[3] , res;

         for(int i  = 0 ; i< 3 ; i++)
             cin >> cor[i];
         sort(cor , cor+3);
         double r =  cor[0] + temp + k;
         double l = cor[2] - temp - k;
         if(r < l) res = 0;
         else if(r-l >= a) res = a*a;
         else res = (a*(r-l));


         printf("%.3f\n",res);

     }

     return 0;
}