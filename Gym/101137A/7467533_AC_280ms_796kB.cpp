#include <bits/stdc++.h>
using namespace std;
#define NN 100005
long long a[NN];
int main()
{
    int n;
    cin >> n;
    for(int i = 0 ; i<n ; i++){
      cin >> a[i];
    }
    for(int i =n ; i< n+3 ; i++){
       a[i] = a[i%n];
    }
    int x , y , z;
    for(int i = 0 ; i< n ; i++){
        if(a[i] < a[i+1] && a[i+1] > a[i+2]){
            x = i%n;
            y=(i+1)%n;
            z = (i+2)%n;
        }
    }
    cout << x+1 << ' ' << y+1 << ' ' << z+1 << endl;

}