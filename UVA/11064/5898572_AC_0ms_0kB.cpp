#include <bits/stdc++.h>
using namespace std;
#define N 47000
bool a[N+5];
vector < int > prime;
vector < long long > fac;
inline void seive(long long num){
//bool a[num+5];
memset(a,0,sizeof(a));
for(int i = 3 ; i*i <= num ; i+= 2)
  if(!a[i])
     for(int j = i*i ; j<= num ; j+= 2*i)
       a[j] = 1;
prime.push_back(2);
for(int i = 3 ; i<= num ; i+= 2)
    if(!a[i])
       prime.push_back(i);
}

long long factor(long long n){
 long long ans = 1;
 for(int i = 0 ; prime[i]*prime[i] <= n && i < prime.size(); i++){
       int p = prime[i];
       if(n%p == 0){
          int counter = 0;
          while(n%p == 0){
             n/= p;
             counter++;
          }
          fac.push_back(p);
          ans *= (counter+1);
       }
 }
 if(n > 1) {
   ans *= 2;
   fac.push_back(n);
 }
 return ans;
}

unsigned long long phi(int num){
  unsigned long long ans = num;
  for(int i = 0 ; i< fac.size() ; i++){
      ans = ans/fac[i]*(fac[i]-1);
  }
//  cout << ans << endl;
  return ans;
}

int main()
{
   long long n;
   seive(47000);
   while(~scanf("%lld", &n)){
       long long temp =  factor(n);
       long long temp1 = phi(n);
  //     cout << temp << ' ' << temp1 << endl;
       cout << n - temp - temp1 + 1 << endl;
       fac.clear();
   }

}
