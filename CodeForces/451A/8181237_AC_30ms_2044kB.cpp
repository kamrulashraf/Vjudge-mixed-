#include <iostream>
using namespace std;
int main()
{
    int a,b, move1 , move2, move;
    while(cin >> a >> b)
    {
        move1 = min( a , b);

        if(move1%2 == 0)
            cout << "Malvika" << endl;
        else cout << "Akshat" << endl ;
    }
return 0;
}