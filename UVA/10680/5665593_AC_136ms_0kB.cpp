#include <bits/stdc++.h>
using namespace std;
bool a[1000005];
vector <int> prime;
void seive(){
int n = 1000000;
for(int i = 3 ; i*i<= n ; i+= 2)
 if(a[i] == 0)
    for(int j = i*i ; j<= n ; j+= 2*i)
        a[j] = 1;
prime.push_back(2);
for(int i = 3 ; i<= n ; i+= 2)
    if(!a[i])
      prime.push_back(i);

}

int fun(int num, int n){
int temp = 1,sum = 0;
while(temp*n <= num){
  temp *= n;
  sum++;
}
return sum;
}
int main()
{
  seive();
 // freopen("a.txt", "w" ,stdout);
 // for(int i = 0 ; i<= 30 ; i++) cout << prime[i] << ' ';
  int num;
  while(scanf("%d", &num)==1){
    if(num == 0) break;
    int n5 = fun(num, 5);
    int n2 = fun(num,2);
    n2 = n2 - min(n5,n2);
    long long ans = 1;
    for(int i = 0 ; prime[i] <= num && i < prime.size() ; i++){
        long long temp = 1;
        if(prime[i] != 2 && prime[i] != 5){
           while(temp*prime[i] <= num){
             temp *= prime[i];
           }
        }
        ans = (ans*temp)%10;
    }
    for(int i = 0 ; i< n2 ; i++)
       ans = (ans*2)%10;

    printf("%d\n", ans);
  }
}
