#include <bits/stdc++.h>
using namespace std;
#define NN 100000005
#define LAST  100000000
map <int,int> tree;
void update(int indx ,int  val){
      while(indx <= LAST){
        tree[indx] += val;
        indx += indx & -indx;
      }
}
long long sum(int indx){
  long long sum = 0;
  while(indx){
    sum += tree[indx];
    indx -= indx & -indx;
  }
  return sum;
}
int main()
{
    int test, cs = 1;
    scanf("%d",&test);
    while(test--){
      tree.clear();
      int x , y , q, n;
      printf("Case %d:\n",cs++);
      scanf("%d %d", &n, &q);
      for(int i = 0 ; i< n ; i++){
        scanf("%d%d",&x , &y);
        x++ , y++;
        update(x,1);
        update(y+1,-1);
      }

      for(int i = 0 ; i< q ; i++){
          scanf("%d",&x);
          x++;
          long long temp = sum(x);
          printf("%lld\n",temp);
      }
    }
 return 0;
}
