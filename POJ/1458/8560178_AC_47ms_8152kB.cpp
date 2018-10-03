#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;
#define ll long long
#define N 1005
char a[N] , b[N];
ll dp[1005][1005];
 int n;


int call(int sa ,int sb){
    if(sa < 0 || sb < 0) return 0;
    if(dp[sa][sb] != -1) return dp[sa][sb];
    if(a[sa] == b[sb]){
        return 1+call(sa-1,sb-1);
    }
    else{
      return dp[sa][sb] = max(call(sa-1,sb),call(sa,sb-1));
    }
}
int main()
{
   while(scanf("%s %s",a,b)==2){
      memset(dp,-1,sizeof dp);
      int sa = strlen(a);
      int sb = strlen(b);
      int res = call(sa-1,sb-1);
      cout << res << endl;
   }

}
