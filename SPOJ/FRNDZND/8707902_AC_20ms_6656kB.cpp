#include <bits/stdc++.h>
using namespace std;
int arr[1000005];
int main()
{

      int n , q;
      scanf("%d%d",&n,&q);
      for(int i = 0 ; i< n ; i++){
         scanf("%d",&arr[i]);
      }
      for(int i = 0 ; i< q ; i++){
          int a , b;
          scanf("%d%d",&a,&b);
          if(a==b){
             printf("%d\n",arr[a-1]);
          }
          else printf("0\n");
      }
}
