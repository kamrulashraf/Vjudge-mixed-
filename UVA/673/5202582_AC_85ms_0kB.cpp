#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i , test;
    char ch;
    stack <char> st;
    char s[1000];
    cin >> test;
    int hit[250] = {0};
    hit['('] = 1;
    hit['['] = 1;
    hit[')'] = '(';
    hit[']'] = '[';
    getchar();
    while(test--)
    {
        gets(s);
        for(i = 0 ; i< strlen(s) ; i++)
        {
          //  cout << st.size() << endl;
            if(hit[s[i]] == 1) st.push(s[i]);
            else if(st.size() > 0){
                if(st.top() == hit[s[i]]) st.pop();
            }
            else st.push(s[i]);
        }
       // cout << st.size() << endl;
        if(st.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;
        while(!st.empty()) st.pop();

    }
return 0;
}
