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
	double x , y;
	void input(){
	    scanf("%lf %lf",&x,&y);
	}

	void print(){
		cout << x << ' ' <<  y << endl;
	}
};
point   a , b , c , d, t, dis1 , dis2;

point sub(point a , point b){
    point temp;
    temp.x = a.x-b.x;
    temp.y = a.y-b.y;
    return temp;
}



double fun(double val){
	point man1 , man2;
	man1.x = dis1.x*val+a.x;
	man1.y = dis1.y*val+a.y;
	man2.x = dis2.x*val+c.x;
	man2.y = dis2.y*val+c.y;


    double xx = man1.x - man2.x;
    double yy = man1.y - man2.y;

    return xx*xx + yy*yy;
}
int main()
{
	 // freopen("in.txt" , "r" ,stdin);
	int test , cs = 1;
	sca(test);
	while(test--){
        a.input();
        b.input();
        c.input();
        d.input();


        dis1 = sub(b,a);
        dis2 = sub(d,c);

  

        double be  = 0 , en = 1.0;


        while( en -be > EPS){
        	double m1 = be + (en-be)/3;
        	double m2 = be + (2.0*(en-be))/3.0;
        	if(fun(m1) < fun(m2)){
        		en = m2;
        	}
        	else be = m1;
        }

        double res = sqrt(fun(be));

        printf("Case %d: %.6lf\n",cs++ , res);

	}
}
