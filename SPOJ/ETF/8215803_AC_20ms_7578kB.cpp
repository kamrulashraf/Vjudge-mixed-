#include <bits/stdc++.h>
using namespace std;
#define NN 1000005
int phi[NN];
bool mark[NN];
void precal(int n){
     phi[0] = 1;
     for(int i = 1 ; i<= n ; i++) phi[i] = i;

     for(int i =2 ; i<= n ; i++){
         // if prime
         if(mark[i] == 0){
              phi[i]--; // if prime phi[i] = i-1;
              for(int j = 2*i ; j<= n ; j+=i){
                    mark[j] = 1; //j is not prime
                    phi[j] = phi[j]/i*(i-1); // formula
              }
         }
     }
}
int main()
{

     precal(1000000);
     int test , cs = 1;
     scanf("%d",&test);
     while(test--){
        int n;
        scanf("%d",&n);
        int res = phi[n];
        printf("%d\n",res);
     }
     return 0;
}
