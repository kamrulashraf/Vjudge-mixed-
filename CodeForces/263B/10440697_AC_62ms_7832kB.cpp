#include <bits/stdc++.h>
using namespace std;
int a[2000005];
int main()
{

     int n , k;
     cin >> n >> k;
     for(int i = 0 ; i< n ; i++)
         scanf("%d",&a[i]);
     sort(a,a+n);
     int temp = n-k;
     if(temp < 0) cout << -1 << endl;
     else cout << a[temp] << ' ' << a[temp] << endl;

}
