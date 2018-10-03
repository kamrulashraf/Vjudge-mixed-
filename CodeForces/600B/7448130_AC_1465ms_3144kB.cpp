#include <bits/stdc++.h>
using namespace std;
#define NN 200005
#define ll long long
ll a[NN] , b[NN];
int main()
{
   int n, m;
   cin >> n >> m;
   for(int i = 0 ; i< n ; i++){
      cin >> a[i];
   }
   sort(a,a+n);
   for(int i = 0 ; i< m ; i++){
      long long key;
      cin >> key;
      // cout << key << endl;
      int pos = upper_bound(a,a+n,key)-a;
      cout << pos << ' ';
   }
   cout << endl;
}