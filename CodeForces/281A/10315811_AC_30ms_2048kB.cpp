#include <bits/stdc++.h>
using namespace std;
int main()
{
     string s;
     getline(cin,s);
     if(s[0] >= 'a') s[0] ^= 32;
     cout << s  << endl;
}
