#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
int MAX(int a , int b ,int c ,int d){
   int temp = max(a,b);
   int temp1 = max(c,d);
   return max(temp , temp1);
}
int table[505][505][11], a[505][505];
void initRMQ(int n){
  rep(i,0,n) rep(j,0,n) table[i][j][0] = a[i][j];

  for(int len = 1 ; (1<<len) <= n ; len++){
     for(int i = 0 ; i+(1<< len) <= n ; i++){
        for(int j = 0 ; j+(1<<len) <= n ; j++){
          int x = table[i][j][len-1];
          int y = table[i+ (1<<(len-1))][j][len-1];
          int z = table[i][j+(1<<(len-1))][len-1];
          int m = table[i+ (1<<(len-1))][j+(1<<(len-1))][len-1];
          table[i][j][len] = MAX(x,y,z,m);
        }
     }
  }
  return;
}

int query(int i , int j , int s){
   int len = log2(s);
   s--;
   int x = table[i][j][len];
  // cout << x << endl;
   int y = table[i+s - (1<<(len))+1][j][len];
   int z = table[i][j+s -(1<<(len))+1][len];
  // cout << z << endl;
   int m = table[i+s - (1<<(len))+1][j + s - (1<<(len))+1][len];
 // cout << m << endl;
   return MAX(x,y,z,m);
}

int main()
{
   int test, cs = 1;
   cin >> test;
   while(test--){
      memset(table,0,sizeof(table));
      int n , q , x, y , z;
      scanf("%d%d",&n, &q);
      rep(i,0,n) rep(j,0,n)
        scanf("%d",&a[i][j]);
      initRMQ(n);
      printf("Case %d:\n",cs++);
      rep(i,0,q){
        scanf("%d%d%d",&x,&y,&z);
        x-- , y--;
        int ans =  query(x,y,z);
        printf("%d\n",ans);
      }
   }
}
