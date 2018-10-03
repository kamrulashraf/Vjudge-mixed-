// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
#include <bits/stdc++.h>
using namespace std;
#define N 100005
int a[N] , b[N];
double x[N];
double element[N];
int main()
{
    // freopen("inputf.in","r",stdin);
    int n , p;
    scanf("%d%d",&n,&p);

    for(int i = 0 ; i< n ; i++){
        scanf("%d%d",&a[i],&b[i]);
        int temp = b[i]/p;
        x[i] = temp - (a[i]-1)/p;
        element[i] = b[i]-a[i]+1;
    }
   // for(int i = 0 ; i< n ; i++){
   //     cout << x[i] << ' ' << element[i] << endl ;
   // } cout << endl ;
    double res = 0.0;
    for(int i = 0 ; i< n ; i++){
          double temp = x[i]*element[(i+1)%n];
          temp += (element[i]-x[i])*x[(i+1)%n];
          double totElement = element[i]*element[(i+1)%n];
          temp*=1000;
          res += temp/totElement;
    }

    res *= 2;
    printf("%.8lf\n",res);
}
