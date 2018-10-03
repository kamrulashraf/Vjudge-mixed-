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

#define EPS 1e-12
#define NEX(x) ((x+1)%n)
#define PRV(x) ((x-1+n)%n)
#define RAD(x) ((x*M_PI)/180)
#define DEG(x) ((x*180)/M_PI)
const double PI=acos(-1.0);

inline int dcmp (double x) { return x < -EPS ? -1 : (x > EPS); }
//inline int dcmp (int x) { return (x>0) - (x<0); }

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

double myAsin(double val) {
    if(val>1) return PI*0.5;
    if(val<-1) return -PI*0.5;
    return asin(val);
}

double myAcos(double val) {
    if(val>1) return 0;
    if(val<-1) return PI;
    return acos(val);
}

ostream &operator<<(ostream &os, const PT &p) {
    os << "(" << p.x << "," << p.y << ")";
}

istream &operator>>(istream &is, PT &p) {
    is >> p.x >> p.y;
    return is;
}

// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p)   { return PT(-p.y,p.x); }
PT RotateCW90(PT p)    { return PT(p.y,-p.x); }

PT RotateCCW(PT p,double t) {
    return PT(p.x*cos(t)-p.y*sin(t),p.x*sin(t)+p.y*cos(t));
}

PT RotateAroundPointCCW(PT p,PT pivot,double t) {
    PT trans=p-pivot;
    PT ret=RotateCCW(trans,t);
    ret=ret+pivot;
    return ret;
}

// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c) {
    return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

double DistancePointLine(PT a,PT b,PT c) {
    return dist(c,ProjectPointLine(a,b,c));
}

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c) {
    double r = dot(b-a,b-a);
    if (fabs(r) < EPS) return a;
    r = dot(c-a, b-a)/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(PT a, PT b, PT c) {
    return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}



bool LinesParallel(PT a, PT b, PT c, PT d) {
    return dcmp(cross(b-a, c-d)) == 0;
}

bool LinesCollinear(PT a, PT b, PT c, PT d) {
    return LinesParallel(a, b, c, d)
      && dcmp(cross(a-b, a-c)) == 0
      && dcmp(cross(c-d, c-a)) == 0;
}


bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
    if (LinesCollinear(a, b, c, d)) {
        if (dcmp(dist2(a, c)) == 0 || dcmp(dist2(a, d)) == 0 ||
            dcmp(dist2(b, c)) == 0 || dcmp(dist2(b, d)) == 0) return true;
        if (dcmp(dot(c-a, c-b)) > 0 && dcmp(dot(d-a, d-b)) > 0 && dcmp(dot(c-b, d-b)) > 0)
            return false;
        return true;
    }
    if (dcmp(cross(d-a, b-a)) * dcmp(cross(c-a, b-a)) > 0) return false;
    if (dcmp(cross(a-c, d-c)) * dcmp(cross(b-c, d-c)) > 0) return false;
    return true;
}



double calll(PT a , PT b ,  PT c , PT d){
     if(LinesParallel(a, b, c, d)){
         return DistancePointLine(c, d, a);
     }
     else return 0.0;

}
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
    b=b-a; d=c-d; c=c-a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b*cross(c, d)/cross(b, d);
}

//  bool PointOnSegment(PT s, PT e, PT p) {
//      if(p == s || p == e)    return 1;
//      return dcmp(cross(s-p, s-e)) == 0
//          && dcmp(dot(PT(s.x-p.x, s.y-p.y), PT(e.x-p.x, e.y-p.y))) < 0;
//  }

bool PointOnSegment(PT p, PT r, PT q) {
   if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
       q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
      return true;

   return false;
}

bool check(PT a , PT b ,PT c , PT d){
    PT temp = ComputeLineIntersection(a, b, c, d);
   // cout << temp.x << ' ' << temp.y << endl;
   // cout << a.x << ' ' << a.y << ' ' << b.x << ' ' << b.y << endl;
   // cout << PointOnSegment(a,b,temp) << endl;
    return (PointOnSegment(a,b,temp));


}

double callls(PT a , PT b ,  PT c , PT d){

    if(LinesParallel(a, b, c, d)){
         return DistancePointLine(c, d, a);
     }
     else if(check(a,b,c,d)){
        return 0;
     }
     else{
        return min(DistancePointLine(c,d,a) , DistancePointLine(c,d,b));
     }

}
double callss(PT a , PT b , PT c , PT d){

    if(SegmentsIntersect(a, b, c, d)){

         return 0.0;
    }
    else{
        // PT temp = ProjectPointSegment(a, b, c);
        // cout << temp.x << ' ' << temp.y << endl;
        // double temp1 = dist(c,temp);
        // cout << temp1 << endl;
        double tt = min(DistancePointSegment(c,d,a), DistancePointSegment(c, d,b));
//        cout << tt << endl;
        double dd = min(DistancePointSegment(a,b,c), DistancePointSegment(a, b,d));
        // cout << tt << ' ' << dd << endl;
        return min(tt,dd);
    }
}
int main()
{
//    write();
     PT a ,  b , c , d;
     string  m , n;
     while(~scanf("%lf%lf%lf%lf",&a.x , &a.y , &b.x , &b.y)){
        getchar();
        cin >> m;
        scanf("%lf%lf%lf%lf",&c.x , &c.y , &d.x , &d.y);
        getchar();
        cin >> n;
        if(m =="END" && n == "END") break;
        double res;
        if(m == "L" && n == "L"){
             res = calll(a,b,c,d);
        }
        else if(m == "L" && n == "LS"){
                res = callls(c,d,a,b);
        }
        else if(m == "LS" && n == "L"){
            res = callls(a,b,c,d);
        }
        if(n =="LS" && m =="LS"){
            res = callss(a,b,c,d);
        }

        printf("%.5f\n",res);
     }
}
