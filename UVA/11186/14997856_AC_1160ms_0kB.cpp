#include <bits/stdc++.h>
using namespace std;
#define N 505
// #define PI 2*acos(0.0)
#define PI acos(-1.0)
#define ll long long
#define EPS 1e-12
struct pt
{
	double  x, y;
};


pt cnv(double angle , double r){
	pt ret;
	ret.x = r*cos(angle);
	ret.y = r*sin(angle);

	return ret;
}

double area(pt a , pt b , pt c) {
    double ret = 0.0;

    ret += a.x*b.y + b.x*c.y + c.x * a.y;
    ret -= a.y* b.x + b.y*c.x+c.y*a.x;
    return ret;
}


int main()
{
//    freopen("out.txt", "w" , stdout);
    int n ;
    double r;
    while(~scanf("%d%lf",&n,&r)){
    	 if(n== 0 && r == 0) break;
    	 pt point[N];
    	 for(int i = 0 ; i< n ; i++){
    	 	 double angle;
    	 	 scanf("%lf",&angle);
    	 	 angle = (PI*angle)/180.0;
    	 	  point[i] = cnv(angle,r);
//    	 	  cout << point[i].x << '#' << point[i].y << endl;
    	 }
    	 double res = 0.0;
    	 for(int i = 0 ; i< n ; i++){
    	 	 for(int j = i+1 ; j< n ; j++){
    	 	 	 for(int k = j+1 ; k < n ; k++){
    	 	 	 	double save = (area(point[i] , point[j] , point[k]));
    	 	 	 	if(save < 0) save *= -1;
    	 	 	 	res += save;
    	 	 	 }
    	 	 }
    	 }
    	 res /= 2.0;
    	 ll temp = round(res);
    	 printf("%lld\n",temp);
    }
    return 0;
}
