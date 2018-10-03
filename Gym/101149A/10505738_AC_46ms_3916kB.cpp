#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int a[N];

int main()
{
      int n , mmax = 0;
      cin >> n;
      for(int i = 0 ; i< n ; i++){
          scanf("%d",&a[i]);
          mmax = max(mmax,a[i]);
      }
      cout << mmax << endl;
}