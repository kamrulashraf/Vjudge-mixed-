#include <bits/stdc++.h>
using namespace std;
#define NN 10005

long long a[NN+10], mark[NN];
long long ncr[NN];
std::vector< int > prime;
void seive(int n){
    for(int i = 2 ; i<= n ; i++){
          if(a[i]==0){
              int temp = i*i;
              for(int j = i ; j<= n ; j+= i){
                   if(j%temp==0){
                      a[j] = -1;
                   }
                   else if(a[j]!=-1){
                      a[j]++;
                   }
              }
          }
    }
    for(int i = 2 ; i<= n ; i++){
         if(a[i] == 1)
             prime.push_back(i);
    }
    a[1] = 1;
    for(int i = 2 ; i <= n ; i++){
          if(a[i] == -1) a[i] = 0;
          else if(a[i]&1) a[i] = -1;
          else a[i] = 1;
    }
}


void factor(int n){
    for(int i = 1 ; i*i < n ; i++){
       if(n%i==0)
         mark[i]++,
         mark[n/i]++;
    }
    int temp = sqrt(n);
    if(temp*temp==n) mark[temp]++;
}





void NCR(){
    ncr[4]=1;
    for(int i=5;i<NN;i++){
        ncr[i] = ncr[i-1]*i/(i-4);
    }
}
int main()
{
     seive(10005);
     NCR();
     int test , cs = 1;
     scanf("%d",&test);
     while(test--){
        memset(mark,0,sizeof mark);
        int n ;
        scanf("%d",&n);
        for(int i = 0 ; i< n ; i++){
             int var;
             scanf("%d",&var);
             factor(var);
        }
        long long res = 0;
        for(int i = 1 ; i<= NN -5 ; i++){
            res += a[i]*ncr[mark[i]];
        }
        printf("Case %d: %lld\n",cs++ , res);
     }
     return 0;
}
