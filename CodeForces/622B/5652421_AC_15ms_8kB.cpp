#include <bits/stdc++.h>
using namespace std;
int main()
{
 int h , m;
 scanf("%d:%d", &h , &m);
 int time;
 cin >> time;
 h+= time/60;
 m += time%60;
 if(m >= 60){

   h += m/60;
   m = m%60;
 }
 h = h%24;
 m = m%60;
 if(h < 10) cout << '0';
 cout << h << ':';
 if(m<10) cout << '0';
 cout << m << endl;


}
