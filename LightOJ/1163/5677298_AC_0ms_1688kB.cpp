#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main()
{
unsigned long long a, temp,i,cs = 1;
int test;
cin >> test;
while(test--){
    scanf("%llu", &a);
    printf("Case %d:", cs++);
    ull mod = a%9;
    temp = (a/9)*10+mod;
    for(i = temp -3; i<= temp+3 ; i++){
    if(i-i/10 == a)
    printf(" %lld",i);
}
printf("\n");

}
return 0;
}
