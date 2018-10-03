#include <bits/stdc++.h>
using namespace std;
#define ull          unsigned long long
#define ll           long long
#define N            31700000
vector < ll > prime;
bool a[N+5];

void seive(long long num){
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

void factor( ull num){
    int flag = 0;
    for(int i = 0 ; prime[i]*prime[i] <= num ; i++){
        ll p = prime[i];
        if(num%p == 0){
            int counter = 0;
            while(num%p==0){
               counter++;
               num/=p;
            }
          if(flag) printf(" ");
          else flag = 1;
          printf("%lld^%d",p,counter);
        }
    }
   if(num > 1) printf(" %llu^1",num);
   cout << "\n";
   return;
}
int main()
{
      seive(N);
      ull num;
      while(cin >> num && num){
         factor(num);
      }

}
