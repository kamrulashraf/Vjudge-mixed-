
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    long int test, a,b;
    cin >> test ;
    while(test--){
        cin >> a >> b;
        if(a<=b)
        {
            if(b%a==0)
                cout << a << ' '<< b << endl;
            else cout << -1 << endl;
        }
        else cout << -1 << endl;
    }
}
