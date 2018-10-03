#include <bits/stdc++.h>
using namespace  std;

#define N 400005
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pll pair < int , int>
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


struct st{
   pll x;
   int pos;
} p[N];

pll g;

ll disSq(pll a , pll b){
     ll x = a.ff - b.ff;
     ll y = a.ss - b.ss;
     ll ret = x*x+y*y;
     return ret;
}

ll triArea(pll a , pll b , pll c){
    // if anti clock wise positive else negative
    ll area  = a.ff*b.ss + b.ff*c.ss+c.ff*a.ss;
    area -= a.ss*b.ff+ b.ss*c.ff+c.ss*a.ff;
    return area;
}

bool convexComp(pll a , pll b){
    // pll a = x.x , b = y.x;
    ll area = triArea(g,a,b);
    if(area > 0) return true;
    else if( area == 0 && disSq(g,a) < disSq(g,b))
       return true;
    return false;
}

pll a[N];

bool cmp(st p , st q){
     pll a , b;
     a = p.x;
     b = q.x;
     if(a.ff == b.ff) return a.ss < b.ss;
     else return a.ff < b.ff;
}


int main()
{
//    read();
    int test  , cs = 1;
    sca(test);
    while(test--){
        int n;
        sca(n);

        for(int i = 0 ; i< 3*n ; i++){
           scaa(a[i].ff , a[i].ss);
           p[i].x = a[i];
           p[i].pos = i;
        }
        sort(p,p+3*n,cmp);

//        sort(a,a+3*n);
//        for(int i = 0 ; i< 3*n ; i++){
////           cout << p[i].x.ff << ' ' << p[i].x.ss << endl;
//            cout << a[i].ff << ' ' << a[i].ss << endl;
//        }


        for(int i = 0 ; i<3* n ; i+=3){
              printf("%d %d %d\n",p[i].pos+1,p[i+1].pos+1,p[i+2].pos+1);
        }
    }
    return 0;
}
