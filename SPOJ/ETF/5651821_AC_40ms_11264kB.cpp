#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int p[N], hit[N];
void phi(int num)
{
    int i , j , k ;
    for(i = 1 ; i<=num ; i++)
        p[i] = i;
 /*   for( i = 2 ; i <= num ; i+=2)
        {
            hit[i] = 1;
            p[i] = p[i]/2; // for(i = 3 ; i<= num ; i+=2)
        }
*/
    for(i = 2 ; i<= num ; i++)
    if(hit[i] == 0){
        p[i] = p[i]-1;
        for(j = 2*i ; j <= num ; j+=i)
        {
            hit[j]=1;
            p[j] = p[j]/i*(i-1);
        }
    }
}
int main()
{
  phi(1000003);
  int test;
  scanf("%d", &test);
  while(test--){
   int num;
   scanf("%d", & num);
   printf("%d\n", p[num]);
  }


}
