#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y)  for(int i=x;i<y;i++)
#define ull    unsigned long long 
int target;

ull call(ull n , ull temp){
    if(n==target) return n*n/temp;
    ull nn = n*n;
    ull g = __gcd(nn,temp);
    // cout << nn << ' ' << temp << ' ' << g << endl;
    nn/=g;
    temp /= g;
    ull ret = nn*call(n-1,temp);
    return ret;
}

int main()
{

     ull n, temp = 120;
     scanf("%llu",&n);
     target = n-5+1;
     ull res = call(n,temp);
     printf("%llu\n",res);
}