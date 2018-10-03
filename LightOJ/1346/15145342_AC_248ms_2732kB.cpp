#include <bits/stdc++.h>
using namespace  std;

#define N 400005
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
#define write() freopen("out.txt", "w" , stdout)
#define read() freopen("in.txt" , "r", stdin)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
#define EPS 1e9

inline int dcmp (double x) { return x < -EPS ? -1 : (x > EPS); }

class PT {
public:
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    double Magnitude() {return sqrt(x*x+y*y);}

    bool operator == (const PT& u) const { return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0; }
    bool operator != (const PT& u) const { return !(*this == u); }
    bool operator < (const PT& u) const { return dcmp(x - u.x) < 0 || (dcmp(x-u.x)==0 && dcmp(y-u.y) < 0); }
    bool operator > (const PT& u) const { return u < *this; }
    bool operator <= (const PT& u) const { return *this < u || *this == u; }
    bool operator >= (const PT& u) const { return *this > u || *this == u; }
    PT operator + (const PT& u) const { return PT(x + u.x, y + u.y); }
    PT operator - (const PT& u) const { return PT(x - u.x, y - u.y); }
    PT operator * (const double u) const { return PT(x * u, y * u); }
    PT operator / (const double u) const { return PT(x / u, y / u); }
    double operator * (const PT& u) const { return x*u.y - y*u.x; }
};

void printPoint(PT a){
   cout << a.x << ' ' << a.y << endl;
}
double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double dist(PT p, PT q)   { return sqrt(dist2(p,q)); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
    b=b-a; d=c-d; c=c-a;
//    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b*cross(c, d)/cross(b, d);
}



double SignedArea(PT a,PT b,PT c){ //The area is positive if abc is in counter-clockwise direction
    PT temp1(b.x-a.x,b.y-a.y),temp2(c.x-a.x,c.y-a.y);
    double save =  0.5*(temp1.x*temp2.y-temp1.y*temp2.x);
    if(save < 0) save *= -1;
    return save;
}


double area(PT a , PT b , PT c){
    printPoint(a); printPoint(b) ; printPoint(c);
    double ret = a.x*b.y + b.x*c.y + c.x*a.y;

    ret -= a.y*b.x + b.y*c.x + c.y*a.x;

    ret *= .5;

    if(ret < 0) ret *= -1;
    return ret;
}

PT x;


double slope(PT a , PT b){
    double y = b.y-a.y;
    double x = b.x-a.x;
    if(x == 0) return inf;
    if(y == 0) return 0;
    return y/x;
}

double length(PT a , PT b){
   double ret = (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
   return sqrt(ret);
}

int main()
{
    int test , cs=  1;
    sca(test);
    while(test--){
         int n ,a;
         PT b;
         std::vector<PT> v;
         scaa(n,a);
        // set point
         x.x = a;
         x.y = 0;


         F(i,n){
            scanf("%lf%lf",&b.x,&b.y);
            v.push_back(b);
         }

         PT mmax = v[0];

         double res  = 0;
         for(int i = 0 ; i< n-1  ;i++){
               PT temp = ComputeLineIntersection(x,mmax,v[i], v[i+1]);

               bool flag = 0;
               if(slope(x,v[i]) > slope(x,mmax)){
                  mmax = v[i];
                  flag = 1;
               }
               if(slope(x,v[i+1]) > slope(x,mmax)){
                  mmax = v[i+1];
                  flag = 1;
               }

               if(flag) res += length(temp,mmax);

         }

         printf("Case %d: %.6lf\n",cs++ , res);


    }
}
