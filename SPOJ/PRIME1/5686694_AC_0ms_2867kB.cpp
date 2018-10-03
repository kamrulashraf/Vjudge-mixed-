#include <bits/stdc++.h>
using namespace std;
bool a[100009];
vector < int > prime;
void seive(){
     int num = 66000;
     for(int i = 3 ; i*i <= num ; i+= 2)
       if(a[i]==0)
          for(int j = i*i ; j<= num ; j+= 2*i)
             a[j] = 1;
     prime.push_back(2);
     for(int i = 3 ; i<= num ; i++)
        if(!a[i])
           prime.push_back(i);

}
void segmentSeive(long long b , long long e){
     memset(a,0,sizeof(a));
     for(int i = 0 ; prime[i]*prime[i] <= e && i < prime.size(); i++){
           long long p = prime[i];
           long long start = p*p;
           if(p<b)
              start = (b+p-1)/p*p;
           for(int j = start ; j<= e ; j+= p)
              a[j-b] = 1;

     }
     int i;
     if(b == 1) i = b+1;
     else i = b;
     for( ; i<= e ; i++)
        if(a[i-b] == 0)
            printf("%d\n",i);
}
int main()
{
  seive();
 // for(int i = 0 ; i< 20 ; i++)  cout << prime[i] << endl;
  int test, cs = 1;
  scanf("%d", &test);
  while(test--){
        long long a, b;
        scanf("%lld %lld", &a , &b);
        segmentSeive(a,b);
        printf("\n");

  }
}
