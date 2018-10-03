#include <bits/stdc++.h>
using namespace std;

void call(int n){
     if(n == 1){
         printf("A");
         return ;
     }
     if(n == 2){
         printf("B");
         return ;
     }
     if(n&1){
        call(n/2);
        printf("A");
     }
     else{
        call((n-2)/2);
        printf("B");
     }
}
int main()
{
     int n;
     cin >> n;
     call(n);
     cout << endl;
     return 0;
}
