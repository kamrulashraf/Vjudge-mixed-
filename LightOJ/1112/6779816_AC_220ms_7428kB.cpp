#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
#define ll long long
int tree[500005];
ll sum(ll idx)
{
    ll sum = 0;
    while(idx!=0)
    {
        sum+= tree[idx];
        idx -= idx &(-idx);
    }
 return sum;
}
void update(ll num , ll idx , ll a)
{
    while(idx <= num)
    {
        tree[idx] += a;
        idx += idx &(-idx);
    }
}
int main()
{
  long long int i , j , k, num , que , x , y , a[500005],q, caseno = 0;
  int test;
  scanf("%lld", &test);
  while(test--)
  {
      caseno++;
      printf("Case %lld:\n", caseno);
      memset(tree , 0 , sizeof(tree));
      scanf("%lld %lld", &num , &que);
      for(i = 1 ; i<= num ; i++)
        scanf("%lld", &a[i]);
      for(i = 1 ; i<= num ; i++)
        update(num , i , a[i]);
   /*   for(i = 1 ; i<= num ; i++)
        cout << tree[i] << ' ';
    */
     for(i = 0 ; i<que ; i++)
     {
         scanf("%lld", &q);
         if(q==1)
         {
             scanf("%lld", &x);
             ll save = sum(x+1) - sum(x);
             printf("%lld\n", save);
             save *= -1;
             update(num,x+1 , save);
         }
         if(q==2)
         {
             scanf("%lld %lld", &x , &y);
             update(num ,x+1 , y);
         }
         if(q==3)
         {
             scanf("%lld %lld", &x , &y);
             ll save = sum(y+1) - sum(x);
             printf("%lld\n", save);
         }
     }
  }
}
