#include <bits/stdc++.h>
using namespace std;
int main()
{
      long long n , m , s;
      cin >> n >> m >> s;
      int i;
      int counter = 0;
      for( i = 1 ; i <= n ; i+= s){
          counter++;
      }
      
      i -= s;
      long long res = 0;
      res += counter;
      res += counter*(n-i);

      counter = 0;
      long long res1 = 0;
      for( i = 1 ; i <= m ; i+= s){
          counter++;
      }

      i -= s;
      res1 += counter;
      res1 += counter*(m-i);
      cout << res*res1 << endl;
}
