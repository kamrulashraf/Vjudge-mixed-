#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;
int gcd(int a , int b)
{
    if(a==0) return b;
    if(b==0) return a;
    while(b%a)
    {
        int temp = a;
        a = b%a;
        b = temp;
    }
    return a;
}
int main()
{
    int i, j , k, a[150], b = 0;
    int test;
    string s;
    cin >> test;
    getchar();
    while(test--)
    {
        int m = 0;
        k = 0;
        getline(cin , s);
        stringstream ss(s);
        while(ss>> a[k]) k++;

        for(i = 0 ; i< k ; i++)
        for(j = 0 ; j< k ; j++)
        {
            if(i != j)
            m = max(m, gcd(a[i], a[j]));
        }
      cout << m << endl;
    }
}
