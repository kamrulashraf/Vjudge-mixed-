#include <bits/stdc++.h>
#define CON ch[x+m][y+n] != '#' && x+m < a && y+n < b && x+m >= 0 && y+n >= 0
using namespace std;
int main()
{
    int i, j , k;
    char s[50000+10], ch[150][150];
    int a,b,c, m , n, x , y;
    while(cin >> a >> b >> c)
    {
        if(a== 0 && b==0 && c==0)
            break;
        int counter = 0, hit[150][150] = {0} ;
        for(i = 0 ; i<a ; i++)
            for(j = 0 ; j< b ; j++)
        {
            cin >> ch[i][j];
            if(ch[i][j] == 'N'){ m = -1; n = 0; x = i; y = j;}
            if(ch[i][j] == 'S'){ m = 1; n = 0; x = i; y = j;}
            if(ch[i][j] == 'L'){ m = 0; n = 1; x = i; y = j;}
            if(ch[i][j] == 'O'){ m = 0; n = -1; x = i; y = j;}
        }
        cin >> s;
        for(i = 0 ; s[i] ; i++)
        {
           if( s[i] == 'F' && CON)
                {
                    x += m;
                    y += n;
                    if(ch[x][y] == '*' && hit[x][y] == 0){
                        counter++;
                        hit[x][y] = 1;
                    }
                }
            else if(s[i] == 'D'){
                if(n == 0) m *= -
                    1;
                swap(m,n);
            }
            else if(s[i] == 'E'){
                if(m == 0) n*= -1;
                swap(m,n);

            }

          //  cout << x << y << ' ' << m << n << endl;
        }
        cout << counter << endl;

    }
}
