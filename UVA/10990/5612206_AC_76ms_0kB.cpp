#include <bits/stdc++.h>
using namespace std;
#define N 2000003
int phi[2000003],dp[N];
long long sum[N];
bool mark[N];
void phiFuntion(void){
 for(int i = 1 ; i< N ; i++)
    phi[i] = i;
 for(int i = 2 ; i<= N ; i++){
    if(mark[i] == 0){
        phi[i]--;
        for(int j = 2*i ; j< N ; j += i){
            phi[j] = phi[j]/i*(i-1);
            mark[j] = 1;
        }
    }
 }
}

void memDp(){
  for(int i = 2 ; i< N ; i++){
    dp[i] = dp[phi[i]]+1;
    sum[i] = sum[i-1]+dp[i];
  }

}
int main()
{
  int a , b, num,test;
  phiFuntion();
  memDp();
  cin >> test;
//  for(int i = 0 ; i< 15 ; i++) cout << sum[i] << ' ';
  while(test--){
    scanf("%d %d", &a , &b);
  //  cout << a << ' ' << sum[a] << endl;
    long long temp = sum[b]-sum[a-1];
    cout << temp << endl;
  }
}
