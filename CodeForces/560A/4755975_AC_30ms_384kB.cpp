#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test,a[100000],i,falg = -1;
    cin >> test;
    for(i = 0 ; i< test ; i++)
    {
        cin >> a[i];
        if(a[i] == 1)
            falg = 1;
    }
    if(falg == 1) cout << "-1" << endl;
    else cout << 1 << endl;
}
