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

double SignedArea(PT a,PT b,PT c){ //The area is positive if abc is in counter-clockwise direction
    PT temp1(b.x-a.x,b.y-a.y),temp2(c.x-a.x,c.y-a.y);
    return 0.5*(temp1.x*temp2.y-temp1.y*temp2.x);
}

bool XYasscending(PT a,PT b) {
    if(abs(a.x-b.x)<EPS) return a.y<b.y;
    return a.x<b.x;
}

//Makes convex hull in counter-clockwise direction without repeating first point
//undefined if all points in given[] are collinear
//to allow 180' angle replace <= with <
void MakeConvexHull(vector<PT>given,vector<PT>&ans){
    int i,n=given.size(),j=0,k=0;
    vector<PT>U,L;
    ans.clear();
    sort(given.begin(),given.end(),XYasscending);
    for(i=0;i<n;i++){
        while(true){
            if(j<2) break;
            if(SignedArea(L[j-2],L[j-1],given[i])<=EPS) j--;
            else break;
        }
        if(j==L.size()){
            L.push_back(given[i]);
            j++;
        }
        else{
            L[j]=given[i];
            j++;
        }
    }
    for(i=n-1;i>=0;i--){
        while(1){
            if(k<2) break;
            if(SignedArea(U[k-2],U[k-1],given[i])<=EPS) k--;
            else break;
        }
        if(k==U.size()){
            U.push_back(given[i]);
            k++;
        }
        else{
            U[k]=given[i];
            k++;
        }
    }
    for(i=0;i<j-1;i++) ans.push_back(L[i]);
    for(i=0;i<k-1;i++) ans.push_back(U[i]);
}


double callen(vector < PT > v){
    if(v.size() <= 1) return 0;
    if(v.size()) v.push_back(v[0]);
    int sz = v.size();
    double res = 0.0;
    for(int i = 0 ; i < sz-1 ; i++){
        res += dist(v[i] , v[i+1]);
    }
    return res;
}

int cost[N] , l[N];

int main()
{
    int n , cs =1;
    while(~sca(n)){
        if(n == 0) break;
        std::vector< PT > v;
        F(i,n){
            double  x , y;
            scanf("%lf %lf %d %d",&x, &y , &cost[i] , &l[i]);
            v.push_back(PT(x,y));
        }

        double mmin = inf;
        ll bits = 0;
        double wood;
        for(int i = 0 ; i < (1<<n) ; i++){
             std::vector< PT > temp;
             ll cc  = 0 ;
             double length = 0;
             for(int j = 0 ; j< n ; j++){
                 if(i & (1<<j)){
                    temp.push_back(v[j]);
                 }
                 else{
                    cc += cost[j];
                    length += l[j];
                 }
             }
             vector < PT > res;
             MakeConvexHull(temp, res);
             double len1 = callen(res);

             if(len1 <= length){
                 if(cc <= mmin){
                     if(cc == mmin){
                        if(__builtin_popcount(bits) > __builtin_popcount(i)){
                            bits = i;
                            mmin = cc;
                            wood = length - len1;
                        }
                     }
                     else{
                        mmin = cc;
                        bits = i;
                        wood = length - len1;
                     }
                 }
             }
             temp.clear();

        }
//        cout << wood << ' ' << mmin << ' ' << bits << endl;
        if(cs != 1) printf("\n");
        printf("Forest %d\n",cs++);
        printf("Cut these trees:");
        for(int i = 0 ; i< n ; i++){
           if(!(bits&(1<<i))){
              printf(" %d",i+1);
           }
        }
        printf("\n");
        printf("Extra wood: %.2lf\n",wood);
        v.clear();

    }
}
