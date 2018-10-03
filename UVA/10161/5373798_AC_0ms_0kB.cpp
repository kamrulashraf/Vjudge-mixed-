#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define k  (m*m-m+1)
int main()
{
    ll n,row , col;
    while(cin >> n && n){

        ll m = ceil(sqrt(n));

            if(n > k ){
                col = m - (n -k);
      //  cout << n << ' ' << k << ' ' << col << endl;
                row = m;
            }
            else if(n< k ){
                row = m - (k-n);
                col = m;
            }
            else{
                row = m;
                col = m;
            }
            if(!(m&1)) swap(row,col);
            cout << col << ' ' << row << endl;
        }

}
