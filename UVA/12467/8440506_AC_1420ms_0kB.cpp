#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
ll mod = 1e9+7;
ll base = 1572872831LL;
ll power[N];
 char a[N], b[N];
ll hashVal1[N];
ll hashVal2[N];

void hashFuntion1(){
     int sz = strlen(a);
     for(int i = 0 ; i < sz; i++){
          hashVal1[i+1] =  (hashVal1[i]*base+a[i]-64)%mod;
     }
}


void hashFuntion2(){
     int sz = strlen(b);
     for(int i = 0 ; i < sz; i++){
          hashVal2[i+1] =  (hashVal2[i]*base+b[i]-64)%mod;
     }
}
void preCalculate(){
   power[0] = 1;
   for(int i = 0 ; i<= 1000005;i++){
      power[i+1] = (power[i]*base)%mod;
   }
}


int hashValBetween(int i , int j){
    return (hashVal2[j] - (hashVal2[i-1]*power[j-i+1])%mod + mod)%mod; // 1 based indx
}


bool fun(int len, int target){
   int sz =  strlen(b);
   for(int i  = 0 ; i+len<= sz ; i++){
        int temp = hashValBetween(i+1,i+len);
        if(temp == target){
           // cout << i << ' ' << i+len <<  endl;
           return 1;
        }
   }
   return 0;
}
int main()
{
   preCalculate();
   int test , cs= 1;
   scanf("%d",&test);
   getchar();
   while(test--){
       gets(a);
       int sz = strlen(a);
       strcpy(b,a);
       reverse(b,b+sz);
       hashFuntion1();
       hashFuntion2();
       int be = 1;
        int e = strlen(a);
       // cout << b << endl;
       while(be<=e){
          int m = (be+e)/2;
          bool flag = fun(m, hashVal1[m]);
          if(flag == 1){
             be =m+1;
          }
          else e = m-1;
       }
       // cout << fun(2, hashVal1[2]) <<  endl;
       for(int i = e-1 ; i>= 0 ; i--)
          printf("%c",a[i]);
       printf("\n");

   }
   return 0;
}
