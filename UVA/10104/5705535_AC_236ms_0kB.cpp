#include <bits/stdc++.h>
using namespace std;
template < class T> T extentedGcd(T a, T b, T &X , T &Y){
     T x1 = 1 , y1 = 0;
     T x2 = 0 , y2 = 1;
     while(b){
        T x = x1 - (a/b)*x2;
        T y = y1 - (a/b)*y2;
        x1 = x2 ; y1 = y2;
        x2 = x  ; y2 = y;
        T temp = a;
        a = b;
        b = temp%b;

     }
     X = x1;  Y = y1;
     return a;
}
int main()
{
  long long a ,b;
  while(cin >> a >> b){
    long long x, y;
    long long temp = extentedGcd(a,b,x,y);
    cout << x << ' ' << y << ' ' << temp << endl;

  }


}

