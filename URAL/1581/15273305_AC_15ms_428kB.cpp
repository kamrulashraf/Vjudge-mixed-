#include <iostream>
using namespace  std;
#define N 10005

int a[N];
int main()
{
    int n;
    cin >> n;
    int counter = 0;
    for(int i = 0 ; i< n ; i++){
         cin >> a[i];
    }

    int temp = a[0];
    int f = 0;
    for(int i = 0 ; i < n ; i++){
         if(a[i] == temp){
             counter++;
         }
         else{
            if(f) cout << ' ';
            f++;
            cout << counter << ' ' << temp ;
            counter = 1;
            temp = a[i];
         }
    }
    if(f) cout << ' ' <<  counter << ' ' << temp << endl;
    else cout << counter << ' ' << temp << endl;
    return 0;
}
