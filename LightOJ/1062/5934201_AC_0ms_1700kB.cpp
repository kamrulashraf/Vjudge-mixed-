#include <bits/stdc++.h>
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
using namespace std;
double solve(double a , double b , double c){
    double bi = 0.0, w;
    double e = a;
    while( e - bi > .0000001){
       w = (bi+e)/2.0;
       double h1 = sqrt(a*a-w*w);
       double h2 = sqrt(b*b-w*w);
       double h = (h1*h2)/(h1+h2);
       if(h > c){
         bi = w;
       }
       else e = w;

    }
  return bi;
}
int main()
{
   int test , cs = 1;
   cin >> test;
   while(test--){
       double a , b , c;
       cin >> a >> b >> c;
       double ans = solve(a,b,c);
       printf("Case %d: %.10lf\n",cs++ ,ans);
   }
}
