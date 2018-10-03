#include <bits/stdc++.h>
using namespace std;
bool a[1000009];
vector < long long > prime;
void seive(){
    int n = 46500;
    for(int i = 3 ; i*i <= n ; i+=2)
       if(a[i] == 0)
         for(int j = i*i ; j<= n ; j+=2*i)
            a[j] = 1;
    prime.push_back(2);
    for(int i =3 ;i <= n ; i+=2)
       if(a[i]==0) prime.push_back(i);
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
           if(a[i-b] == 0)
             counter++;
        return counter;
}
int main()
{
    seive();
    int test , cs= 1;
    scanf("%d", &test);
    while(test--){
        long long a , b;
        scanf("%lld %lld", &a , &b);
        long long temp = segmentSeive(a,b);
        printf("Case %d: %lld\n", cs++ , temp);

    }
}
