#include <bits/stdc++.h>
using namespace std;
int dp[100005];
vector < int > prime,v;
void seive(){
bool a[205];
int n = 200;
for(int i = 3 ; i*i <= n ; i+=2)
   if(a[i]==0)
      for(int j = i*i ; j<= n ; j+= 2*i)
         a[j] = 1;
 prime.push_back(2);
 for(int i = 3 ; i<= n ; i+=2)
    if(a[i] == 0) prime.push_back(i);

}

void factor(int num){
  for(int i = 0 ; prime[i]*prime[i] <= num && i < prime.size() ; i++){
     if(num%prime[i]==0){
        v.push_back(prime[i]);
        while(num%prime[i]==0)  num /= prime[i];
     }

  }
if(num > 1) v.push_back(num);
}
int main()
{
  int a , b;
  int test, cs = 1;
  seive();
  cin >> test;
  while(test--){
     cin >> a >> b;
     for(int i = 0 ; i<= 1001 ; i++)
         dp[i] = 99999999;
     dp[a] = 0;
     for(int i = a ; i<= b ; i++){
        if(dp[i] != 99999999){
           v.clear();
           factor(i);
           if(v.size() != 0 && i != v[0])
           for(int j = 0 ; j < v.size() && v[j] <= b ; j++){
              int temp = i+v[j];
              if(temp <= b){
                dp[temp] = min(dp[i]+1, dp[temp]);
              }
           }
        }

     }
    if(dp[b] == 99999999)  printf("Case %d: %d\n", cs++ , -1);
       else printf("Case %d: %d\n", cs++ , dp[b]);

  }

}
