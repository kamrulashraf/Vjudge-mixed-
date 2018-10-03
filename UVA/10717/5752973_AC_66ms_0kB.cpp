#include <bits/stdc++.h>
using namespace std;
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}

int main()
{
 // freopen("a.txt", "w", stdout);
  long long n , t, a[55], ans;
  vector < long long > v;
  while(cin >> n >> t){
          long long mmin = 1e7;
          if(n == 0 && t == 0 ) break;
          for(int i = 0 ; i < n ; i++){
            cin >> a[i];
          }
          ans = 1;
          for(int i = 0 ; i< n ; i++)
              for(int j = i+1 ; j< n ; j++)
                for(int k = j+1 ; k< n ; k++)
                   for(int l = k+1 ; l<n ; l++){
                       long long t1 = lcm(a[i],a[j]);
                       t1 = lcm(t1,a[k]);
                       t1 = lcm(t1,a[l]);
                       v.push_back(t1);
                   }
           for(int i = 0 ; i<t ; i++){
              long long var, l , h;
              cin >> var;
              long long save1 = -1, save2 = 1e7;
              for(int j = 0 ; j< v.size() ; j++){
                 long long temp = var/v[j]*v[j];
                 if(var%v[j] == 0){
                   l = temp ; h = temp;
                 }
                 else{
                   l = temp ; h = temp+v[j];
                 }
                save1 = max(save1,l);
                save2 = min(save2,h);
              }
               cout << save1 << ' ' << save2 << endl;

           }
         v.clear();
  }

}
