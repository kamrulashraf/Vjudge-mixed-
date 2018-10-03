#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
int dp[1005][35];
int weight[1005] , cost[1005], maxw, test1, n, total;
using namespace std;
int fun(int i , int w)
{

    if(i == n+1) return 0;
    int profit1 = 0 , profit2 = 0;
    if(dp[i][w]!=-1) return dp[i][w];
    if(w+weight[i] <= maxw)
    {
        profit1 = cost[i] + fun(i+1, w+weight[i]);
    }
    profit2 = fun(i+1 , w);

    dp[i][w] = max(profit1 , profit2);
    return dp[i][w];
}
int main()
{
    int i,j;
    int test;
    cin >> test;
    while(test--)
    {
        total = 0;
        cin >> n;
        for(i = 1 ; i<= n ; i++)
        {
            cin >> cost[i] >> weight[i];
        }
        int test2;
        cin  >> test2;
        for(i = 1 ; i<= test2 ; i++)
        {
            memset(dp , -1  , sizeof(dp));
            cin >> maxw;
            int price = fun(1,0);
            total += price;

        }
     cout << total << endl;
    }
}