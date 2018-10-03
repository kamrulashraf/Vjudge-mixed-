#include <cstdio>
#include <iostream>
using namespace std;
int gcd(int a , int b){
    if(a%b==0) return b; else gcd(b, a%b);
    }
int main()
{
    long int i , j , n , c, a , b,d , h;
    while(cin >> n >> c)
    {
       if(n == 0 && c == 0) break;
       if(c>n/2) c = n-c;
       d = 1,h = 1;
       for(i = n-c+1,j=1 ; i<=n ; i++ , j++)
       {
           d = d*i;
           h = h*j;
           int m = gcd(d,h);
           d = d/m;
           h = h/m;
       }
       cout << d/h << endl;
    }
 return 0;
}
