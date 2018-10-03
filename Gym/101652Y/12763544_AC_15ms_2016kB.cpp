#include <bits/stdc++.h>
using namespace  std;

#define N 3000000
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define MP make_pair
#define PB push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define EPS 1e-9

double fun(double a , double k ,double p , double x){
     double temp = (k*p)/a + a*x;
     return temp;
}
int main()
{

    double k , p , x;
    cin >> k >> p >> x;



    double b = 0 , e = 500 ;


    while( e -b > EPS){
        double m1 = b + (e-b)/3.0;
        double m2 = b+ (2*(e-b))/3.0;
        if(fun(m1,k,p,x) < fun(m2,k,p,x)){
           e = m2;
        }
        else b = m1;
    }
//      cout << b << endl;
    double bb =max(b-10 , 0.0);
    double res = 4e15;
    for(int i = bb ; i<= 5000 ; i++){
       res = min(res,fun(i,k,p,x));
    }
    printf("%.3lf\n",res);
}
