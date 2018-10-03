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
#define EPS 1e-9

struct point
{
	double x , y;
	point(){}
	point(double a , double b){
		x = a ; y = b;
	}
};

struct line
{
	double a , b , c;
	line() {}
	line(point p1 , point p2){
		a = p1.y - p2.y;
		b = p2.x-p1.x;
		c = p1.x*p2.y - p2.x*p1.y;
	}

};

inline bool eq(double a , double b){
	return fabs(a-b) < EPS;
}

bool intersection(line l1 , line l2 , point &p){
	double det = l1.a*l2.b - l1.b*l2.a;
	if(eq(det,0)) return false;
	p.x = (l1.b*l2.c-l2.b*l1.c)/det;
	p.y = (l1.c*l2.a - l2.c*l1.a)/det;
	return true;
}

double slope(point a , point b){
    double y = b.y-a.y;
    double x = b.x-a.x;
    if(x == 0) return inf;
    if(y == 0) return 0;
    return y/x;
}

double area(point a , point b , point c){

    double ret = a.x*b.y + b.x*c.y + c.x*a.y;

    ret -= a.y*b.x + b.y*c.x + c.y*a.x;

    ret *= .5;

    if(ret < 0) ret *= -1;
    return ret;
}


double length(point a , point b){
   double ret = (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
   return sqrt(ret);
}
int main()
{
	int test , cs = 1;
	sca(test);
	while(test--){
		 int n , m;
		 scaa(n,m);
		 point x(m,0);
		 vector < point > v;
		 F(i,n){
		    double a , b;
            scanf("%lf%lf",&a,&b);
            v.push_back(point(a,b));
		 }

         point mmax = v[0];
         double res = 0;
		 for(int i = 0 ; i < n-1 ; i++){
              line temp1(v[i], v[i+1]);
              line temp2(x,mmax);
              point temp;
              intersection(temp1,temp2,temp);


              bool f = 0;

              if(slope(x,v[i]) > slope(x,mmax)){
                 mmax = v[i];
                 f = 1;
              }


              if(slope(x,v[i+1]) > slope(x,mmax)){
                 mmax = v[i+1];
                 f = 1;
              }

              if(f == 1){
                    res += length(temp,mmax);
//                    cout << temp.x << ' ' << temp.y << ' ' << mmax.x << ' ' << mmax.y << ' ' << res <<  endl;
              }

		 }
		 printf("Case %d: %.8lf\n",cs++ , res);

	}
}
