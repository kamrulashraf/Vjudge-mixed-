#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main()
{
   long n;
   while(cin >> n)
   {
       if(n<0) break;
       else if(n <= 1) cout << "0%"<< endl;
       else {
        cout << n*25 << '%' << endl;
       }
   }
}
