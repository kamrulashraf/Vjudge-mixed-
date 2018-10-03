#include <bits/stdc++.h>
using namespace std;
#define N 105
#define inf 1e9
long long dp[65][N][132];
int n , k;


int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
        int n;
        scanf("%d",&n);
        int counter = 0;
        double res = 1.0;
        for(int i = n ; i >= 0 ; i--){
            res *= (i/(double)n);
            if(res <= .50) break;
            counter++;
            
        }
        printf("Case %d: %d\n",cs++ ,counter);
    }
}
