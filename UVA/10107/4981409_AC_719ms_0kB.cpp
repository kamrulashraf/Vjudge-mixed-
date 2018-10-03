#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a , arr[10005], i = 0;
    while(cin >> a)
    {
        arr[i] = a;
        sort(arr, arr+i+1);
        if(i&1)
          cout << (arr[i/2]+arr[i/2+1] )/2 << endl;
        else
           cout << arr[i/2] << endl;
        i++;

    }
 return 0;
}
