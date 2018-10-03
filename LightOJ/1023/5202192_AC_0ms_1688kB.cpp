#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i , a, b , test , s[26], caseno=1;
    scanf("%d", &test);
    while(test--)
    {
        for(i = 0 ; i<26 ; i++)
          s[i] = 65+i;
        scanf("%d %d", &a , &b);
        printf("Case %d:\n",caseno++);
        int counter = 0;
        do{
            counter++;
            if(counter == b+1) break;
            for(int j = 0 ; j< a ; j++)
              printf("%c",s[j]);
            printf("\n");
        } while(next_permutation(s,s+a));

    }
return 0;
}
