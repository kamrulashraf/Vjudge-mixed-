#include <cstdio>
#include <iostream>
#include <set>
#include <cmath>
using namespace std;
int main()
{
    int i , j , k , num, arr[30005], test, m;
    set<int> s;
    while(cin >> test)
    {
        int flag = -1;
        for(i = 0 ; i< test ; i++)
         cin >> arr[i];
        for(i = 0; i<test-1;i++)
        {
            m = abs(arr[i+1] - arr[i]);
            if(m == 0 || m >= test)
            {
                flag = 1;
                break;
            }
            else s.insert(m);
        }
        if(flag = -1){
            if(s.size() == test - 1)
                cout << "Jolly" << endl;
            else cout << "Not jolly" << endl;
        }
        else cout << "Not jolly" << endl;
        s.clear();
    }

return 0;
}
