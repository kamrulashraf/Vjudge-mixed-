#include<cstdio>
#include <iostream>
using namespace std;
int main()
{
    int i , j , k , num;
    int t;
    cin >> t;
    while(t--)
    {
        int flag = -1;
        cin >> num;
        i = 1;
        if(num%10 == 9)
        {
            cout << 1 << endl;
            continue;
        }
        while(1)
        {
            if((num-9)%10 == 9)
                break;
          //  cout << num << endl;
            if(num<=0)
            {
                flag = 1;
                cout << "Impossible" << endl;
                break;
            }
            num -= 9;
            i++;
        }
        if(flag != 1)
        cout << i+1 << endl;
    }
}
