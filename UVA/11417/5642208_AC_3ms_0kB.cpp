#include <bits/stdc++.h>
using namespace std;
int dp[501][501];
int gcd(int a, int b){
  if(!(b%a)) return a;
  else return gcd(b%a,a);
}
int main()
{
  int n;
  int sum = 0;
  for(int i = 1 ; i<= 500 ; i++){
    sum = 0;
    for(int j = i+1 ; j<= 500 ; j++){
       sum += gcd(i,j);
       dp[i][j] = dp[i-1][j]+sum;
     //  cout << "(" << i <<'*' << j << ")" << dp[i][j] << ' ';
    }
  }
  while(cin >> n && n){
    cout << dp[n-1][n] << endl;
  }
}
