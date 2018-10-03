#include <bits/stdc++.h>
using namespace  std;
#define NN 100005
#define ll  long long
ll a[NN] , b[NN];
ll mmin = 1e14;
int main()
{
    ll r , c;
    cin >> r >> c;
    for(int i = 0 ; i< r ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i< r ; i++){
        cin >> b[i];
    }
    for(int i = 0 ; i< r ; i++){
        mmin = min(mmin , c - (a[i]+b[i]));
    }
    double res = mmin;
    cout << res/2.0 << endl;
}