#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int a[N] , b[N];
#define pii pair < int ,int>
#define ff first
#define ss second

bool comp(pii a , pii b){
   if(a.ff > b.ff) return true;
   else if(a.ff == b.ff) return a.ss > b.ss;
   return 0;
}
int main()
{
      int n , mmax = 0;
      cin >> n;
      std::vector< pii > v;
      for(int i = 0 ; i< n ; i++){
          scanf("%d%d",&a[i],&b[i]);
          int temp = a[i] - b[i];
          v.push_back({temp,a[i]});
      }
      sort(v.begin() , v.end(), comp);

       long long res = 0;
       long long prev = 0;
      for(int i = 0 ; i< n ; i++){
            if(v[i].ss-prev >= 0){
               res += v[i].ss-prev;
               prev = 0;
            }
            else{
               prev = prev - v[i].ss;
               res += 0;
            }
//            cout << (v[i].ss - prev) << endl;
            prev += v[i].ff;
      }
      cout << res << endl;
}
