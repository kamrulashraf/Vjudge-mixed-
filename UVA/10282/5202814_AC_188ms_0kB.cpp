#include <bits/stdc++.h>
using namespace std;
char a[100005], b[100005], c[100005];
map <string ,string> hit;
int main()
{
    while(gets(a))
    {
        if(a[0] == '\0') break;
        sscanf(a,"%s %s",b , c);
        hit[c] = b;
    }
    while(gets(a))
    {
       if(a[0] == '\0') break;

       if(hit[a] == "\0") printf("eh\n");
       else printf("%s\n", hit[a].c_str());
    }
 return 0;
}
