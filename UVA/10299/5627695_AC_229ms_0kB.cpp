#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool a[32000];
vector <int> prime;
void seive(void){
int n = 32000;
for(int i = 3 ; i*i <= n ; i+=2)
  if(a[i] == 0)
    for(int j = i*i ; j<= n ; j+= 2*i)
      a[j] = 1;
prime.push_back(2);
for(int i = 3 ; i<= n ; i+=2)
   if(a[i]==0) prime.push_back(i);
}
int phiFuntion(ll num){
if(num == 1) return 0;
ll ans = num;
for(int i = 0 ; prime[i]*prime[i] <= num ; i++){
  if(num%prime[i] == 0){
      ans = ans/prime[i]*(prime[i]-1);
    while(num%prime[i]==0)
       num /= prime[i];
  }
}
if(num > 1) ans = ans/num*(num-1);
  return ans;
}
int main()
{
  ll num;
  seive();
 // for(int i = 0 ; i< 20 ; i++) cout << prime[i] << ' ';
  while(cin >> num && num){
        cout << phiFuntion(num) << endl;
  }
}
