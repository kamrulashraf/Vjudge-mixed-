#include <bits/stdc++.h>
using namespace std;
long long  dp [50005];
int call(int i, string s){
   if(s[i] == '0') return dp[i] = 0;
   if(i == s.size()) return dp[i] = 1;
   if( i == s.size()-1) return dp[i] = 1;
   if(dp[i] != -1) return dp[i];
   int temp = (s[i]-48)*10;
   if(temp+s[i+1]-48 <= 26)
      return dp[i] = call(i+1 ,s) + call(i+2,s);
   else return dp[i] = call(i+1,s);
}
int main()
{
   int len;
   string s;
   while(cin >> s){
      if(s == "0") break;
      memset(dp,-1,sizeof(dp));
      cout << call(0, s) << endl;
//      for(int i = 0 ; i< s.size() ; i++)
//         cout << dp[i] << ' ';
//         cout << "\n";
   }

}
