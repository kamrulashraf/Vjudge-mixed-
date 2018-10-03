#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int a , b;
#define pii pair < int ,int>
#define ff first
#define ss second

bool comp(pii a , pii b){
   if(a.ff < b.ff) return true;
   else if(a.ff == b.ff) return a.ss > b.ss;
   return 0;
}
int main()
{
      int n , mmax = 0;
      cin >> n;
      std::vector< pii > v;
      for(int i = 0 ; i< n ; i++){
          scanf("%d%d",&a,&b);

          v.push_back({a,1});
          v.push_back({b,-1});
      }

      sort(v.begin(),v.end(),comp);
      std::vector< int > temp(v.size());
      int sum = 0;
      for(int i = 0 ; i< v.size() ; i++){
          if(i == 0) temp[i] = v[i].ss;
          else if(v[i].ss > 0)
           temp[i] = temp[i-1]+v[i].ss;
          else temp[i] = temp[i-1];

          sum = temp[i];
      }

      int counter = 0;
      for(int i = 0 ; i< v.size() ; i++){
          counter += v[i].ss;
          int tt = sum - temp[i];
//          cout << v[i].ss << ' ' << tt << ' ' << endl;
          if(tt == 0)
          mmax = max(mmax,counter);
      }

      cout << mmax << endl;
      v.clear();

}
