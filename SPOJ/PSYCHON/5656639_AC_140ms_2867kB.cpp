#include <bits/stdc++.h>
using namespace std;
bool a[3200];
vector <int> prime;
void seive(int n){
for(int i = 3 ; i*i <= n ; i+= 2)
  if(!a[i])
    for(int j = i*i ; j<= n ; j+= 2*i)
       a[j] = 1;
 prime.push_back(2);
 for(int i = 3 ; i<= n ; i+=2)
   if(!a[i]) prime.push_back(i);
return;
}

void call(int num){
int odd = 0, even = 0;
for(int i = 0 ; prime[i]*prime[i]<= num && i < prime.size() ; i++){
   if(num%prime[i] == 0){
    int counter = 0;
    while(num%prime[i]==0){
      counter++;
      num /= prime[i];
    }
    if(counter&1) odd++;
    else even++;
   }
}
if(num > 1) odd++;
if(even > odd) printf("Psycho Number\n");
else printf("Ordinary Number\n");
}
int main()
{
  seive(3200);
 // for(int i = 0 ; i< 20 ; i++) cout << prime[i] << ' ';
  int test;
  scanf("%d", &test);
  while(test--){
    int num;
    scanf("%d", &num);
    call(num);

  }
}
