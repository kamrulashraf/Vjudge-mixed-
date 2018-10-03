#include <bits/stdc++.h>
#define N 1000005
using namespace std;
int b[N];
    void kmpPreprocess(char *sub)
    {
        int i = 0, j = -1;
        b[i] = j;
        int m = strlen(sub);
        while(i < m){
            while(j >= 0 && sub[i] != sub[j])
                j = b[j];
            i++, j++;
            b[i] = j;
        }
    }

    int kmp(char *s , char *sub){
      int i=0,j=0,counter=0;
      int n = strlen(s);
      int m = strlen(sub);
      while(i<n){
        while( j>= 0 && s[i] != sub[j])
           j = b[j];
         i++ , j++;
         if(j==m) counter++ , j = b[j];
      }
      return counter;
    }

int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    getchar();
    while(test--){
      char str[N],sub[N];
      gets(sub);
      gets(str);
      kmpPreprocess(sub);
      int res = kmp(str,sub);
      printf("%d\n",res);
    }
   return 0;
}
