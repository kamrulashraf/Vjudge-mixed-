#include <bits/stdc++.h>
using namespace std;

bool comp(int a , int b){
   return a>b;
}
int main()
{
    int n;
    scanf("%d",&n);
    int flag = 0;
    for(int i = 0 ; i< n ; i++){
         int a , b, c;
         scanf("%d%d%d",&a,&b,&c);
         if(a+b <= c) flag = 1;
         if(b+c <= a) flag = 1;
         if(c+a <= b) flag = 1;
    }
    if(flag) printf("NO\n");
    else printf("YES\n");
}
