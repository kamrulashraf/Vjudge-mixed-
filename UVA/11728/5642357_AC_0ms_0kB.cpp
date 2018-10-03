#include <bits/stdc++.h>
using namespace std;
 int dp[10001] , hit[10005];
int main()
{
  for(int i = 0 ; i<= 1000 ; i++)
    dp[i] = 1;
  for(int i = 2 ; i<= 1000 ; i++)
      for(int j = i ; j<= 1000 ; j+= i)
          dp[j] += i;
  for(int i =1 ; i<= 1000 ; i++){
    hit[dp[i]] = i;
  }
  int n, cs = 1;
  while(cin >> n && n){
    printf("Case %d: ", cs++);
    if(!hit[n])
       cout << "-1" << endl;
         else cout << hit[n] << endl;

  }
  return 0;
}
