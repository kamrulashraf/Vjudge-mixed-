#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int i , j , n , m, counter = 0,sum = 0,maxi;
    cin >> n >> m;
    int arr[100000+5];
    for(i = 0 ;i<n ; i++)
        cin >> arr[i];
    for(i = 0,j = 0 ;i<n ; i++)
    {
        sum+= arr[i];
        counter++;
        if(sum > m)
        {
            sum -= arr[j];
            counter--;
            j++;
        }
        maxi = max(maxi, counter);
    }
    cout << counter << endl;
}