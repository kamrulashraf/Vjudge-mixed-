#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll p[20], dp[20], num[20];
string s;


ll call(int indx){
   ll ret = 0, sz = s.size();

   if(indx == sz-1){
      for(int i = 1 ; i<= s[indx]-'0' ; i++){
        ret += i;
      }
      return ret%3;
   }
   int temp = s[indx]-48;

   for(int i = 0 ; i < temp ; i++){

       ret = (ret + i*p[sz-indx-1]+dp[sz-indx-2])%3;
//       cout << i << ' ' << ret << ' ' << dp[sz-indx-2] << endl;
   }
   ret = (ret + (temp*(num[indx+1]+1))%3 + call(indx+1))%3;
//   cout << ret << ' ' << num[indx+1] << endl;
   return ret%3;
}
int main()
{
    // freopen("in.txt","r", stdin);
    // freopen("out.txt","w", stdout);
     int test , cs = 1;
     scanf("%d",&test);
     dp[0] = 45;
     p[0] = 1;
     for(int i = 1 ; i< 15 ; i++){
         p[i] = 10*p[i-1];
     }

     for(int i = 1 ; i<= 10 ; i++){
         for(int j = 1 ; j<= 9 ; j++){
             dp[i] += dp[i-1]+j*p[i];
         }
         dp[i] += dp[i-1];
     }


     while(test--){
         cin >> s;
         int sz = s.size();
         int counter = 0;
         while(sz--){
             num[sz] = p[counter]*(s[sz]-'0')+num[sz+1];
             counter++;
         }

         int res = call(0);
         res %= 3;
         if(res) printf("NO\n");
         else printf("YES\n");
         s.clear();
         memset(num,0,sizeof num);

     }
}
