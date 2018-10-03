#include <bits/stdc++.h>
using namespace  std;

#define N 505
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

int fx[] = {0,0,1,-1};
int fy[] = {1,-1,0,0};
int a[N][N];
int main()
{
//     read();
    int test ;

    sca(test);
    while(test--){
         int n , m;
         scaa(n,m);

         for(int i = 0 ; i< n ; i++){
             for(int j = 0 ; j< m ; j++){
                 sca(a[i][j]);
//                 if(a[i][j] == -1){
//
//                 }
             }
         }

// even odd can be alter;
// 1 2 3
// 4 5 6
// 7 8 9

// 5 can be change with 2 , 4 , 6 . and 2 4 6 can cange with diagonal
// which are likely to cng with 5
         int counter = 0;
         int cnt = 0;
         for(int i = 0 ; i< n  ; i++){
            for(int j = 0 ; j< m ; j++){
               if(a[i][j] != -1){
                   if((i+j)&1) counter+=a[i][j];
                   else cnt+=a[i][j];
               }

            }
         }

         int res = abs(counter-cnt);
         printf("%d\n",res);


    }
}
