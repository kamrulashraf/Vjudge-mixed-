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

int x[N] , y[N] , z[N];
int main()
{
    int test ;
    sca(test);
    while(test--){
         int n;
         int mmax[4] = {0} , save[4];
         F(i,4) save[i] = inf;
         sca(n);
         F(i , n){
             int a , b,  c;
             scaaa(a,b,c);
             x[i] = a; y[i] = b ; z[i] = c;

             if(mmax[b] <= c){

                 mmax[b] = c;
             }
         }

        for(int i = 0 ; i< n ; i++){
//           cout << z[i] << ' ' << x[i] << ' ' <<  y[i] << endl;
           if(z[i] == mmax[y[i]]){
               save[y[i]] = min(save[y[i]] , x[i]);
           }
        }

         for(int i = 1 ; i<= 3 ; i++){
             cout << mmax[i] << ' ' << save[i] << endl;
         }
    }
}
