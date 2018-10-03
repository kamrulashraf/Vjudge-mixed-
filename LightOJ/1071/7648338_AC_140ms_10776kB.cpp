#include <bits/stdc++.h>
using namespace std;
#define NN 105
#define inf 1e6
int dp[NN][NN][2*NN] , arr[NN][NN];
int row , col;
int call(int r , int c , int r1 , int c1, int level){
      if(r >= row || c >= col || r1 >= row || c1 >= col) return 0;
      if(r==r1 && c == c1 && !(r1 == 0 && c1 == 0)) return 0;
      if(dp[r][c][r1] != -1) return dp[r][c][r1];
      int x, y, zz;
      zz = arr[r][c]+arr[r1][c1];
      level++;
      x = max(zz+call(r+1, c, r1 +1 , c1, level),zz+call(r+1, c , r1 , c1+1,level));
      y = max(zz+call(r, c+1, r1 +1 , c1,level),zz+call(r, c+1 , r1 , c1+1,level));
      return dp[r][c][r1] = max(x,y);
}
int main()
{
   int test , cs = 1;
   scanf("%d", &test);
   while(test--){
       int n;
       scanf("%d%d", &row, &col);
       for(int i = 0 ; i< row ; i++){
          for(int j = 0 ; j < col ; j++){
             scanf("%d",&arr[i][j]);
          }
       }
       memset(dp,-1,sizeof(dp));
       int res = call(0,0,0,0,0);
    //  cout << res << endl;
       res -= arr[0][0];
       res += arr[row-1][col-1];
       printf("Case %d: %d\n",cs++ ,res);
 
   }
}