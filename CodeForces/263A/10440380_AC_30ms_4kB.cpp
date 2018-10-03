#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5; int x ,  y;
    for(int i = 0 ; i< n ; i++){
         for(int j = 0 ; j< n ; j++){
              int temp ;
              cin >> temp;
              if(temp&1){
                 x = i;y = j;
              }
         }
    }
    int res = abs(x-2)+abs(y-2);
    cout << res << endl;
}
