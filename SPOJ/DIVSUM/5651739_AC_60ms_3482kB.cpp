#include <bits/stdc++.h>
using namespace std;
bool a[1000];
vector <int> prime;
void seive(void){
int n = 1000;
for(int i = 3 ; i*i <= n ; i+= 2)
   if(!a[i])
      for(int j = i*i ; j<= n ; j+= 2*i)
        a[j] = 1;
prime.push_back(2);
for(int i = 3 ; i<= n ; i+= 2)
  if(!a[i]) prime.push_back(i);
}
long long sod(int num){
long long res = 1;
for(int i = 0 ; prime[i]*prime[i] <= num && i < prime.size() ; i++){
  if(num%prime[i] == 0){
    int pow = 1;
    int sum = 1;
    while(num%prime[i] == 0){
      pow = pow*prime[i];
      sum += pow;
      num /= prime[i];
    }
    res *= sum;
  }
}
if(num >1) res *= (num+1);
return res;


}
int main()
{
seive();
int num , test;
cin >> test;
while(test--){
 scanf("%d", &num);
 int temp = sod(num);
 printf("%d\n", temp-num);
}

}
