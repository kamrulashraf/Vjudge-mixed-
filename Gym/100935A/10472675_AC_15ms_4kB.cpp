#include <bits/stdc++.h>
using namespace std;
int main()
{

    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
          int a ,b , c ,  x, y , z;
          scanf("%d%d%d%d%d%d",&a,&b,&c,&x,&y,&z);
          int aa , bb;
          aa = 3600*a+60*b+c;
          bb = 3600*x+60*y+z;
//          cout << aa << ' ' << bb <<endl;
          if(aa==bb) printf("Case %d: Yes\n",cs++);
          else printf("Case %d: No\n",cs++);
    }
}
