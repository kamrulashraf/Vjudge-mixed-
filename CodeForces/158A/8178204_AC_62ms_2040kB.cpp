#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    int n, i, save, k, counter, arr[200];
    while (cin >> n >> k)
    {
        for (i = 0; i< n; i++)
        {
            cin >> arr[i];
            if (i + 1 == k)
                save = arr[i];
        }

        for (i = 0, counter = 0; i<n; i++)
        {
            if (arr[i] >= save && arr[i] != 0)
                counter++;
        }
        cout << counter << endl;
    }
    return 0;
}