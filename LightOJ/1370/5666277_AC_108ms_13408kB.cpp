#include <bits/stdc++.h>
using namespace std;
int p[1000005], hit[1000005];
int dp[1000005];
void eulerPhi(int num)
{
    int i , j , k ;
    for(i = 2 ; i<=num ; i++)
        p[i] = i;
    for(i = 2 ; i<= num ; i++)
    if(hit[i] == 0){
        p[i] = p[i]-1;
        for(j = 2*i ; j <= num ; j+=i)
        {
            hit[j]=1;
            p[j] = p[j]/i*(i-1);
        }
    }
    for(int i = 1 ; i<= 1000004 ; i++)
       dp[i] = 1000010;
    for(int i = 2 ; i<= 1000003 ; i++){
       if(dp[p[i]] == 1000010)
          dp[p[i]] = i;
    }
   for(int i = 1000003 ; i >= 1 ; i--){
      dp[i] = min(dp[i],dp[i+1]);
    }

}
int main()
{
  eulerPhi(1000003);
  int test, cs = 1;
  scanf("%d", &test);
  while(test--){
    long long sum= 0;
    int num;
    scanf("%d", &num);
    for(int i = 0 ; i< num ; i++){
      int a ;
      scanf("%d", &a);
      sum += dp[a];
    }
    printf("Case %d: %lld Xukha\n", cs++ , sum);
  }

}
