#include <bits/stdc++.h>
using namespace std;
int a[100005], table[100005][22];
    void RMQ_init(int n){
        for(int i=0;i<n;i++) table[i][0] = a[i];
        for(int len = 1;(1<<len)<=n;len++)
            for(int i=0;(i+(1<<len))<=n;i++)
                table[i][len] = min(table[i][len-1],table[i+(1<<(len-1))][len-1]);
        return;
    }
 
    int getmin(int i,int j){
        int k = log2(j-i+1);
        return min(table[i][k],table[j-(1<<k)+1][k]);
    }
 
int main()
{
   int test , n , m, p , q, cs = 1;
   scanf("%d",&test);
   while(test--){
      memset(table,0,sizeof(table));
      printf("Case %d:\n",cs++);
      scanf("%d %d", &n , &m);
      for(int i = 0 ; i< n ; i++) scanf("%d",&a[i]);
 
      RMQ_init(n);
      for(int i = 0 ; i< m ; i++){
        scanf("%d%d",&p,&q);
        p-- , q--;
        printf("%d\n", getmin(p,q));
      }
   }
   return 0;
}