#include <bits/stdc++.h>
using namespace std;
int main()
{

     int a , b , c , d;
     while(scanf("%d%d%d%d",&a,&b,&c,&d)){
        if(a == 0 && b == 0 && c == 0 && d == 0) break;
        if(a > b) swap(a,b);
        if(c > d) swap(c,d);
        int res = (c-b);
        int res1 = d-a;
        printf("%d %d\n",res,res1);
     }
}
