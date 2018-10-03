#include <bits/stdc++.h>
using namespace std;
double call(int a , int b , int depth){
     if(a==0 || b==0) return 0;
     if(depth>=25) return 0;
     int c = min(a,b);
     double ret  = 0;
     ret += 1+call(a-c,b+c,depth+1)*.5+call(a+c,b-c,depth+1)*.5;
     return ret;
}
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
       int a , b;
       scanf("%d%d",&a,&b);
       double res  = call(a,b,0);
       double prob = (double) a/((double) a + (double) b);
       printf("Case %d: %.6lf %.6lf\n",cs++ ,res , prob);
    }
    return 0;
}
