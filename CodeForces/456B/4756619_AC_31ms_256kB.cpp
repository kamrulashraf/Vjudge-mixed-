#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i , j , k,save;
    string s;
    cin >> s;
    int len = s.size();
    if(len > 1)
    save = 10*(s[len-2]-48)+s[len-1]-48;
    else save = s[0]-48;
    int m = save%4;
    if(m == 0) cout << 4 << endl;
    else cout << 0 << endl;
}
