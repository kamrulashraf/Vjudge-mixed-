#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define NN 50000
#define inf 1e14
bool a[50000];
int nn ;
       std::vector< ll > v;

std::vector< int > prime;
    inline void seive(long long num){

    for(int i = 3 ; i*i <= num ; i+= 2)
      if(!a[i])
         for(int j = i*i ; j<= num ; j+= 2*i)
           a[j] = 1;
    prime.push_back(2);
    for(int i = 3 ; i<= num ; i+= 2)
        if(!a[i])
           prime.push_back(i);
   }

vector< ll > factor(ll num){
    std::vector< ll > v;
    for(int i = 0 ; i < prime.size() && prime[i]*prime[i]<= num ; i++){
          ll p = prime[i];
          if(num%p == 0){

              ll counter = 1;
              while(num%p==0){
                 num/=p;
                 counter *= p;
              }
              v.push_back(counter);
          }
    }
    if(num>1){
        v.push_back(num);
    }
    return v;
}

ll call(int i,ll mul){
	  if(i==nn){
	  	 return mul;
	  }
	 long long temp = mul*v[i];
	 long long p = call(i+1,mul+v[i]);
	 long long p1 = call(i+1,temp);
	 return min(p,p1);
}
int main()
{
   seive(50000);
   ll n;
   int cs = 1;
   while(cin >> n){
       if(n==0) break;
//       if(n==1){
//          cout <<  1 << endl;
//          continue;
//       }
       v = factor(n);
       int sz = v.size();
       nn = sz;
       long long mmin = call(0,1);
       if(mmin == n) mmin++;
       printf("Case %d: %lld\n",cs++ , mmin);
       v.clear();
   }
   return 0;
}
