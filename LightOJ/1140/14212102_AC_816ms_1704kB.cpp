#include <bits/stdc++.h>
using namespace std;
#define NN 15
#define ll long long
int u[NN] , l[NN];
long long dp[NN][2][2][2][NN];
int n;
// next state
//flag = flag| i? 1:0
//islow = islow & (i==lower[index])
//ishigh = ishigh & (i==upper[index])
long long call(int in , bool flag ,bool islow , bool ishigh,int carry){
    if(in >= n)
       return carry;
    ll  res = 0;
    if(dp[in][flag][islow][ishigh][carry] !=-1)
       return dp[in][flag][islow][ishigh][carry];
    for(int i = 0 ; i< 10 ; i++){
         if(islow && i < l[in]) continue;
         if(ishigh && i> u[in]) continue;
         if(i == 0 && flag)
           res += call(in+1,flag,islow&(i==l[in]),ishigh&(i==u[in]),carry+1);
         else
           res +=call(in+1,flag | i?1:0,islow&(i==l[in]),ishigh&(i==u[in]),carry);
 
    }
    return dp[in][flag][islow][ishigh][carry] =res;
}
int main()
{
   int test , cs = 1;
   scanf("%d",&test);
   while(test--){
       string s , s1;
       cin >> s >> s1;
       int len = s.size();
       int len1 = s1.size();
       n = max(len,len1);
       int dif = len1-len;
       string temp;
       for(int i = 0 ; i< dif ; i++)
          temp += '0';
       temp += s;
       s = temp;
       for(int i = 0 ; i < s.size() ; i++){
           l[i] = s[i]-48;
           u[i] = s1[i]-48;
       }
       memset(dp,-1,sizeof dp);
       long long res = call(0,0,1,1,0);
       temp.clear();
       for(int i = 0 ; i< s.size(); i++)
          temp += '0';
        if(s == temp) res ++;
       printf("Case %d: %lld\n",cs++,res);
   }
   return 0;
}
 