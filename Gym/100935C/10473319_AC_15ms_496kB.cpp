#include <bits/stdc++.h>
using namespace std;
char s[100000];
int tree[100005];
int nn = 10005;
void update(int indx, int val){
    while(indx <= nn){
         tree[indx] += val;
         indx += indx&-indx;
    }
}

int sum(int indx){
    int ret = 0;
    while(indx){
        ret += tree[indx];
        indx -= indx & -indx;
    }
    return ret;
}
int main()
{

    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
          int r , c;
          char ch[25][25];
          int dp[25] = {0};
          scanf("%d%d",&r,&c);

          for(int i  = 0 ; i< r ; i++){
              for(int j = 0 ; j< c ; j++){
//                 scanf("%c",&ch[i][j]);
                 cin >> ch[i][j] ;
                 if(ch[i][j] == '*')
                     dp[j]++;
              }
          }


          int mmax = 0 ; int mmin = 50;

          for(int i = 0 ; i< c ; i++){
                if(dp[i] == 0) continue;
             mmax = max(mmax,dp[i]);
             mmin = min(mmin,dp[i]);
          }

         if(mmin == 2)
            printf("Case %d: Zero\n",cs++);
         else printf("Case %d: Eight\n",cs++);
    }
}
