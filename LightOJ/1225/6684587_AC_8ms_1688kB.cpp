#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test,cs  = 1;
    scanf("%d",&test);
    getchar();
    while(test--){
        char s[1000];
        bool flag = 0;
        gets(s);
        int len = strlen(s);
        for(int i = 0 ; i< len/2 ; i++){
           int j = len-i-1;
           if(s[i] != s[j]) flag = 1;
        }
        printf("Case %d: ", cs++);
        if(flag) puts("No");
        else puts("Yes");
    }  
}