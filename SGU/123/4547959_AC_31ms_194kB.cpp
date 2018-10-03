#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int i = 0 , j = 1 , nth,sum = 1;
    int counter = 1;
    cin >> nth;
    if(nth==1) cout << '1' << endl;
    else
    while(1)
    {
        i = i + j;
        sum += i;
        counter++;
        if(counter == nth){
               cout << sum << endl;
               break;
        }

        j = i + j;
        counter++;
        sum += j;
        if(counter == nth){
               cout << sum << endl;
               break;
        }

    }
}
