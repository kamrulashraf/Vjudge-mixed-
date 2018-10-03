#include <bits/stdc++.h>
using namespace std;
bool a[10000002];
int prime[670000], dp[670000][10] ,  cnt;
void seive(){
   int n = sqrt(10000000);
   for(int i = 2 ; i<= n ; i++){
    if(a[i] == 0)
       for(int j = i*i ; j<= 10000000 ; j+= i){
          a[j] = 1;
       }
   }

   for(int i = 2 ; i<= 10000000 ; i++){
      if(a[i] == 0) prime[cnt++] = i;
   }
}
int main()
{
     seive();

     int test , cs = 1;
     scanf("%d",&test);
     char s[100],ss[100];
     getchar();

     for(int i = 0 ; i < cnt ; i++){
         int temp = prime[i];
         while(temp){
            int tt = temp%10;
            temp /= 10;
            dp[i][tt]++;
         }
     }

     while(test--){
         int mark[11] = {0};
         scanf("%s",s);
//         int sz = 0,flag = 0;
//         for(int i = 0; s[i] ; i++){
//            if(flag == 0 && s[i] == '0') continue;
//            ss[sz++] = s[i];
//            flag = 1;
//         }
         strcpy(ss,s);
         int sz = strlen(ss);

         for(int i = 0 ; i < sz ; i++){
            mark[ss[i]-'0']++;
         }
         int res = 0;
         for(int i = 0 ; i< cnt ; i++){
            int flag = 1;
            for(int j = 0 ; j< 10 ; j++){
                if(mark[j] < dp[i][j]) flag = 0;
            }
//            cout << flag << ' ' << i << endl;
            res += flag;
         }

         printf("%d\n",res);
     }
}
