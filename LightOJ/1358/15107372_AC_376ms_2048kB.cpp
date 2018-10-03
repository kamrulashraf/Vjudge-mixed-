#include <bits/stdc++.h>
using namespace  std;


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
#define EPS 1e-6
#define inf 1e9
const double PI=acos(-1.0);

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

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double dist(PT p, PT q)   { return sqrt(dist2(p,q)); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

double CirclishArea(PT a, PT b, PT cen, double r) {
    double ang = fabs(atan2((a-cen).y, (a-cen).x) - atan2((b-cen).y, (b-cen).x));
    if (ang > PI) ang = 2*PI - ang;
    return (ang * r * r) / 2.0;
}
//intersection of circle and triangle


double SignedArea(PT a,PT b,PT c){ //The area is positive if abc is in counter-clockwise direction
    PT temp1(b.x-a.x,b.y-a.y),temp2(c.x-a.x,c.y-a.y);
    return 0.5*(temp1.x*temp2.y-temp1.y*temp2.x);
}



vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r) {
    vector<PT> ret;
    b = b-a;
    a = a-c;
    double A = dot(b, b);
    double B = dot(a, b);
    double C = dot(a, a) - r*r;
    double D = B*B - A*C;
    if (D < -EPS) return ret;
        ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
    if (D > EPS)
        ret.push_back(c+a+b*(-B-sqrt(D))/A);
    return ret;
}


double CicleTriangleIntersectionArea(PT a, PT b, PT c, double radius) {
    vector<PT>g = CircleLineIntersection(a, b, c, radius);
    if (b < a) swap(a, b);
    if (g.size() < 2) return CirclishArea(a, b, c, radius);
    else {
        PT l = g[0], r = g[1];
        if (r < l) swap(l, r);
        if (b < l || r < a) return CirclishArea(a, b, c, radius);
        else if (a < l && b < r) return fabs(SignedArea(c, b, l)) + CirclishArea(a, l, c, radius);
        else if (r < b && l < a) return fabs(SignedArea(a, c, r)) + CirclishArea(r, b, c, radius);
        else if (a < l && r < b) return fabs(SignedArea(c, l, r)) + CirclishArea(a, l, c, radius) + CirclishArea(b, r, c, radius);
        else return fabs(SignedArea(a, b, c));
    }
    return 0;
}
//intersection of circle and simple polygon (vertexes in counterclockwise order)
double CirclePolygonIntersectionArea(vector<PT> &p, PT c, double r) {
    int i, j, k, n = p.size();
    double sum = 0;
    for (i = 0; i < p.size(); i++) {
        double temp = CicleTriangleIntersectionArea(p[i], p[(i+1)%n], c, r);
        double sign = SignedArea(c, p[i], p[(i+1)%n]);
        if (dcmp(sign) == 1) sum += temp;
        else if (dcmp(sign) == -1) sum -= temp;
    }
    return sum;
}


double ComputeSignedArea(const vector<PT> &p) {
    double area = 0;
    for(int i = 0; i < p.size(); i++) {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return area / 2.0;
}



PT cen;
std::vector< PT > v;
double p;
int main()
{

    int n;
    int test , cs =1;
    sca(test);
    while(test--){
         sca(n);

         for(int i = 0 ; i< n ; i++){
             PT a;
             scanf("%lf %lf",&a.x , &a.y);
             v.push_back(a);
         }
         scanf("%lf%lf%lf",&cen.x , &cen.y, &p);
         p /= 100;

         double area = ComputeSignedArea(v);


         double b , e;
         b = 0 ;
         e = inf;

         while(e-b> EPS){
             double m  =(b+e)/2.0;
             double a = CirclePolygonIntersectionArea(v, cen, m);
             double per = a/area;


//             cout << b << ' '<< e << ' '  << a << ' ' << area << ' ' << per << endl;
//             cout << per << endl;
             if( p -per > EPS){
                 b = m;
             }
             else e = m;
         }

//         double a = CirclePolygonIntersectionArea(v, cen,(double) 1);
//             double per = a/area;
//             per *= 100.0;
//
//             cout << per << ' ' << area << ' ' << a << endl;
         ll res = round(e);
//         cout << b << '#' << e << ' ' << CirclePolygonIntersectionArea(v, cen,(double) e)/area << endl;
//        cout <<  b << - e << endl;
         printf("Case %d: %lld\n",cs++ , res);
         v.clear();




    }
}
