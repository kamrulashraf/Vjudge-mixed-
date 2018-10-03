#include <bits/stdc++.h>
using namespace std;
int a[10000009];
void seive(void){
int n = 10000007;
for(int i = 4 ; i<= n ; i+=2)
   a[i] = 2;
for(int i = 3 ; i*i<= n ; i+=2)
   if(a[i] == 0)
     for(int j = i*i ; j<= n ; j+= 2*i)
       if(a[j] == 0) a[j] = i;

}

void print(int num){
  printf("1");
  if(num==1){
    printf("\n");
   return;
   }
  while(a[num] && num%a[num]==0){
     printf(" x %d", a[num]);
     num /= a[num];
  }
    printf(" x %d", num);
  printf("\n");
}
int main()
{
 // cout << sqrt(10000000) << endl;
  seive();
//    for(int i = 1 ; i<= 20 ; i++) cout << i << '=' << a[i] << endl;
  int num;
  while(scanf("%d",&num)!=EOF){
    print(num);
  }
 return 0;
}
