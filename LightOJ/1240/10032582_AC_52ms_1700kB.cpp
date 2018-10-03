#include <bits/stdc++.h>
using namespace std;
#define EPS  1e-9
struct point
{
    double  x, y , z;
} a , b , p, ss;

double xx , yy , zz;
double fun(double m){
    point temp;
    temp.x  =  m*ss.x+a.x; // find the point
    temp.y = m*ss.y+a.y;
    temp.z = m*ss.z+a.z;
    xx = temp.x - p.x;
    yy =  temp.y - p.y;
    zz = temp.z - p.z;
    return (xx*xx + yy*yy + zz*zz);

}
int main()
{
    // freopen("in.txt","r" , stdin);    scanf("%d",&test);
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
          scanf("%lf%lf%lf",&a.x, &a.y , &a.z);
          scanf("%lf%lf%lf",&b.x, &b.y , &b.z);
          scanf("%lf%lf%lf",&p.x, &p.y , &p.z);
          ss.x  =  b.x - a.x;
          ss.y = b.y  - a.y;
          ss.z = b.z - a.z;

          double be = 0 , en  = 1.0;
          while( en - be > EPS){
                double m1 = be + (en-be)/3;
                double m2 =  be+ (2.0*(en-be))/3.0;
                if(fun(m1) < fun(m2))
                     en = m2;
                else be = m1;
          }

          double res = sqrt(fun(be));
          printf("Case %d: %.8lf\n",cs++, res);
    }
    return 0;
}
