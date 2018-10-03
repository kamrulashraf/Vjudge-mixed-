#include <bits/stdc++.h>
#define N 2000005
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
      gets(str);
      int sz = strlen(str);
      strcpy(sub,str);
      reverse(sub,sub+sz);
      str[sz] = '#';
      int i;
      for(i=sz+1; i<= sz+sz+1 ; i++)
          str[i] = sub[i-sz-1];
      str[i] = '\0';
      kmpPreprocess(str);
      int mmax = 0;
      for(int i = sz+2 ; i <= 2*sz+1; i++){
          mmax = max(b[i],mmax);
      }
      for(int i = mmax-1 ; i>= 0 ; i--)
         printf("%c",str[i]);
      printf("\n");
    }
}
