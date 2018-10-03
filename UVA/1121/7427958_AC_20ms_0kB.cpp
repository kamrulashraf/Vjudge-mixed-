#include <bits/stdc++.h>
using namespace std;
#define NN 1000005
#define inf 1e9
int a[NN];
long long cul[NN];
int main()
{
   int n , k;
   while(scanf("%d%d",&n,&k) == 2){
        a[0]=0;
        for(int i = 1 ; i<= n ;i++){
           scanf("%d",&a[i]);
        }
        for(int i = 1;i<=n;i++)
          cul[i]=cul[i-1]+a[i];
        cul[n+1] = cul[n];
        int mmin = inf;
        for(int i = 1 ; i<=n ; i++){
          int key = cul[i]+k-a[i];
          int pos = lower_bound(cul,cul+n,key)-cul;
          if(cul[pos]-cul[i-1] >= k) mmin = min(mmin,pos-i+1);
          //cout << i << ' ' <<  pos-i << ' ' << mmin << ' ' << cul[pos]-cul[i] << ' ' << pos << endl;
        }
        if(mmin == inf) mmin = 0;
        cout << mmin << endl;

   }
}
