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
struct point
{
	double x , y , z;
	void input(){
		scanf("%lf%lf%lf",&x,&y,&z);
	}

};


point dis;
point p , q , t;


point sub(point a , point b){
	point temp ;
	temp.x = a.x - b.x;
	temp.y = a.y - b.y;
	temp.z = a.z - b.z;
	return temp;
}

double fun(double val){
	double xx = val*dis.x + p.x;
	double yy = val*dis.y + p.y;
	double zz = val*dis.z + p.z;
    xx -= t.x;
    yy -= t.y;
    zz -= t.z;
    return xx*xx + yy*yy + zz*zz;
}

int main()
{
	// freopen("in.txt" , "r" , stdin);
	int test , cs = 1;
	sca(test);
	while(test--){
        
        p.input();
        q.input();
        t.input();
        dis = sub(q,p);

        double b = 0.0 , e = 1.0;
        
        while(e-b > EPS){
            double m1 =  b + (e-b)/3.0;
            double m2 = b + (2.0*(e-b))/3.0;
            if(fun(m1)   < fun(m2))
            	e = m2;
            else b = m1;

        }

        double res = sqrt(fun(b));
        printf("Case %d: %.8lf\n",cs++ , res);



	}
}
