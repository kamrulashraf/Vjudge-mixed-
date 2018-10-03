#include <bits/stdc++.h>
using namespace std;
template < class T > inline T big(T b, T p, T N){
   if(!p) return 1;
   if(!(p&1)){
    T x = big(b,p/2,N);
    return (x * x)%N;
   }
   return (b * big(b,p-1,N))%N;
}
int main()
{
  long long a , b , c;
   cin >> a >> b >> c;
    cout << big(a,b,c) << endl;


}
