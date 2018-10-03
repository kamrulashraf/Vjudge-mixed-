#include <bits/stdc++.h>
using namespace std;
#define N 705
#define inf  1e9;
struct pt
{
	int x , y;
	pt(int _x , int _y){
		 x = _x ; y = _y;
	}
};


double call(pt a , pt b){
     if(a.x == b.x && a.y == b.y) return inf;

	 double x = b.x - a.x;
	 double y = b.y - a.y;
	 if(x == 0) return inf;
	 return (double) y/x;
}
int main()
{
	 int test , cs = 1;
	 scanf("%d",&test);
	 while(test--){
	 	 int n;
	 	 scanf("%d",&n);

	 	 vector < pt > v;
	 	 for(int i = 0 ; i< n ; i++){
	 	 	int x , y;
	 	 	scanf("%d%d",&x,&y);
	 	 	v.push_back(pt(x,y));

	 	 }
         map < double , int > mark;
         int mmax = 0;
	 	 for(int i = 0 ; i< n-1 ; i++){
	 	 	mark.clear();
	 	 	 for(int j = i+1 ; j< n ; j++){
                 double slope = call(v[i] , v[j]);
                 mark[slope]++;
                 mmax = max(mmax, mark[slope]);
//                 cout << slope << ' ';
	 	 	 }
//	 	 	 cout << mmax << endl;
	 	 }
	 	 v.clear();

	 	 printf("Case %d: %d\n",cs++ ,mmax+1);
	 }
}
