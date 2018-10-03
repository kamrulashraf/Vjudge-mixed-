#include <bits/stdc++.h>
using namespace std;
bool a[1000005] = {1,1};
vector <int> prime;
void seive(void){
int n = 1000003;
for(int i = 3 ; i*i <= n ; i+= 2)
   if(!a[i])
      for(int j = i*i ; j<= n ; j+= 2*i)
        a[j] = 1;
prime.push_back(2);
for(int i = 3 ; i<= n ; i+= 2)
  if(!a[i]) prime.push_back(i);
}
int isprime(long long num){
  if(num == 2) return 1;
  if(num%2 == 0) return 0;
  if(a[num] == 0) return 1;

}

void fun(long long num){
   long long temp = sqrt(num);
 //  cout << temp << ' ' << temp*temp << endl;
   if(isprime(temp) && temp*temp == num)
      cout << "YES" << endl;
   else cout << "NO" << endl;

}
int main(){
  seive();
  int n;
  cin >> n;
  for(int i = 0 ; i< n ; i++){
    long long temp;
    cin >> temp;
    fun(temp);
  }

}
