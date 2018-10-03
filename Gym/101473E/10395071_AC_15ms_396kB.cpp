#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define ull unsigned long long
int mark[100005];
int main()
{
      int  n , r, temp;
      scanf("%d%d",&n,&r);

      for(int i = 0 ; i< r ; i++){
           scanf("%d",&temp);
           mark[temp]++;
      }
      if(n == r){
          printf("*\n");
      }
      else
      for(int i = 1,counter = 0 ; i<= n ; i++){
             if(mark[i] == 0){
                 if(counter) printf(" ");
                 printf("%d",i);
                 counter++;
             }
      }
      return 0;
}
