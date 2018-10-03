#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
int main()
{
    int n;
    scanf("%d",&n);
    double res = 1;
    int counter = 0;
    for(int i = n; i>= 0 ; i--){
        counter++;
        res *= i / (double) n;
        if(res <= .5) break;
    }
    printf("%d\n",counter);
}