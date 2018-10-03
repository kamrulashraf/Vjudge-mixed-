#include <bits/stdc++.h>
using namespace std;
int main()
{
     int p;
     cin >> p;
//     if(p == 2){
//         cout << 0 << endl;
//         return 0;
//     }
     int counter = 0;
     for(int x = 1 ; x< p ; x++){
           int temp = 1;
           bool flag = 0;
           for(int i = 1 ; i<p-1 ; i++){
                 temp = (temp*x)%p;
//                 cout << x << ' ' << i << ' ' <<  temp << endl;
                 if( (temp-1) % p == 0){
                        flag = 1;
                        break;
                 }
           }
//           cout << x << ' ' << flag << endl;
           if(flag == 0 && (temp*x-1)%p == 0){
//              cout << x << endl;
              counter++;
           }
     }

     cout << counter << endl;
}
