#include <bits/stdc++.h>
using namespace std;
bool a[1000009];
vector <int> prime;
vector <long long> temp_prime;
void seive(){
 int num = 66000;
 for(int i = 3 ; i*i<= num ; i+= 2)
   if(a[i] == 0)
    for(int j = i*i ; j<= num ; j+= 2*i)
       a[j] = 1;
 prime.push_back(2);
 for(int i = 3 ; i<= num ; i+=2){
   if(a[i] == 0){
     prime.push_back(i);
   }
 }

}


int segmentSeive(long long b , long long e){
        int counter = 0;
        memset(a,0,sizeof(a));
        if(b == 1) b++;
        for(int i = 0 ; prime[i]*prime[i] <= e && i < prime.size() ; i++){
           long long p = prime[i];
           long long start= p*p;
           if(start < b)
              start = (b+p-1)/p*p;
           for(long long j = start ; j<= e ; j+= p)
             a[j-b] = 1;
        }

        for(long long i = b ; i <= e ; i++)
           if(a[i-b] == 0){
              temp_prime.push_back(i);
           }
        return counter;
}


int main()
{
  //ŝ freopen("a.txt", "w", stdout);
   seive();
   long long a,b;
   while(scanf("%lld %lld", &a, &b) != EOF){
       long long s1,s2,s3,s4, mmax = -10 , mmin = 1000010, flag = 0;
       segmentSeive(a,b);
       int temp = temp_prime.size();
       for(int i = 1; i <  temp_prime.size() ; i++){
              long long diff = temp_prime[i]-temp_prime[i-1];

              if(diff < mmin){
                 s1 = temp_prime[i-1];
                 s2 = temp_prime[i];
                 mmin = diff;
                 flag = 1;
              }
              if(diff > mmax){
                 s3 = temp_prime[i-1];
                 s4 = temp_prime[i];
                 mmax = diff;
                 flag = 1;
              }

       }
       temp_prime.clear();
       if(flag == 0)
              printf("There are no adjacent primes.\n");
       else  printf("%lld,%lld are closest, %lld,%lld are most distant.\n", s1 , s2, s3 , s4);
   }
}

