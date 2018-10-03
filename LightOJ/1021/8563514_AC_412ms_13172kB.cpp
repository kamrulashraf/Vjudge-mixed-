#include <bits/stdc++.h>
using namespace std;
#define NN 70000+5
int base , k ;
string s;
long long dp[NN][21];
 
 
long long call(int val, int remain, int mask){
        long long res = 0;
        if(remain==0){
            if(val%k == 0) return 1;
        }
        if(dp[mask][val%k] != -1) return dp[mask][val%k];
        for(int i = 0; i< s.size() ; i++){
            int flag = mask&(1<<i);
            if(flag==0){
                int temp = mask;
                temp = (mask|(1<<i));
                int x = s[i];
                if(x>62) x =x-'A'+10;
                else x-=48;
                long long tempVal = base*val+x;
                res += call(tempVal%k,remain-1,temp);
            }
        }
 
 
        return dp[mask][val%k] = res;
}
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
        scanf("%d %d",&base,&k);
        cin >> s;
        memset(dp,-1,sizeof(dp));
        long long res = call(0,s.size(),0);
        printf("Case %d: %lld\n",cs++ ,res);
    }
    return 0;
}