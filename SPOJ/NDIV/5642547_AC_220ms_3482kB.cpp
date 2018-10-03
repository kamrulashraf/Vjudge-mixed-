#include <bits/stdc++.h>
using namespace std;
bool a[32003];
vector <int> prime;
void seive(void){
int n = 32000;
for(int i = 3 ; i*i <= n ; i+= 2)
  if(!a[i])
    for(int j = i*i ; j<= n ; j+= 2*i)
       a[j] = 1;
 prime.push_back(2);
 for(int i = 3 ; i<= n ; i+=2)
   if(!a[i]) prime.push_back(i);
 return;
}

int nod(int n){
  int res = 1;
  for(int i = 0 ; prime[i]*prime[i]<= n&& i < prime.size() ; i++){
    if(n%prime[i] == 0){
      int counter = 1;
      while(!(n%prime[i])){
        counter++;
        n /= prime[i];
      }
      res *= counter;
    }

  }
  if(n > 1) res *= 2;
  return res;
}
int main()
{
  int a  , b, c, counter = 0;
  seive();
  cin >> a >> b >> c;
  for(int i = a ; i<= b ; i++){
     if(nod(i) == c)
       counter++;
  }
  cout << counter << endl;
}
