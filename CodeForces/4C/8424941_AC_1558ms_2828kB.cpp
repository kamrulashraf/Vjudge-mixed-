#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main()
{
    long num, i ;
    string s;
    map <string , int> m;
    cin >> num ;
    for(i = 0 ; i< num ; i++)
    {
        cin >> s;
        if(m[s] == 0)
            cout << "OK" << endl;
        else if(m[s] != 0)
          cout << s << m[s] << endl;

        m[s] += 1;


    }
}