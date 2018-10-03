#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    long long i , sum = 0 , num;
    cin >> num;
    if(num == 0) cout << 1 << endl;
    else if(num < 0)
    {
        num *= -1;
        sum = (num*(num+1))/2;
        sum *= -1;
        cout << sum+1 << endl;
    }
    else{
         sum = (num*(num+1))/2;
         cout << sum << endl;
    }
}
