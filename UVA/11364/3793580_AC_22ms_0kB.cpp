#include <stdio.h>
#include <iostream>
#include <stdlib.h>
int cmpfunc(const void *a, const void *b)
   {
     return *(int *) a - *(int *) b;
   }
using namespace std;
int main()
{
 int test,n,i,num[25],ans;
 cin >> test;
 while(test--)
 {
     scanf("%d", &n);
     for(i=0;i<n;i++)
         scanf("%d", &num[i]);

     qsort(num,n,sizeof(int), cmpfunc);

     ans = 2 *(num[n-1] - num[0]);
     cout << ans << "\n" ;
 }
}
