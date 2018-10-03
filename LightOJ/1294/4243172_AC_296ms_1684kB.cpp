#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    long long int i , n , m;
    int test;
    cin >> test;
    for(i = 1 ; i<= test ; i++)
    {
        cin >> n >> m ;
        cout << "Case " << i << ": " << n/2 * m << endl;

    }
 return 0;
}
