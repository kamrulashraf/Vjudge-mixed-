#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int dp[1000005];
int main()
{
      int n;
      cin >> n;
      getchar();
      scanf("%s",&s[1]);
      int sz = 0;
      for(int i = 1 ; s[i] ; i++){
          sz++;
          dp[i] = dp[i-1] + (s[i]-'0');
      }


      long long res = 0;
      int counter = 0;
      if(n == 0){
          for(int i = 1 ; i<= sz ; i++){
              if(s[i] == '0') counter++;
              else counter = 0;

              if(counter) res += counter;
          }
      }
      else
      for(int i = 1 ; i<= sz ; i++){
          int temp = dp[i-1];
          temp += n;
          int t = lower_bound(dp+i,dp+sz+1,temp) -dp;
          int t1 = upper_bound(dp+i,dp+sz+1,temp) -dp;
          res += t1-t;
//           cout << i <<' ' <<  t << ' ' << t1  << ' ' << t1 -t << endl;

       }
      cout << res << endl;


}
