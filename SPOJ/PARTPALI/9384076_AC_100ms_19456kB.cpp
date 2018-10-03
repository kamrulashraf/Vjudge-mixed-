#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
ll dp[21][21][1005];
       int m , s;
int power[30];
void p(int n){
   int base = 1;
   power[0] = 1%n;
   for(int i = 1 ; i<= 20 ; i++){
         base = (base*10)%n;
         power[i] = base;
   }
}

long long call(int b ,  int e, int val){
//      cout << b << ' ' << e << ' ' <<val << endl;
     if(b <= 0){
       if(val%m == 0){
//          cout <<b << ' ' << e << ' ' <<  val << endl;
          return 1;
       }
       return 0;
     }
     if(dp[b][e][val] != -1) return dp[b][e][val];
     int x = b-1 , y = e+1;
     long long res = 0;
     for(int i = 0 ; i<= 9 ; i++){
         if(b == 1 && i==0) continue;
        int temp = (val*10+i)%m;
        int temp1 = (i%m*power[y-x]%m)%m;
         temp = (temp+temp1)%m;
        res += call(x,y,temp);
     }
     return dp[b][e][val] =  res;
}
int main()
{
//    freopen("in.txt" , "r" , stdin);
     int test , cs = 1;
     scanf("%d",&test);
     while(test--){
      memset(dp,-1,sizeof dp);
      scanf("%d%d",&m,&s);
      p(m);
      long long res = 0;
      if(s&1){
            for(int i = 0 ; i<= 9 ; i++){
              if(s==1 && i == 0) continue;
              res += call(s/2,s/2,i);
            }
//              call(s/2,s/2,1);
      }
        else{
         for(int i = 0 ; i<= 9 ; i++){
                if(i == 0 && s== 2) continue;
                res += call(s/2-1,s/2, i*10+i);
         }
        }

        cout << res << endl;
     }
}
