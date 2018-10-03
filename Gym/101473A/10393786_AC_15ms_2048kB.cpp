
#include <bits/stdc++.h>
using namespace std;
#define N 1000005

int main()
{
     int a , b , c;
     bool flag = 0;
     cin >> a >> b >> c;
     if(a== b && c != a){
         printf("C\n");
     }
     else if(a == c && c != b){
         printf("B\n");
     }
     else if(b == c && a != b){
        printf("A\n");
     }
     else printf("*\n");
    return 0;
}
