#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y)  for(int i=x;i<y;i++)
long long ncr[101][101];
    void nCr(int n){
         rep(i,0,n+1) rep(j,0,i+1){
            if(i==j || j == 0) ncr[i][j] = 1;
            else ncr[i][j] = ncr[i-1][j-1]+ ncr[i-1][j];
         }
    }
int main()
{
   nCr(100);
   int n , m;
   while(scanf("%d%d",&n,&m) && (m && n)){
       long long res = ncr[n][m];
       printf("%d things taken %d at a time is %lld exactly.\n",n,m,res);
   }
}