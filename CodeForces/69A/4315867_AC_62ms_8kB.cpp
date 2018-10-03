#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
 int test,m, sum , sum1 , sum2;
 int i[200] , j [200] , k[200];
 while (cin >> test)
 {
    for(m =0 ; m< test ; m++)
        cin >> i[m] >> j[m] >> k[m];


    for(sum = 0, sum1 =0 , sum2 = 0,m =0 ; m< test ; m++)
    {
       sum = sum + i[m];
       sum1 = sum1 + j[m];
       sum2 = sum2 + k[m];
    }

    if(sum == 0 && sum1 == 0 && sum2 == 0)
        cout << "YES" << endl;
    else cout << "NO" << endl;
}

return 0;
}
