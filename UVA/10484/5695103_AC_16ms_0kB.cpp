#include <bits/stdc++.h>
using namespace std;
vector <int> prime;
vector < long long > v;
map < long long , long long > hit;
inline void seive(long long num){
bool a[num+1];
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

void call(long long num){
  for(int i = 0 ; prime[i] <= num && i < prime.size() ; i++){
    long long temp = num;
    long long sum = 0;
    while(temp){
      sum += temp/prime[i];
      temp /= prime[i];
    }
    hit[prime[i]] = sum;
    v.push_back(prime[i]);
  }
}

int factor(long long num){
   for(int i = 0 ; prime[i]*prime[i] <= num && i < prime.size() ; i++){
     if(num%prime[i] == 0){
        while(num%prime[i] == 0){
           num/= prime[i];
           if(hit[prime[i]] == 0) return 1;
           hit[prime[i]]--;
        }
     }
   }
 if(num > 1){
     if(hit[num] == 0) return 1;
     hit[num]--;
 }
return 0;
}
int main()
{
   //freopen("a.txt", "w" , stdout);
   int test , cs = 1;
   seive(105);
   long long a , b;
   while(scanf("%lld %lld", &a , &b)==2){
         if(a==0 && b==0)
         break;
         if(b <= 0){
           printf("0\n");
           continue;
         }
         call(a);
         int flag = factor(b);
         long long ans = 1;
         for(int i = 0 ; i< v.size() ; i++){
            if(hit[v[i]] > 0){
              ans *= (hit[v[i]]+1);
            }

         }
       if(flag == 1)
       printf("0\n");
       else
       printf("%lld\n",ans);
       hit.clear();
       v.clear();
   }


}

